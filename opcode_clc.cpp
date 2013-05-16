/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_clc.h"

GOpcodeCLC::GOpcodeCLC(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeCLC::initUI(void){
    QLabel* plblCLC = new QLabel("<h1><strong><center>clc</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblCLC);

    setLayout(phblGeneral);
}

QString GOpcodeCLC::sourceCode(void){
    QString str;
    str.append("clc");

    return(str);
}

void GOpcodeCLC::analyse(void){
    m_nTicks = 2;
    m_nBytes = 1;
}
