#ifndef SUKOMAIN_H
#define SUKOMAIN_H

#include <QMainWindow>
#include <vector>
#include "squareclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SukoMain; }
QT_END_NAMESPACE

class SukoMain : public QMainWindow
{
    Q_OBJECT

public:
    SukoMain(QWidget *parent = nullptr);
    ~SukoMain();


    squareClass *topLeft, *topCenter, *topRight, *middleLeft, *middleCenter, *middleRight, *bottomLeft, *bottomCenter, *bottomRight; //grid values

    int q1Val, q2Val, q3Val, q4Val; //desired values
    int blueVal, pinkVal, purpleVal; //desired values

    int q1Sum, q2Sum, q3Sum, q4Sum; //temp values for checks
    int blueSum, pinkSum, purpleSum; //temp values for checks

    int myints[10];

    std::vector<squareClass*> blueSquares;
    std::vector<squareClass*> purpleSquares;
    std::vector<squareClass*> pinkSquares;


    void CycleColor(squareClass*);

    void setGrid(std::vector<int>);

    bool checkq1();
    bool checkq2();
    bool checkq3();
    bool checkq4();

    bool checkBlue();
    bool checkPink();
    bool checkPurple();

    bool checkUnique();

    bool checkAllRules();

    bool checkValidNum(int);

    void createPermutations(int[],int[],int);

    void solve();

private slots:

//    void on_purpleButton_clicked();


    void on_TopLeftButton_clicked();

    void on_TopCenterButton_clicked();

    void on_TopRightButton_clicked();

    void on_MiddleLeftButton_clicked();

    void on_MiddleCenterButton_clicked();

    void on_MiddleRightButton_clicked();

    void on_BottomLeftButton_clicked();

    void on_BottomCenterButton_clicked();

    void on_BottomRightButton_clicked();

    void on_Quadrant2_textEdited(const QString &arg1);

    void on_Quadrant1_textEdited(const QString &arg1);

    void on_Quadrant3_textEdited(const QString &arg1);

    void on_Quadrant4_textEdited(const QString &arg1);

    void on_purpleLineEdit_textEdited(const QString &arg1);

    void on_blueLineEdit_textEdited(const QString &arg1);

    void on_pinkLineEdit_textEdited(const QString &arg1);


    void on_BottomRightButton_2_clicked();

private:
    Ui::SukoMain *ui;
};
#endif // SUKOMAIN_H
