/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_das.h"

GOpcodeDAS::GOpcodeDAS(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeDAS::initUI(void){
    QLabel* plblDAS = new QLabel("<h1><strong><center>das</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblDAS);

    setLayout(phblGeneral);
}

QString GOpcodeDAS::sourceCode(void){
    QString str;
    str.append("das");

    return(str);
}

void GOpcodeDAS::analyse(void){
    m_nTicks = 4;
    m_nBytes = 1;
}
