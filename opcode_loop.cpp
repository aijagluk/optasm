/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_loop.h"

GOpcodeLOOP::GOpcodeLOOP(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeLOOP::initUI(void){
    m_pleOp = new QLineEdit();

    m_pleOp->setAlignment(Qt::AlignCenter);

    QLabel* plblLOOP = new QLabel("<h1><strong>loop</strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(plblLOOP);
    phblGeneral->addWidget(m_pleOp);
    phblGeneral->addStretch();

    setLayout(phblGeneral);
}

QString GOpcodeLOOP::sourceCode(void){
    QString str;
    str.append("loop ");
    str.append(m_strOp1);

    return(str);
}

void GOpcodeLOOP::clearSource(void){
    m_pleOp->clear();
}

void GOpcodeLOOP::saveData(void){
    setOp1(m_pleOp->text());
}

void GOpcodeLOOP::analyse(void){
    QRegExp rxpLabel = QRegExp("^\\s*[a-zA-Z_][a-zA-Z_0-9]*\\s*$");

    if(m_strOp1.contains(rxpLabel)){
        m_nTicks = 5; //если прыжок произошел, то 17
        m_nBytes = 2;
    }
    else{
        m_nTicks = 0;
        m_nBytes = 0;
        qDebug() << "m_nTicks = m_nBytes = 0; opcode_loop.cpp; \"analyse\" function\n";
    }
}
