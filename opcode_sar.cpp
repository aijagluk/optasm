/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_sar.h"
#include "services_types.h"

GOpcodeSAR::GOpcodeSAR(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeSAR::initUI(void){
    m_pleOp1 = new QLineEdit();
    m_pleOp2 = new QLineEdit();

    m_pleOp1->setAlignment(Qt::AlignCenter);
    m_pleOp2->setAlignment(Qt::AlignCenter);

    QLabel* plblSAR = new QLabel("<h1><strong>sar</strong></h1>");
    QLabel* plblComma = new QLabel("<h1><strong>,</strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(plblSAR);
    phblGeneral->addWidget(m_pleOp1);
    phblGeneral->addWidget(plblComma);
    phblGeneral->addWidget(m_pleOp2);
    phblGeneral->addStretch();

    setLayout(phblGeneral);
}

QString GOpcodeSAR::sourceCode(void){
    QString str;
    str.append("sar ");
    str.append(m_strOp1);
    str.append(", ");
    str.append(m_strOp2);

    return(str);
}

void GOpcodeSAR::clearSource(void){
    m_pleOp1->clear();
    m_pleOp2->clear();
}

void GOpcodeSAR::saveData(void){
    setOp1(m_pleOp1->text());
    setOp2(m_pleOp2->text());
}

int GOpcodeSAR::calcEA(QString str){

    QRegExp rxpTicks12 = QRegExp("^(\\s*(byte|word)?\\s*\\[\\s*bp\\s*\\+\\s*si\\s*\\+\\s*\\w+\\s*\\]|\\[\\s*bx\\s*\\+\\s*di\\s*\\+\\s*\\w+\\s*\\])$");
    QRegExp rxpTicks11 = QRegExp("^(\\s*(byte|word)?\\s*\\[\\s*bp\\s*\\+\\s*di\\s*\\+\\s*\\w+\\s*\\]|\\[\\s*bx\\s*\\+\\s*si\\s*\\+\\s*\\w+\\s*\\])$");
    QRegExp rxpTicks8 = QRegExp("^(\\s*(byte|word)?\\s*\\[\\s*bp\\s*\\+\\s*si\\s*\\]|\\[\\s*bx\\s*\\+\\s*di\\s*\\])$");
    QRegExp rxpTicks7 = QRegExp("^(\\s*(byte|word)?\\s*\\[\\s*bp\\s*\\+\\s*di\\s*\\]|\\[\\s*bx\\s*\\+\\s*si\\s*\\])$");
    QRegExp rxpTicks9 = QRegExp("^(\\s*(byte|word)?\\s*\\[\\s*(bx|bp|si|di)\s*\\+\\s*\\w+\\s*\\])$");
    QRegExp rxpTicks5 = QRegExp("^(\\s*(byte|word)?\\s*\\[\\s*(bx|bp|si|di)\\s*\\])$");
    QRegExp rxpTicks6 = QRegExp("^(\\s*(byte|word)?\\s*\\w+)$");

    if(str.contains(rxpTicks12)){
        return(12);
    }
    else if(str.contains(rxpTicks11)){
        return(11);
    }
    else if(str.contains(rxpTicks8)){
        return(8);
    }
    else if(str.contains(rxpTicks7)){
        return(7);
    }
    else if(str.contains(rxpTicks9)){
        return(9);
    }
    else if(str.contains(rxpTicks5)){
        return(5);
    }
    else if(str.contains(rxpTicks6)){
        return(6);
    }
    else{
        return(0); //error signal
    }
}

void GOpcodeSAR::analyse(void){

    QRegExp rxpAccumulator = QRegExp("^\\s*(ax|ah|al)\\s*$");
    QRegExp rxpRegisterWithoutAccumulator = QRegExp("^\\s*(bx|bh|bl|cx|ch|cl|dx|dh|dl|si|di|sp|bp)\\s*$");
    QRegExp rxpBaseRegister = QRegExp("^\\s*(ax|ah|al|bx|bh|bl|cx|ch|cl|dx|dh|dl|si|di|sp|bp)\\s*$");
    QRegExp rxpSegmentRegister = QRegExp("^\\s*(cs|ds|ss|es|gs|fs)\\s*$");
    QRegExp rxpSegmentRegisterWithoutCS = QRegExp("^\\s*(ds|ss|es|gs|fs)\\s*$");
    QRegExp rxpConstant = QRegExp("^\\s*\\d+\\s*$");

    QRegExp rxpByte = QRegExp("^\\s*(ah|al|bh|bl|ch|cl|dh|dl)\\s*$");
    QRegExp rxp2Bytes = QRegExp("^\\s*(ax|bx|cx|dx|bp|si|di|sp)\\s*$");
    QRegExp rxpCL = QRegExp("^\\s*cl\\s*$");

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

    int EA_ticks = 0;

    if((oper1 == BASE_REGISTER)){

        if(m_strOp2.contains(rxpCL)){
            m_nTicks = 20; // it's so bad! )
        }
        else if(m_strOp2.toInt() == 1){
            m_nTicks = 2;
        }
        else{
            m_nTicks = 0;
            qDebug() << "m_nTicks = 0; opcode_sar.cpp; \"analyse\" function\n";
        }

        if(m_strOp1.contains(rxp2Bytes)){
            m_nBytes = 4;
        }
        else if(m_strOp1.contains(rxpByte)){
            m_nBytes = 2;
        }
        else{
            m_nBytes = 0; //error signal
            qDebug() << "m_nBytes = 0; opcode_sar.cpp; \"analyse\" function\n";
        }
    }
    else if(oper1 == MEMORY){
        EA_ticks = calcEA(m_strOp2);
        if(EA_ticks == 0){
            qDebug() << "EA == 0\n";
        }

        if(m_strOp2.contains(rxpCL)){
            m_nTicks = 40 + EA_ticks; // it's so bad! )
        }
        else if(m_strOp2.toInt() == 1){
            m_nTicks = 15 + EA_ticks;
        }
        else{
            m_nTicks = 0;
            qDebug() << "m_nTicks = 0; opcode_sar.cpp; \"analyse\" function\n";
        }

        m_nBytes = 4;
    }
}
