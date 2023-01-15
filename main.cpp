#include "sukomain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SukoMain w;
    w.show();
    return a.exec();
}
