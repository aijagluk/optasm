/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_cld.h"

GOpcodeCLD::GOpcodeCLD(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeCLD::initUI(void){
    QLabel* plblCLD = new QLabel("<h1><strong><center>cld</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblCLD);

    setLayout(phblGeneral);
}

QString GOpcodeCLD::sourceCode(void){
    QString str;
    str.append("cld");

    return(str);
}

void GOpcodeCLD::analyse(void){
    m_nTicks = 2;
    m_nBytes = 1;
}
