#ifndef SQUARECLASS_H
#define SQUARECLASS_H

#include <QObject>
#include <QWidget>

class squareClass
{
public:
    enum ColorStates{Blue, Purple, Pink, None};

    squareClass(QWidget*);
    ColorStates color=None;
    int* value;
    QWidget* QtSquare;
};

#endif // SQUARECLASS_H
