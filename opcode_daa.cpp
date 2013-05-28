/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_daa.h"
#include <QtWidgets/QTextEdit>

GOpcodeDAA::GOpcodeDAA(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeDAA::initUI(void){
    QLabel* plblDAA = new QLabel("<h1><strong><center>daa</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblDAA);

    QString info_str = "Производит десятичную коррекцию результата двоичного сложения байтовых BCD-чисел, "
            "который содержится в регистре AL.\n"
            "Сложение чисел производится в два этапа: сначала байты суммируются как обычные двоичные числа, "
            "а затем осуществляется коррекция результата по следующим правилам:\n"
            "\t1) Если флажок AF=1 или младшая тетрада AL больше десятичной цифры 9, то к содержимому AL "
            "прибавляется число 6 и флажок AF устанавливается в 1.\n"
            "\t2) Если флажок CF=1 или старшая тетрада AL больше десятичной цифры 9, то к содержимому AL "
            "прибавляется число 60 (в BCD-формате) и флажок CF устанавливается в 1.\n"
            "После коррекции в регистре AL остается упакованное десятичное число в диапазоне от 0 до 99.\n"
            "Устанавливает все арифметические флажки в зависимости от полученного результата, "
            "за исключением флажков OF и AF, состояние которых после коррекции не определено.\n"
            "Переполнение определяется по флажку переноса CF. Если CF=1, результат сложения превысил "
            "значение 99 и в регистре AL после коррекции остается усеченный результат (две младшие цифры).\n"
            "Сложение BCD-чисел повышенной точности аналогично двоичному сложению с повышенной точностью (ADC), "
            "но после сложения каждого байта необходимо производить двоичную коррекцию.";
    QTextEdit* info = new QTextEdit();
    info->setText(info_str);
    info->setReadOnly(true);

    QVBoxLayout* pvblGeneral = new QVBoxLayout();
    pvblGeneral->addWidget(info);
    pvblGeneral->addLayout(phblGeneral);

    setLayout(pvblGeneral);
}

QString GOpcodeDAA::sourceCode(void){
    QString str;
    str.append("daa");

    return(str);
}

void GOpcodeDAA::analyse(void){
    m_nTicks = 4;
    m_nBytes = 1;
}
