/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_jnp.h"

GOpcodeJNP::GOpcodeJNP(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeJNP::initUI(void){
    m_pleOp = new QLineEdit();

    m_pleOp->setAlignment(Qt::AlignCenter);

    QLabel* plblJNP = new QLabel("<h1><strong>jnp</strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(plblJNP);
    phblGeneral->addWidget(m_pleOp);
    phblGeneral->addStretch();

    setLayout(phblGeneral);
}

QString GOpcodeJNP::sourceCode(void){
    QString str;
    str.append("jnp ");
    str.append(m_strOp1);

    return(str);
}

void GOpcodeJNP::clearSource(void){
    m_pleOp->clear();
}

void GOpcodeJNP::saveData(void){
    setOp1(m_pleOp->text());
}

void GOpcodeJNP::analyse(void){
    QRegExp rxpLabel = QRegExp("^\\s*[a-zA-Z_][a-zA-Z_0-9]*\\s*$");

    if(m_strOp1.contains(rxpLabel)){
        m_nTicks = 4; //если прыжок произошел, то 16
        m_nBytes = 2;
    }
    else{
        m_nTicks = 0;
        m_nBytes = 0;
        qDebug() << "m_nTicks = m_nBytes = 0; opcode_jnp.cpp; \"analyse\" function\n";
    }
}
