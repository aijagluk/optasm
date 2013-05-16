/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_nop.h"

GOpcodeNOP::GOpcodeNOP(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeNOP::initUI(void){
    QLabel* plblNOP = new QLabel("<h1><strong><center>nop</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblNOP);

    setLayout(phblGeneral);
}

QString GOpcodeNOP::sourceCode(void){
    QString str;
    str.append("nop");

    return(str);
}

void GOpcodeNOP::analyse(void){
    m_nTicks = 3;
    m_nBytes = 1;
}
