/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_sti.h"
#include <QtWidgets/QTextEdit>

GOpcodeSTI::GOpcodeSTI(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeSTI::initUI(void){
    QLabel* plblSTI = new QLabel("<h1><strong><center>sti</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblSTI);

    QString info_str = "Устанавливает флажок IF в 1.\n"
            "Флажок IF устанавливают в 1 для разрешения восприятия аппаратных прерываний.";
    QTextEdit* info = new QTextEdit();
    info->setText(info_str);
    info->setReadOnly(true);

    QVBoxLayout* pvblGeneral = new QVBoxLayout();
    pvblGeneral->addWidget(info);
    pvblGeneral->addLayout(phblGeneral);

    setLayout(pvblGeneral);
}

QString GOpcodeSTI::sourceCode(void){
    QString str;
    str.append("sti");

    return(str);
}

void GOpcodeSTI::analyse(void){
    m_nTicks = 2;
    m_nBytes = 1;
}
