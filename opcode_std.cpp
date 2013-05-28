/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_std.h"
#include <QtWidgets/QTextEdit>

GOpcodeSTD::GOpcodeSTD(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeSTD::initUI(void){
    QLabel* plblSTD = new QLabel("<h1><strong><center>std</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblSTD);

    QString info_str = "Устанавливает флажок DF в 1.\n"
            "Флажок DF устанавливают в 1 для автодекремента регистров SI и DI в командах обработки строк.";
    QTextEdit* info = new QTextEdit();
    info->setText(info_str);
    info->setReadOnly(true);

    QVBoxLayout* pvblGeneral = new QVBoxLayout();
    pvblGeneral->addWidget(info);
    pvblGeneral->addLayout(phblGeneral);

    setLayout(pvblGeneral);
}

QString GOpcodeSTD::sourceCode(void){
    QString str;
    str.append("std");

    return(str);
}

void GOpcodeSTD::analyse(void){
    m_nTicks = 2;
    m_nBytes = 1;
}
