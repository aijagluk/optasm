/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_into.h"

GOpcodeINTO::GOpcodeINTO(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeINTO::initUI(void){

    QLabel* plblINTO = new QLabel("<h1><strong>into</strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(plblINTO);    
    phblGeneral->addStretch();

    setLayout(phblGeneral);
}

QString GOpcodeINTO::sourceCode(void){
    QString str;
    str.append("into");

    return(str);
}

void GOpcodeINTO::analyse(void){
    m_nTicks = 4;  // 52 if (OF==1)
    m_nBytes = 1;
}
