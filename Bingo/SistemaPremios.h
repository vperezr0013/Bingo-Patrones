#ifndef SISTEMAPREMIOS_H
#define SISTEMAPREMIOS_H

#include "Premios.h"

class SistemaPremios
{

private:

    static std::vector<Premio> premiosRegistrados;

    static unsigned int bingoValor;


public:


    /**
     * Gets a string representation of the prizes saved, useful to be serialized or console debug reasons
     * @return
     */
    static std::string toString();


    [[nodiscard]] static bool addPremio(const std::string& code);

    /**
     * Adds a prize to the PrizeSystem
     * @param minRows
     * @param minColumns
     * @param value credits for the prize
     */
    static void addPremio(unsigned int columnas, unsigned int filas, unsigned int valor);


    static void eliminaPremio(unsigned int index);


    /**
     * Given a card and extracted numbers returns the amount of prize
     * @param card
     * @return
     */
    static unsigned int validaCarton(Carton& carton, const std::vector<unsigned int>& extracted);

    /**
     * The bingo is a special bonus, it means when all rows and columns are marked
     * The bingo value CAN be 0
     * @param credits value of the bonus
     */
    static void setBingo(unsigned int credits);


    /**
     * Loads the prizes from Settings.ini
     * @return true on success, false on error
     */
    static bool load();


    static std::vector<Premio>& getPremios();

    static unsigned int getBingoValor();


    [[nodiscard]] static bool guardar();

    static void clear();
};


#endif // SISTEMAPREMIOS_H
