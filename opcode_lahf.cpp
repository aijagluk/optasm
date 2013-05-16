/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_lahf.h"

GOpcodeLAHF::GOpcodeLAHF(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeLAHF::initUI(void){
    QLabel* plblLAHF = new QLabel("<h1><strong><center>lahf</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblLAHF);

    setLayout(phblGeneral);
}

QString GOpcodeLAHF::sourceCode(void){
    QString str;
    str.append("lahf");

    return(str);
}

void GOpcodeLAHF::analyse(void){
    m_nTicks = 4;
    m_nBytes = 1;
}
