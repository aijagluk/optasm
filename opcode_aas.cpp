/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_aas.h"

GOpcodeAAS::GOpcodeAAS(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeAAS::initUI(void){
    QLabel* plblAAS = new QLabel("<h1><strong><center>aas</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblAAS);

    setLayout(phblGeneral);
}

QString GOpcodeAAS::sourceCode(void){
    QString str;
    str.append("aas");

    return(str);
}

void GOpcodeAAS::analyse(void){
    m_nTicks = 4;
    m_nBytes = 1;
}
