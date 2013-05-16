/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_pushf.h"

GOpcodePUSHF::GOpcodePUSHF(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodePUSHF::initUI(void){
    QLabel* plblPUSHF = new QLabel("<h1><strong><center>pushf</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblPUSHF);

    setLayout(phblGeneral);
}

QString GOpcodePUSHF::sourceCode(void){
    QString str;
    str.append("pushf");

    return(str);
}

void GOpcodePUSHF::analyse(void){
    m_nTicks = 10;
    m_nBytes = 1;
}
