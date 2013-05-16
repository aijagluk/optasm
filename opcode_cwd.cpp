/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_cwd.h"

GOpcodeCWD::GOpcodeCWD(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeCWD::initUI(void){
    QLabel* plblCWD = new QLabel("<h1><strong><center>cwd</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblCWD);

    setLayout(phblGeneral);
}

QString GOpcodeCWD::sourceCode(void){
    QString str;
    str.append("cwd");

    return(str);
}

void GOpcodeCWD::analyse(void){
    m_nTicks = 5;
    m_nBytes = 1;
}
