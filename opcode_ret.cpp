/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_ret.h"
#include "services_types.h"
#include <QtWidgets/QTextEdit>

GOpcodeRET::GOpcodeRET(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeRET::initUI(void){
    m_pleOp = new QLineEdit();

    m_pleOp->setAlignment(Qt::AlignCenter);

    QLabel* plblRET = new QLabel("<h1><strong>ret</strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(plblRET);
    phblGeneral->addWidget(m_pleOp);
    phblGeneral->addStretch();

    QString info_str = "Возвращает управление вызывающей программе. Команда возврата - это косвенный переход, "
            "т.к. адрес перехода извлекается из вершины стека.\n"
            "Команда возврата с операндом-константой дополнительно прибавляет содержащееся в ней данное, "
            "к указателю стека SP, что упрощает возврат из подпрограмм, параметры которых передаются в стеке.\n"
            "Регистр флажков не модифицируется.";
    QTextEdit* info = new QTextEdit();
    info->setText(info_str);
    info->setReadOnly(true);

    QVBoxLayout* pvblGeneral = new QVBoxLayout();
    pvblGeneral->addWidget(info);
    pvblGeneral->addLayout(phblGeneral);

    setLayout(pvblGeneral);
}

QString GOpcodeRET::sourceCode(void){
    QString str;
    str.append("ret ");
    str.append(m_strOp1);

    return(str);
}

void GOpcodeRET::clearSource(void){
    m_pleOp->clear();
}

void GOpcodeRET::saveData(void){
    setOp1(m_pleOp->text());
}

void GOpcodeRET::analyse(void){
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

    if(oper1 == CONSTANT_VALUE){

        m_nTicks = 12;
        m_nBytes = 3;
    }
    else if(m_strOp1.isEmpty()){
        m_nTicks = 18;
        m_nBytes = 1;
    }
    else{
        m_nTicks = 0;
        m_nBytes = 0;
        qDebug() << "m_nTicks = m_nBytes = 0; opcode_ret.cpp; \"analyse\" function\n";
    }

}
