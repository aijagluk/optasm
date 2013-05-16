/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_wait.h"

GOpcodeWAIT::GOpcodeWAIT(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeWAIT::initUI(void){
    QLabel* plblWAIT = new QLabel("<h1><strong><center>wait</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblWAIT);

    setLayout(phblGeneral);
}

QString GOpcodeWAIT::sourceCode(void){
    QString str;
    str.append("wait");

    return(str);
}

void GOpcodeWAIT::analyse(void){
    m_nTicks = 3; // и больше
    m_nBytes = 1;
}
