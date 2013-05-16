/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_daa.h"

GOpcodeDAA::GOpcodeDAA(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeDAA::initUI(void){
    QLabel* plblDAA = new QLabel("<h1><strong><center>daa</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblDAA);

    setLayout(phblGeneral);
}

QString GOpcodeDAA::sourceCode(void){
    QString str;
    str.append("daa");

    return(str);
}

void GOpcodeDAA::analyse(void){
    m_nTicks = 4;
    m_nBytes = 1;
}
