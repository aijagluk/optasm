/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_lock.h"

GOpcodeLOCK::GOpcodeLOCK(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeLOCK::initUI(void){
    QLabel* plblLOCK = new QLabel("<h1><strong><center>lock</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblLOCK);

    setLayout(phblGeneral);
}

QString GOpcodeLOCK::sourceCode(void){
    QString str;
    str.append("lock");

    return(str);
}

void GOpcodeLOCK::analyse(void){
    m_nTicks = 2;
    m_nBytes = 1;
}
