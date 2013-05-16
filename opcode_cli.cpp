/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_cli.h"

GOpcodeCLI::GOpcodeCLI(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeCLI::initUI(void){
    QLabel* plblCLI = new QLabel("<h1><strong><center>cli</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblCLI);

    setLayout(phblGeneral);
}

QString GOpcodeCLI::sourceCode(void){
    QString str;
    str.append("cli");

    return(str);
}

void GOpcodeCLI::analyse(void){
    m_nTicks = 2;
    m_nBytes = 1;
}
