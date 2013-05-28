/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_aad.h"
#include <QtWidgets/QTextEdit>

GOpcodeAAD::GOpcodeAAD(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeAAD::initUI(void){
    QLabel* plblAAD = new QLabel("<h1><strong><center>aad</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblAAD);

    QString info_str = "Производит символьную коррекцию содержимого регистра AX по следующим правилам:\n"
            "\t1) Содержимое регистра AH умножается на число 10.\n"
            "\t2) Полученный результат прибавляется к содержимому регистра AL.\n"
            "\t3) Содержимое регистра AH сбрасывается.\n"
            "Деление ASCII-чисел производится в два этапа: сначала двухбайтовое ASCII-делимое преобразуется в двоичное число в регистре AL, "
            "а затем командой DIV содержимое регистра AX делится на байтовое ASCII-число. После деления в регистре AL остаеся частное, "
            "а в регистре AH - остаток.\n"
            "Состояние флажков SF, ZF, PF зависит от содержимого регистра AL. Состояние флажков OF, AF, CF не определено.\n"
            "Если делитель равен 0, то генерируется прерываение типа 0. Если в программе нет оработки такого прерывания, необходимо "
            "до операции проверить возможность возникновения деления на 0.\n"
            "Может оказаться, что частное - это не одна десятичная цифра (например, когда число 40 делится на 2). "
            "При этом переполнение не возникает, поэтому после каждой последовательности команд AAD-DIV необходимо проверять, "
            "не превысило ли частное числа 9, и вызывать соответствующую обработку переполнения.";

    QTextEdit* info = new QTextEdit();
    info->setText(info_str);
    info->setReadOnly(true);

    QVBoxLayout* pvblGeneral = new QVBoxLayout();
    pvblGeneral->addWidget(info);
    pvblGeneral->addLayout(phblGeneral);

    setLayout(pvblGeneral);
}

QString GOpcodeAAD::sourceCode(void){
    QString str;
    str.append("aad");

    return(str);
}

void GOpcodeAAD::analyse(void){
    m_nTicks = 60;
    m_nBytes = 2;
}
