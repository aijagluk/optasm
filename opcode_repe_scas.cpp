/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_repe_scas.h"
#include "services_types.h"

GOpcodeREPE_SCAS::GOpcodeREPE_SCAS(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeREPE_SCAS::initUI(void){
    m_pleOp1 = new QLineEdit();

    m_pleOp1->setAlignment(Qt::AlignCenter);

    QLabel* plblREPE_SCAS = new QLabel("<h1><strong>repe scas</strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(plblREPE_SCAS);
    phblGeneral->addWidget(m_pleOp1);
    phblGeneral->addStretch();

    setLayout(phblGeneral);
}

QString GOpcodeREPE_SCAS::sourceCode(void){
    QString str;
    str.append("repe scas ");
    str.append(m_strOp1);

    return(str);
}

void GOpcodeREPE_SCAS::clearSource(void){
    m_pleOp1->clear();
}

void GOpcodeREPE_SCAS::saveData(void){
    setOp1(m_pleOp1->text());
}

void GOpcodeREPE_SCAS::analyse(void){
    QRegExp rxpAccumulator = QRegExp("^\\s*(ax|ah|al)\\s*$");
    QRegExp rxpRegisterWithoutAccumulator = QRegExp("^\\s*(bx|bh|bl|cx|ch|cl|dx|dh|dl|si|di|sp|bp)\\s*$");
    QRegExp rxpBaseRegister = QRegExp("^\\s*(ax|ah|al|bx|bh|bl|cx|ch|cl|dx|dh|dl|si|di|sp|bp)\\s*$");
    QRegExp rxpSegmentRegister = QRegExp("^\\s*(cs|ds|ss|es|gs|fs)\\s*$");
    QRegExp rxpSegmentRegisterWithoutCS = QRegExp("^\\s*(ds|ss|es|gs|fs)\\s*$");
    QRegExp rxpConstant = QRegExp("^\\s*\\d+\\s*$");

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

    //int EA_ticks = 0;

    if(oper1 == MEMORY){
        m_nTicks = 15;
        m_nBytes = 1;

    }
    else{
        qDebug() << "command is not recognize!\n";
    }
}
