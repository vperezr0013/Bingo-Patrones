#include "bingo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bingo w;
    w.show();
    return a.exec();
}
