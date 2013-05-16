/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_rep_stos.h"

GOpcodeREP_STOS::GOpcodeREP_STOS(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeREP_STOS::initUI(void){
    QLabel* plblREP_STOS = new QLabel("<h1><strong><center>rep stos</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblREP_STOS);

    setLayout(phblGeneral);
}

QString GOpcodeREP_STOS::sourceCode(void){
    QString str;
    str.append("rep stos");

    return(str);
}

void GOpcodeREP_STOS::analyse(void){
    m_nTicks = 11;
    m_nBytes = 1;
}
