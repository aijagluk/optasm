/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_xlat.h"

GOpcodeXLAT::GOpcodeXLAT(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeXLAT::initUI(void){
    QLabel* plblXLAT = new QLabel("<h1><strong><center>xlat</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblXLAT);

    setLayout(phblGeneral);
}

QString GOpcodeXLAT::sourceCode(void){
    QString str;
    str.append("xlat");

    return(str);
}

void GOpcodeXLAT::analyse(void){
    m_nTicks = 1;
    m_nBytes = 11;
}
