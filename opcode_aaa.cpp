/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_aaa.h"

GOpcodeAAA::GOpcodeAAA(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeAAA::initUI(void){
    QLabel* plblAAA = new QLabel("<h1><strong><center>aaa</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblAAA);

    setLayout(phblGeneral);
}

QString GOpcodeAAA::sourceCode(void){
    QString str;
    str.append("aaa");

    return(str);
}

void GOpcodeAAA::analyse(){
    m_nTicks = 4;
    m_nBytes = 1;
}
