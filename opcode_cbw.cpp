/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_cbw.h"

GOpcodeCBW::GOpcodeCBW(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeCBW::initUI(void){
    QLabel* plblCBW = new QLabel("<h1><strong><center>cbw</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblCBW);

    setLayout(phblGeneral);
}

QString GOpcodeCBW::sourceCode(void){
    QString str;
    str.append("cbw");

    return(str);
}

void GOpcodeCBW::analyse(void){
    m_nTicks = 2;
    m_nBytes = 1;
}
