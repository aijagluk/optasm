/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_stc.h"
#include <QtWidgets/QTextEdit>

GOpcodeSTC::GOpcodeSTC(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeSTC::initUI(void){
    QLabel* plblSTC = new QLabel("<h1><strong><center>stc</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblSTC);

    QString info_str = "Устанавливает флажок CF в 1.";
    QTextEdit* info = new QTextEdit();
    info->setText(info_str);
    info->setReadOnly(true);

    QVBoxLayout* pvblGeneral = new QVBoxLayout();
    pvblGeneral->addWidget(info);
    pvblGeneral->addLayout(phblGeneral);

    setLayout(pvblGeneral);
}

QString GOpcodeSTC::sourceCode(void){
    QString str;
    str.append("stc");

    return(str);
}

void GOpcodeSTC::analyse(void){
    m_nTicks = 2;
    m_nBytes = 1;
}
