/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_rep_movs.h"
#include "services_types.h"

GOpcodeREP_MOVS::GOpcodeREP_MOVS(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeREP_MOVS::initUI(void){
    m_pleOp1 = new QLineEdit();
    m_pleOp2 = new QLineEdit();

    m_pleOp1->setAlignment(Qt::AlignCenter);
    m_pleOp2->setAlignment(Qt::AlignCenter);

    QLabel* plblREP_MOVS = new QLabel("<h1><strong>rep movs</strong></h1>");
    QLabel* plblComma = new QLabel("<h1><strong>,</strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(plblREP_MOVS);
    phblGeneral->addWidget(m_pleOp1);
    phblGeneral->addWidget(plblComma);
    phblGeneral->addWidget(m_pleOp2);
    phblGeneral->addStretch();

    setLayout(phblGeneral);
}

QString GOpcodeREP_MOVS::sourceCode(void){
    QString str;
    str.append("rep movs ");
    str.append(m_strOp1);
    str.append(", ");
    str.append(m_strOp2);

    return(str);
}

void GOpcodeREP_MOVS::clearSource(void){
    m_pleOp1->clear();
    m_pleOp2->clear();
}

void GOpcodeREP_MOVS::saveData(void){
    setOp1(m_pleOp1->text());
    setOp2(m_pleOp2->text());
}

//int GOpcodeREP_MOVS::calcEA(QString str)
//{
//}

void GOpcodeREP_MOVS::analyse(void){

    QRegExp rxpAccumulator = QRegExp("^\\s*(ax|ah|al)\\s*$");
    QRegExp rxpRegisterWithoutAccumulator = QRegExp("^\\s*(bx|bh|bl|cx|ch|cl|dx|dh|dl|si|di|sp|bp)\\s*$");
    QRegExp rxpBaseRegister = QRegExp("^\\s*(ax|ah|al|bx|bh|bl|cx|ch|cl|dx|dh|dl|si|di|sp|bp)\\s*$");
    QRegExp rxpSegmentRegister = QRegExp("^\\s*(cs|ds|ss|es|gs|fs)\\s*$");
    QRegExp rxpSegmentRegisterWithoutCS = QRegExp("^\\s*(ds|ss|es|gs|fs)\\s*$");
    QRegExp rxpConstant = QRegExp("^\\s*\\d+\\s*$");

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

    //int EA_ticks = 0;

    if((oper1 == MEMORY && oper2 == MEMORY)){
        m_nTicks = 18;
        m_nBytes = 1;

    }
    else{
        qDebug() << "command is not recognize!\n";
    }
}
