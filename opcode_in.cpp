/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_in.h"
#include "services_types.h"

GOpcodeIN::GOpcodeIN(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeIN::initUI(void){
    m_pleOp1 = new QLineEdit();
    m_pleOp2 = new QLineEdit();

    m_pleOp1->setAlignment(Qt::AlignCenter);
    m_pleOp2->setAlignment(Qt::AlignCenter);

    QLabel* plblIN = new QLabel("<h1><strong>in</strong></h1>");
    QLabel* plblComma = new QLabel("<h1><strong>,</strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(plblIN);
    phblGeneral->addWidget(m_pleOp1);
    phblGeneral->addWidget(plblComma);
    phblGeneral->addWidget(m_pleOp2);
    phblGeneral->addStretch();

    setLayout(phblGeneral);
}

QString GOpcodeIN::sourceCode(void){
    QString str;
    str.append("in ");
    str.append(m_strOp1);
    str.append(", ");
    str.append(m_strOp2);

    return(str);
}

void GOpcodeIN::clearSource(void){
    m_pleOp1->clear();
    m_pleOp2->clear();
}

void GOpcodeIN::saveData(void){
    setOp1(m_pleOp1->text());
    setOp2(m_pleOp2->text());
}

void GOpcodeIN::analyse(void){
    QRegExp rxpAccumulator = QRegExp("^\\s*(ax|ah|al)\\s*$");
    QRegExp rxpRegisterWithoutAccumulator = QRegExp("^\\s*(bx|bh|bl|cx|ch|cl|dx|dh|dl|si|di|sp|bp)\\s*$");
    QRegExp rxpBaseRegister = QRegExp("^\\s*(ax|ah|al|bx|bh|bl|cx|ch|cl|dx|dh|dl|si|di|sp|bp)\\s*$");
    QRegExp rxpSegmentRegister = QRegExp("^\\s*(cs|ds|ss|es|gs|fs)\\s*$");
    QRegExp rxpSegmentRegisterWithoutCS = QRegExp("^\\s*(ds|ss|es|gs|fs)\\s*$");
    QRegExp rxpConstant = QRegExp("^\\s*\\d+\\s*$");

    QRegExp rxpDX = QRegExp("^\\s*dx\\s*$");

    OperandType oper1;
    OperandType oper2;

    if(m_strOp1.contains(rxpAccumulator)){
        oper1 = ACCUMULATOR;
    }
    else if(m_strOp1.contains(rxpBaseRegister)){
        oper1 = BASE_REGISTER;
    }
    else if(m_strOp1.contains(rxpRegisterWithoutAccumulator)){
        oper1 = BASE_REGISTER_WITHOUT_ACCUMULATOR;
    }
    else if(m_strOp1.contains(rxpSegmentRegisterWithoutCS)){
        oper1 = SEGMENT_REGISTER_WITHOUT_CS;
    }
    else if(m_strOp1.contains(rxpSegmentRegister)){
        oper1 = SEGMENT_REGISTER;
    }
    else if(m_strOp1.contains(rxpConstant)){
        oper1 = CONSTANT_VALUE;
    }
    else{
        oper1 = MEMORY;
    }

    if(m_strOp2.contains(rxpAccumulator)){
        oper2 = ACCUMULATOR;
    }
    else if(m_strOp2.contains(rxpBaseRegister)){
        oper2 = BASE_REGISTER;
    }
    else if(m_strOp2.contains(rxpRegisterWithoutAccumulator)){
        oper2 = BASE_REGISTER_WITHOUT_ACCUMULATOR;
    }
    else if(m_strOp2.contains(rxpSegmentRegisterWithoutCS)){
        oper2 = SEGMENT_REGISTER_WITHOUT_CS;
    }
    else if(m_strOp2.contains(rxpSegmentRegister)){
        oper2 = SEGMENT_REGISTER;
    }
    else if(m_strOp2.contains(rxpConstant)){
        oper2 = CONSTANT_VALUE;
    }
    else{
        oper2 = MEMORY;
    }

    if(oper1 == ACCUMULATOR && oper2 == CONSTANT_VALUE){
        m_nTicks = 10;
        m_nBytes = 2;
    }
    else if(oper1 == ACCUMULATOR && oper2 == BASE_REGISTER){
        m_nTicks = 8;

        if(m_strOp2.contains(rxpDX)){
            m_nBytes = 1;
        }
        else{
            m_nBytes = 0;
            qDebug() << "Error: opcode_in.cpp \"analyse\" function";
        }
    }
    else{
        qDebug() << "command is not recognize!\n";
    }

}
