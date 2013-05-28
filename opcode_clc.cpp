/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_clc.h"
#include <QtWidgets/QTextEdit>

GOpcodeCLC::GOpcodeCLC(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeCLC::initUI(void){
    QLabel* plblCLC = new QLabel("<h1><strong><center>clc</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblCLC);

    QString info_str = "Сбросывает флажок СF в 0.";
    QTextEdit* info = new QTextEdit();
    info->setText(info_str);
    info->setReadOnly(true);

    QVBoxLayout* pvblGeneral = new QVBoxLayout();
    pvblGeneral->addWidget(info);
    pvblGeneral->addLayout(phblGeneral);

    setLayout(pvblGeneral);
}

QString GOpcodeCLC::sourceCode(void){
    QString str;
    str.append("clc");

    return(str);
}

void GOpcodeCLC::analyse(void){
    m_nTicks = 2;
    m_nBytes = 1;
}
