/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_sahf.h"

GOpcodeSAHF::GOpcodeSAHF(QWidget *parent) :
    QWidget(parent){

    initUI();
}

void GOpcodeSAHF::initUI(void){
    QLabel* plblSAHF = new QLabel("<h1><strong><center>sahf</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblSAHF);

    setLayout(phblGeneral);
}

QString GOpcodeSAHF::sourceCode(void){
    QString str;
    str.append("sahf");

    return(str);
}

void GOpcodeSAHF::analyse(void){
    m_nTicks = 4;
    m_nBytes = 1;
}
