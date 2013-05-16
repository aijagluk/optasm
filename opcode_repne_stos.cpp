/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_repne_stos.h"

GOpcodeREPNE_STOS::GOpcodeREPNE_STOS(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeREPNE_STOS::initUI(void){
    QLabel* plblREPNE_STOS = new QLabel("<h1><strong><center>repne stos</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblREPNE_STOS);

    setLayout(phblGeneral);
}

QString GOpcodeREPNE_STOS::sourceCode(void){
    QString str;
    str.append("repne stos");

    return(str);
}

void GOpcodeREPNE_STOS::analyse(void){
    m_nTicks = 11;
    m_nBytes = 1;
}
