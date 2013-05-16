/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_loopnz.h"

GOpcodeLOOPNZ::GOpcodeLOOPNZ(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeLOOPNZ::initUI(void){
    m_pleOp = new QLineEdit();

    m_pleOp->setAlignment(Qt::AlignCenter);

    QLabel* plblLOOPNZ = new QLabel("<h1><strong>loopnz</strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(plblLOOPNZ);
    phblGeneral->addWidget(m_pleOp);
    phblGeneral->addStretch();

    setLayout(phblGeneral);
}

QString GOpcodeLOOPNZ::sourceCode(void){
    QString str;
    str.append("loopnz ");
    str.append(m_strOp1);

    return(str);
}

void GOpcodeLOOPNZ::clearSource(void){
    m_pleOp->clear();
}

void GOpcodeLOOPNZ::saveData(void){
    setOp1(m_pleOp->text());
}

void GOpcodeLOOPNZ::analyse(void){
    QRegExp rxpLabel = QRegExp("^\\s*[a-zA-Z_][a-zA-Z_0-9]*\\s*$");

    if(m_strOp1.contains(rxpLabel)){
        m_nTicks = 6; //если прыжок произошел, то 18
        m_nBytes = 2;
    }
    else{
        m_nTicks = 0;
        m_nBytes = 0;
        qDebug() << "m_nTicks = m_nBytes = 0; opcode_loopnz.cpp; \"analyse\" function\n";
    }
}
