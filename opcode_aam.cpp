/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_aam.h"

GOpcodeAAM::GOpcodeAAM(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeAAM::initUI(void){
    QLabel* plblAAM = new QLabel("<h1><strong><center>aam</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblAAM);

    setLayout(phblGeneral);
}

QString GOpcodeAAM::sourceCode(void){
    QString str;
    str.append("aam");

    return(str);
}

void GOpcodeAAM::analyse(void){
    m_nTicks = 83;
    m_nBytes = 2;
}
