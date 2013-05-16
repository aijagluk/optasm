/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_btr.h"

GOpcodeBTR::GOpcodeBTR(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeBTR::initUI(void){
    m_pleOp1 = new QLineEdit();
    m_pleOp2 = new QLineEdit();

    m_pleOp1->setAlignment(Qt::AlignCenter);
    m_pleOp2->setAlignment(Qt::AlignCenter);

    QLabel* plblBTR = new QLabel("<h1><strong>btr</strong></h1>");
    QLabel* plblComma = new QLabel("<h1><strong>,</strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(plblBTR);
    phblGeneral->addWidget(m_pleOp1);
    phblGeneral->addWidget(plblComma);
    phblGeneral->addWidget(m_pleOp2);
    phblGeneral->addStretch();

    setLayout(phblGeneral);
}

QString GOpcodeBTR::sourceCode(void){
    QString str;
    str.append("btr ");
    str.append(m_strOp1);
    str.append(", ");
    str.append(m_strOp2);

    return(str);
}

void GOpcodeBTR::clearSource(void){
    m_pleOp1->clear();
    m_pleOp2->clear();
}

void GOpcodeBTR::saveData(void){
    setOp1(m_pleOp1->text());
    setOp2(m_pleOp2->text());
}

void GOpcodeBTR::analyse(void){
    //заглушка
    m_nTicks = 0;
    m_nBytes = 0;
}
