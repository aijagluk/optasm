/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_std.h"

GOpcodeSTD::GOpcodeSTD(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeSTD::initUI(void){
    QLabel* plblSTD = new QLabel("<h1><strong><center>std</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblSTD);

    setLayout(phblGeneral);
}

QString GOpcodeSTD::sourceCode(void){
    QString str;
    str.append("std");

    return(str);
}

void GOpcodeSTD::analyse(void){
    m_nTicks = 2;
    m_nBytes = 1;
}
