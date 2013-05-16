/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_hlt.h"

GOpcodeHLT::GOpcodeHLT(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeHLT::initUI(void){
    QLabel* plblHLT = new QLabel("<h1><strong><center>hlt</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblHLT);

    setLayout(phblGeneral);
}

QString GOpcodeHLT::sourceCode(void){
    QString str;
    str.append("hlt");

    return(str);
}

void GOpcodeHLT::analyse(void){
    m_nTicks = 2; //и больше
    m_nBytes = 1;
}
