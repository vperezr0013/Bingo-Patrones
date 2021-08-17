#include <algorithm>

#include <Settings.hpp>
#include "SistemaPremios.h"

std::vector<Premio> SistemaPremios::premiosRegistrados;
unsigned int SistemaPremios::bingoValue;

unsigned int SistemaPremios::checkCard(Carton& carton, const std::vector<unsigned int>& extracted)
{



    // Create lookup table for O(1) check if a number was extracted
    unsigned int maxNExtracted = *std::max_element(std::begin(extracted), std::end(extracted));
    unsigned int maxNCard = *std::max_element(std::begin(carton.numeros), std::end(carton.numeros));
    std::vector<unsigned int> lookup(std::max(maxNExtracted, maxNCard) + 1);
    for (unsigned int j : extracted)
        lookup[j] = 1;


    // First check special case of Bingo
    if (bingoValor != 0)
    {
        bool bingo = true;
        for (size_t i = 0; i < card.WIDTH * card.HEIGHT; i++)
        {
            if (lookup[card[i]] == 0)
            {
                bingo = false;
                break;
            }
        }
        if (bingo)
            return bingoValor;
    }


    // TODO: fix this ugly code
    for (Premio& p : premiosRegistrados)
    {
        unsigned int rowsMatched = 0;
        if (p.Filas != 0)
        {
            for (size_t row = 0; row < carton.HEIGHT; row++)
            {
                bool rowMatch = true;
                for (size_t column = 0; column < carton.WIDTH; column++)
                {
                    size_t index = row * card.WIDTH + column;

                    unsigned int cartonNumero = carton[index];
                    if (lookup[cartonNumero] == 0)
                    {
                        rowMatch = false;
                        break;
                    }
                }
                if (rowMatch)
                {
                    rowsMatched++;
                }
            }
        }


        unsigned int columnsMatched = 0;
        if (p.Columnas != 0)
        {
            for (size_t column = 0; column < carton.WIDTH; column++)
            {
                bool columnMatch = true;
                for (size_t row = 0; row < carton.HEIGHT; row++)
                {
                    size_t index = row * carton.WIDTH + column;

                    unsigned int cardNumber = carton[index];
                    if (lookup[cardNumber] == 0)
                    {
                        columnMatch = false;
                        break;
                    }
                }
                if (columnMatch)
                {
                    columnsMatched++;
                }
            }

        }


        if (rowsMatched >= p.Filas && columnsMatched >= p.Columnas)
            return p.Valor * rowsMatched + p.Valor * columnsMatched;

    }

    return 0;
}

std::string SistemaPremios::toString()
{
    std::stringstream ss;
    for (Premio p: premiosRegistrados)
    {
        ss << p.toString() << ",";
    }
    if (bingoValor)
        ss << "B" << bingoValor;
    return ss.str();
}

void SistemaPremios::setBingo(unsigned int credits)
{
    bingoValor = credits;
}

struct custom_prizes_sort
{
    inline bool operator()(const Premio& struct1, const Premio& struct2)
    {
        // FIXME: should prizes be sorted by area or by value?
        //return (struct1.MINIMUM_COLUMNS * struct1.MINIMUM_ROWS > struct2.MINIMUM_COLUMNS * struct2.MINIMUM_ROWS);
        return struct1.Valor > struct2.Valor;
    }
};


bool parsePremios(const std::string& premioString, Premio& out)
{
    const std::string::size_type posC = premioString.find('C');
    const std::string creditsString = premioString.substr(posC + 1);
    for (char s : creditsString)
        if (!isdigit(s))
            return false;

    const std::string::size_type posV = premioString.find('V');
    const std::string columnsString = premioString.substr(posV + 1, posC - posV - 1);
    for (char s : columnsString)
        if (!isdigit(s))
            return false;

    const std::string::size_type posH = prizeString.find('H');

    if (posH != 0)
        return false;

    const std::string rowsString = prizeString.substr(1, posV - 1);
    for (char s : rowsString)
        if (!isdigit(s))
            return false;


    unsigned int prizeValue;
    unsigned int prizeRows;
    unsigned int prizeColumns;

    std::stringstream css(creditsString);
    css >> prizeValue;
    std::stringstream vss(columnsString);
    vss >> prizeColumns;
    std::stringstream hss(rowsString);
    hss >> prizeRows;

    if (prizeValue == 0)
        return false;

    if (prizeRows == 0 && prizeColumns == 0)
        return false;

    out = Prize(prizeRows, prizeColumns, prizeValue);

    return true;
}

bool PrizeSystem::load()
{

    std::string prizesString;
    try
    {
        prizesString = Settings::get<std::string>("prizes");
    }
    catch (std::invalid_argument& e)
    {
        return false;
    }


    //FIXME: ugly code ahead, maybe use JSON for settings next time?
    std::replace(prizesString.begin(), prizesString.end(), ',', ' ');  // replace ',' by ' '

    std::vector<std::string> array;
    std::stringstream ss(prizesString);
    std::string temp;
    while (ss >> temp)
        array.push_back(temp);

    for (const std::string& prizeString : array)
        if (!addPrize(prizeString))
            return false;

    std::sort(prizesRegistered.begin(), prizesRegistered.end(), custom_prizes_sort());
    return true;
}

std::vector<Prize>& PrizeSystem::getPrizes()
{
    return prizesRegistered;
}

unsigned int PrizeSystem::getBingoValue()
{
    return bingoValue;
}

bool PrizeSystem::save()
{
    Settings::set("prizes", toString());
    return Settings::save();
}

void PrizeSystem::removePrize(unsigned int index)
{
    prizesRegistered.erase(prizesRegistered.begin() + index);

    //FIXME: is sort really needed with erase?
    std::sort(prizesRegistered.begin(), prizesRegistered.end(), custom_prizes_sort());
}

bool PrizeSystem::addPrize(const std::string& prizeString)
{
    // error another same code

    for (Prize& p : prizesRegistered)
    {
        if (p.toString() == prizeString)
            return false;
    }

    if (prizeString.length() == 0)
        return false;

    switch (prizeString[0])
    {
        case 'B':
        {
            std::stringstream ssbingo(prizeString.substr(1));
            auto ss = ssbingo.str();
            for (char s : ss)
                if (!isdigit(s))
                    return false;
            ssbingo >> bingoValue;
            break;
        }
        case 'H':
        {
            Prize p;
            if (!parsePrize(prizeString, p))
                return false;
            else
            {
                prizesRegistered.emplace_back(p);
                std::sort(prizesRegistered.begin(), prizesRegistered.end(), custom_prizes_sort());

            }

            break;
        }
        default:
            //FIXME: exceptions instead of return false?
            return false;
    }


    return true;
}


void PrizeSystem::addPrize(unsigned int minRows, unsigned int minColumns, unsigned int value)
{


    prizesRegistered.emplace_back(minRows, minColumns, value);


    std::sort(prizesRegistered.begin(), prizesRegistered.end(), custom_prizes_sort());
}

void PrizeSystem::clear()
{
    prizesRegistered.clear();
    bingoValue = 0;
}
