/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_esc.h"

GOpcodeESC::GOpcodeESC(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeESC::initUI(void){
    QLabel* plblESC = new QLabel("<h1><strong><center>esc</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblESC);

    setLayout(phblGeneral);
}

QString GOpcodeESC::sourceCode(void){
    QString str;
    str.append("esc");

    return(str);
}

void GOpcodeESC::analyse(void){
    m_nTicks = 8; // plus EA ;)
    m_nBytes = 4;
}
