/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_sti.h"

GOpcodeSTI::GOpcodeSTI(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeSTI::initUI(void){
    QLabel* plblSTI = new QLabel("<h1><strong><center>sti</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblSTI);

    setLayout(phblGeneral);
}

QString GOpcodeSTI::sourceCode(void){
    QString str;
    str.append("sti");

    return(str);
}

void GOpcodeSTI::analyse(void){
    m_nTicks = 2;
    m_nBytes = 1;
}
