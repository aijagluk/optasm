/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_loopne.h"

GOpcodeLOOPNE::GOpcodeLOOPNE(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeLOOPNE::initUI(void){
    m_pleOp = new QLineEdit();

    m_pleOp->setAlignment(Qt::AlignCenter);

    QLabel* plblLOOPNE = new QLabel("<h1><strong>loopne</strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(plblLOOPNE);
    phblGeneral->addWidget(m_pleOp);
    phblGeneral->addStretch();

    setLayout(phblGeneral);
}

QString GOpcodeLOOPNE::sourceCode(void){
    QString str;
    str.append("loopne ");
    str.append(m_strOp1);

    return(str);
}

void GOpcodeLOOPNE::clearSource(void){
    m_pleOp->clear();
}

void GOpcodeLOOPNE::saveData(void){
    setOp1(m_pleOp->text());
}

void GOpcodeLOOPNE::analyse(void){
    QRegExp rxpLabel = QRegExp("^\\s*[a-zA-Z_][a-zA-Z_0-9]*\\s*$");

    if(m_strOp1.contains(rxpLabel)){
        m_nTicks = 6; //если прыжок произошел, то 18
        m_nBytes = 2;
    }
    else{
        m_nTicks = 0;
        m_nBytes = 0;
        qDebug() << "m_nTicks = m_nBytes = 0; opcode_loopne.cpp; \"analyse\" function\n";
    }
}
