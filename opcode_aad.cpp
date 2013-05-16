/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_aad.h"

GOpcodeAAD::GOpcodeAAD(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeAAD::initUI(void){
    QLabel* plblAAD = new QLabel("<h1><strong><center>aad</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblAAD);

    setLayout(phblGeneral);
}

QString GOpcodeAAD::sourceCode(void){
    QString str;
    str.append("aad");

    return(str);
}

void GOpcodeAAD::analyse(void){
    m_nTicks = 60;
    m_nBytes = 2;
}
