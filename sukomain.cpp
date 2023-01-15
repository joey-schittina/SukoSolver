#include "sukomain.h"
#include "./ui_sukomain.h"
#include "squareclass.h"
//#include "qrect.h"
//#include "QRegion"
#include <QDebug>
#include <vector>
#include <chrono>

SukoMain::SukoMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SukoMain)
{
    ui->setupUi(this);

    topLeft=new squareClass(ui->TopLeftButton);
    topCenter= new squareClass(ui->TopCenterButton);
    topRight= new squareClass(ui->TopRightButton);
    middleLeft= new squareClass(ui->MiddleLeftButton);
    middleCenter= new squareClass(ui->MiddleCenterButton);
    middleRight= new squareClass(ui->MiddleRightButton);
    bottomLeft= new squareClass(ui->BottomLeftButton);
    bottomCenter= new squareClass(ui->BottomCenterButton);
    bottomRight= new  squareClass(ui->BottomRightButton);
}


SukoMain::~SukoMain()
{
    delete ui;
}

void SukoMain::setGrid(std::vector<int> ints){
    auto i=ints.begin();
    *topLeft->value=*i++;
    *topCenter->value=*i++;
    *topRight->value=*i++;
    *middleLeft->value=*i++;
    *middleCenter->value=*i++;
    *middleRight->value=*i++;
    *bottomLeft->value=*i++;
    *bottomCenter->value=*i++;
    *bottomRight->value=*i++;
}

void SukoMain::solve(){
    std::vector<int> ints = std::vector<int>({1,2,3,4,5,6,7,8,9});
    do{
        setGrid(ints);
        if(checkAllRules()){
            ui->TopLeftButton->setText(QString::number(*topLeft->value));
            ui->TopCenterButton->setText(QString::number(*topCenter->value));
            ui->TopRightButton->setText(QString::number(*topRight->value));
            ui->MiddleLeftButton->setText(QString::number(*middleLeft->value));
            ui->MiddleCenterButton->setText(QString::number(*middleCenter->value));
            ui->MiddleRightButton->setText(QString::number(*middleRight->value));
            ui->BottomLeftButton->setText(QString::number(*bottomLeft->value));
            ui->BottomCenterButton->setText(QString::number(*bottomCenter->value));
            ui->BottomRightButton->setText(QString::number(*bottomRight->value));
            break;
        }
    }while(next_permutation(ints.begin(),ints.end()));
}

bool SukoMain::checkValidNum(int num){
    if (num<10 && num>=0){
        return true;
    }
    return false;
}

bool SukoMain::checkUnique(){
    if(*topLeft->value!=*topCenter->value!=*topRight->value!=*middleLeft->value!=*middleCenter->value!=\
            *middleRight->value!=*bottomLeft->value!=*bottomCenter->value!=*bottomRight->value){
        return true;
    }
    return false;
}

bool SukoMain::checkAllRules(){
    return (checkBlue()&&checkPink()&&checkPurple()&&checkq1()&&checkq2()&&checkq3()&&checkq4());
}

void SukoMain::CycleColor(squareClass *square){
    if(square->color==squareClass::Blue){
        for(auto i=blueSquares.begin();i<blueSquares.end();i++){
            if((*i)->value==square->value){
                blueSquares.erase(i);
            }
        }
        square->color=squareClass::Pink;
        pinkSquares.push_back(square);
        square->QtSquare->setStyleSheet("background-color: rgb(199, 127, 255);");
    }else if(square->color==squareClass::Pink){
        for(auto i=pinkSquares.begin();i<pinkSquares.end();i++){
            if((*i)->value==square->value){
                pinkSquares.erase(i);
            }
        }
        square->color=squareClass::Purple;
        purpleSquares.push_back(square);
        square->QtSquare->setStyleSheet("background-color: #885dff;");
    }else{
        for(auto i=purpleSquares.begin();i<purpleSquares.end();i++){
            if((*i)->value==square->value){
                purpleSquares.erase(i);
            }
        }
        square->color=squareClass::Blue;
        blueSquares.push_back(square);
        square->QtSquare->setStyleSheet("background-color:rgb(96, 175, 255);");
    }
}


//void SukoMain::on_purpleButton_clicked()
//{
//    ui->purpleButton->hide();
//    ui->purpleLineEdit->show();
//    ui->purpleLineEdit.select
//}

bool SukoMain::checkBlue(){
    blueSum=0;
    for(auto i=blueSquares.begin();i<blueSquares.end();i++){
        blueSum+=*(*i)->value;
    }
    return blueSum==blueVal;
}

bool SukoMain::checkPink(){
    pinkSum=0;
    for(auto i=pinkSquares.begin();i<pinkSquares.end();i++){
        pinkSum+=*(*i)->value;
    }
    return pinkSum==pinkVal;
}

bool SukoMain::checkPurple(){
    purpleSum=0;
    for(auto i=purpleSquares.begin();i<purpleSquares.end();i++){
        purpleSum+=*(*i)->value;
    }
    return purpleSum==purpleVal;
}

bool SukoMain::checkq1(){
    q1Sum=*topRight->value + *topCenter->value + *middleRight->value + * middleCenter->value;
    return q1Sum==q1Val;
}

bool SukoMain::checkq2(){
    q2Sum=*topLeft->value + *topCenter->value + *middleLeft->value + * middleCenter->value;
    return q2Sum==q2Val;
}

bool SukoMain::checkq3(){
    q3Sum=*middleLeft->value + *middleCenter->value + *bottomLeft->value + * bottomCenter->value;
    return q3Sum==q3Val;
}

bool SukoMain::checkq4(){
    q4Sum=*middleCenter->value + *middleRight->value + *bottomCenter->value + * bottomRight->value;
    return q4Sum==q4Val;
}


void SukoMain::on_TopLeftButton_clicked()
{
    CycleColor(topLeft);
}


void SukoMain::on_TopCenterButton_clicked()
{
    CycleColor(topCenter);
}


void SukoMain::on_TopRightButton_clicked()
{
    CycleColor(topRight);
}


void SukoMain::on_MiddleLeftButton_clicked()
{
    CycleColor(middleLeft);
}


void SukoMain::on_MiddleCenterButton_clicked()
{
    CycleColor(middleCenter);
}


void SukoMain::on_MiddleRightButton_clicked()
{
    CycleColor(middleRight);
}


void SukoMain::on_BottomLeftButton_clicked()
{
    CycleColor(bottomLeft);
}


void SukoMain::on_BottomCenterButton_clicked()
{
    CycleColor(bottomCenter);
}


void SukoMain::on_BottomRightButton_clicked()
{
    CycleColor(bottomRight);
}


void SukoMain::on_Quadrant2_textEdited(const QString &arg1)
{
    q2Val=ui->Quadrant2->text().toInt();


//    if(checkValidNum(num)){
//        q4Val=num;
//        ui->Quadrant2->setStyleSheet("color:white;\n"
//                                     "border-radius: 10px;\n"
//                                     "border: 2px solid rgb(183, 183, 183);\n"
//                                     "background-color:rgb(152, 152, 152);");
//    }else{
//        ui->Quadrant2->setStyleSheet("color:red;\n"
//                                     "border-radius: 10px;\n"
//                                     "border: 2px solid rgb(183, 183, 183);\n"
//                                     "background-color:rgb(152, 152, 152);");
//    }
}


void SukoMain::on_Quadrant1_textEdited(const QString &arg1)
{
    q1Val=ui->Quadrant1->text().toInt();
//    if(checkValidNum(num)){
//        q4Val=num;
//        ui->Quadrant1->setStyleSheet("color:white;\n"
//                                     "border-radius: 10px;\n"
//                                     "border: 2px solid rgb(183, 183, 183);\n"
//                                     "background-color:rgb(152, 152, 152);");
//    }else{
//        ui->Quadrant1->setStyleSheet("color:red;\n"
//                                     "border-radius: 10px;\n"
//                                     "border: 2px solid rgb(183, 183, 183);\n"
//                                     "background-color:rgb(152, 152, 152);");
//    }
}



void SukoMain::on_Quadrant3_textEdited(const QString &arg1)
{
    q3Val=ui->Quadrant3->text().toInt();
//    if(checkValidNum(num)){
//        q4Val=num;
//        ui->Quadrant3->setStyleSheet("color:white;\n"
//                                     "border-radius: 10px;\n"
//                                     "border: 2px solid rgb(183, 183, 183);\n"
//                                     "background-color:rgb(152, 152, 152);");
//    }else{
//        ui->Quadrant3->setStyleSheet("color:red;\n"
//                                     "border-radius: 10px;\n"
//                                     "border: 2px solid rgb(183, 183, 183);\n"
//                                     "background-color:rgb(152, 152, 152);");
//    }
}


void SukoMain::on_Quadrant4_textEdited(const QString &arg1)
{
    q4Val=ui->Quadrant4->text().toInt();
//    if(checkValidNum(num)){
//        q4Val=num;
//        ui->Quadrant4->setStyleSheet("color:white;\n"
//                                     "border-radius: 10px;\n"
//                                     "border: 2px solid rgb(183, 183, 183);\n"
//                                     "background-color:rgb(152, 152, 152);");
//    }else{
//        ui->Quadrant4->setStyleSheet("color:red;\n"
//                                     "border-radius: 10px;\n"
//                                     "border: 2px solid rgb(183, 183, 183);\n"
//                                     "background-color:rgb(152, 152, 152);");
//    }
}


void SukoMain::on_purpleLineEdit_textEdited(const QString &arg1)
{
    purpleVal=ui->purpleLineEdit->text().toInt();
}


void SukoMain::on_blueLineEdit_textEdited(const QString &arg1)
{
    blueVal=ui->blueLineEdit->text().toInt();
}


void SukoMain::on_pinkLineEdit_textEdited(const QString &arg1)
{
    pinkVal=ui->pinkLineEdit->text().toInt();
}



void SukoMain::on_BottomRightButton_2_clicked()
{
    clock_t start = clock();
    solve();
    qDebug()<<(clock()-start)/CLOCKS_PER_SEC;
}

