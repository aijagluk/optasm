/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_pop.h"
#include "services_types.h"

GOpcodePOP::GOpcodePOP(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodePOP::initUI(void){
    m_pleOp = new QLineEdit();

    m_pleOp->setAlignment(Qt::AlignCenter);

    QLabel* plblPOP = new QLabel("<h1><strong>pop</strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(plblPOP);
    phblGeneral->addWidget(m_pleOp);
    phblGeneral->addStretch();

    setLayout(phblGeneral);
}

QString GOpcodePOP::sourceCode(void){
    QString str;
    str.append("pop ");
    str.append(m_strOp1);

    return(str);
}

void GOpcodePOP::clearSource(void){
    m_pleOp->clear();
}

void GOpcodePOP::saveData(void){
    setOp1(m_pleOp->text());
}

int GOpcodePOP::calcEA(QString str){

    QRegExp rxpTicks12 = QRegExp("^(\\[\\s*bp\\s*\\+\\s*si\\s*\\+\\s*\\w+\\s*\\]|\\[\\s*bx\\s*\\+\\s*di\\s*\\+\\s*\\w+\\s*\\])$");
    QRegExp rxpTicks11 = QRegExp("^(\\[\\s*bp\\s*\\+\\s*di\\s*\\+\\s*\\w+\\s*\\]|\\[\\s*bx\\s*\\+\\s*si\\s*\\+\\s*\\w+\\s*\\])$");
    QRegExp rxpTicks8 = QRegExp("^(\\[\\s*bp\\s*\\+\\s*si\\s*\\]|\\[\\s*bx\\s*\\+\\s*di\\s*\\])$");
    QRegExp rxpTicks7 = QRegExp("^(\\[\\s*bp\\s*\\+\\s*di\\s*\\]|\\[\\s*bx\\s*\\+\\s*si\\s*\\])$");
    QRegExp rxpTicks9 = QRegExp("^(\\[\\s*(bx|bp|si|di)\s*\\+\\s*\\w+\\s*\\])$");
    QRegExp rxpTicks5 = QRegExp("^(\\[\\s*(bx|bp|si|di)\\s*\\])$");
    QRegExp rxpTicks6 = QRegExp("^(\\w+)$");

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

void GOpcodePOP::analyse(void){
    QRegExp rxpAccumulator = QRegExp("^\\s*(ax|ah|al)\\s*$");
    QRegExp rxpRegisterWithoutAccumulator = QRegExp("^\\s*(bx|bh|bl|cx|ch|cl|dx|dh|dl|si|di|sp|bp)\\s*$");
    QRegExp rxpBaseRegister = QRegExp("^\\s*(ax|ah|al|bx|bh|bl|cx|ch|cl|dx|dh|dl|si|di|sp|bp)\\s*$");
    QRegExp rxpSegmentRegister = QRegExp("^\\s*(cs|ds|ss|es|gs|fs)\\s*$");
    QRegExp rxpSegmentRegisterWithoutCS = QRegExp("^\\s*(ds|ss|es|gs|fs)\\s*$");
    QRegExp rxpConstant = QRegExp("^\\s*\\d+\\s*$");

    QRegExp rxpByte = QRegExp("^\\s*(ah|al|bh|bl|ch|cl|dh|dl)\\s*$");
    QRegExp rxp2Bytes = QRegExp("^\\s*(ax|bx|cx|dx|bp|si|di|sp)\\s*$");

    OperandType oper1;

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

    int EA_ticks = 0;

    if(oper1 == BASE_REGISTER){
        m_nTicks = 8;
        m_nBytes = 1;
    }
    else if(oper1 == SEGMENT_REGISTER){
        m_nTicks = 8;
        m_nBytes = 1;
    }
    else if(oper1 == MEMORY){
        EA_ticks = calcEA(m_strOp1);
        if(EA_ticks == 0){
            qDebug() << "EA == 0\n";
        }
        m_nTicks = 17 + EA_ticks;

        if(m_strOp1.contains(rxpByte)){
            m_nBytes = 3;
        }
        else if(m_strOp1.contains(rxp2Bytes)){
            m_nBytes = 4;
        }
        else{
            m_nBytes = 0; //error signal
            qDebug() << "m_nBytes = 0";
        }
    }
}
