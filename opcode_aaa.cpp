/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_aaa.h"
#include <QtWidgets/QTextEdit>

GOpcodeAAA::GOpcodeAAA(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeAAA::initUI(void){
    QLabel* plblAAA = new QLabel("<h1><strong><center>aaa</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblAAA);    

    QString info_str = "Производит символьную коррекцию результата двоичного сложения байтовых ASCII-чисел,"
                       " который содержится в аккумуляторе AL.\n"
            "Сложение ASCII-чисел производится в два этапа: сначала байты суммируются как обычные двоичные числа,"
            " а затем осуществляется коррекция по следующим правилам:\n"
            "\t1) Если младшая тетрада AL меньше или равна десятичному числу 9 и флажок AF=0, то переход к шагу 3.\n"
            "\t2) Если младшая тетрада AL больше десятичного числа 9 и флажок AF=1, то к содержимому AL прибавляется"
            " число 6, к содержимому регистра AH прибавляется единица, а флажок AF устанавливается в 1.\n"
            "\t3) Сбрасывается старшая тетрада аккумулятора AL.\n"
            "\t4) Флажок CF устанавливается в то же состояние, что и флажок AF.\n"
            "Флажки CF и AF устанавливаются в 1, если результат суммирования больше числа 9. "
            "Состояние остальных флажков не определено.";
    QTextEdit* info = new QTextEdit();
    info->setText(info_str);
    info->setReadOnly(true);

    QVBoxLayout* pvblGeneral = new QVBoxLayout();
    pvblGeneral->addWidget(info);
    pvblGeneral->addLayout(phblGeneral);

    setLayout(pvblGeneral);
}

QString GOpcodeAAA::sourceCode(void){
    QString str;
    str.append("aaa");

    return(str);
}

void GOpcodeAAA::analyse(){
    m_nTicks = 4;
    m_nBytes = 1;
}
