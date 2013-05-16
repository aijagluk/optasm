/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_popf.h"

GOpcodePOPF::GOpcodePOPF(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodePOPF::initUI(void){
    QLabel* plblPOPF = new QLabel("<h1><strong><center>popf</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblPOPF);

    setLayout(phblGeneral);
}

QString GOpcodePOPF::sourceCode(void){
    QString str;
    str.append("popf");

    return(str);
}

void GOpcodePOPF::analyse(void){
    m_nTicks = 8;
    m_nBytes = 1;
}
