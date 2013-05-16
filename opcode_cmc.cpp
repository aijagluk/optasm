/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_cmc.h"

GOpcodeCMC::GOpcodeCMC(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeCMC::initUI(void){
    QLabel* plblCMC = new QLabel("<h1><strong><center>cmc</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblCMC);

    setLayout(phblGeneral);
}

QString GOpcodeCMC::sourceCode(void){
    QString str;
    str.append("cmc");

    return(str);
}

void GOpcodeCMC::analyse(void){
    m_nTicks = 2;
    m_nBytes = 1;
}
