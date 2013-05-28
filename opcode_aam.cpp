/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_aam.h"
#include <QtWidgets/QTextEdit>

GOpcodeAAM::GOpcodeAAM(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeAAM::initUI(void){
    QLabel* plblAAM = new QLabel("<h1><strong><center>aam</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblAAM);

    QString info_str = "Производит символьную коррекцию результата умножения байтовых ASCII-чисел, который содержится в регистре AL.\n"
            "Умножение ASCII-чисел производится в два этапа: сначала осуществляется умножение командой MUL, а затем результат "
            "корректируется по следующим правилам:\n"
            "\t1) Содержимое регистра AL делится на число 10.\n"
            "\t2) Частное загружается в регистр AH, а остаток - в регистр AL.\n"
            "Состояние флажков SF, ZF, PF зависит от содержимого регистра AL.\n"
            "Состояние флажков OF, AF, CF не определено.\n"
            "Команду AAM можно использовать для деления двоичного числа на 10. Частное помещается в регистр AH, остаток - в регистр AL.";
    QTextEdit* info = new QTextEdit();
    info->setText(info_str);
    info->setReadOnly(true);

    QVBoxLayout* pvblGeneral = new QVBoxLayout();
    pvblGeneral->addWidget(info);
    pvblGeneral->addLayout(phblGeneral);

    setLayout(pvblGeneral);
}

QString GOpcodeAAM::sourceCode(void){
    QString str;
    str.append("aam");

    return(str);
}

void GOpcodeAAM::analyse(void){
    m_nTicks = 83;
    m_nBytes = 2;
}
