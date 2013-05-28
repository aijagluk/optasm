/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_cld.h"
#include <QtWidgets/QTextEdit>

GOpcodeCLD::GOpcodeCLD(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeCLD::initUI(void){
    QLabel* plblCLD = new QLabel("<h1><strong><center>cld</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblCLD);

    QString info_str = "Сбрасывает флажок DF в 0.\n"
            "Флажок DF устанавливают в 0 для автоинкремента регистров SI и DI в командах обработки строк.";
    QTextEdit* info = new QTextEdit();
    info->setText(info_str);
    info->setReadOnly(true);

    QVBoxLayout* pvblGeneral = new QVBoxLayout();
    pvblGeneral->addWidget(info);
    pvblGeneral->addLayout(phblGeneral);

    setLayout(pvblGeneral);
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
