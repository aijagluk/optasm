/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_aas.h"
#include <QtWidgets/QTextEdit>

GOpcodeAAS::GOpcodeAAS(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeAAS::initUI(void){
    QLabel* plblAAS = new QLabel("<h1><strong><center>aas</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblAAS);

    QString info_str = "Производит символьную коррекцию результата двоичного вычитания байтовых ASCII-чисел, "
            "который содержится в регистре AL.\n"
            "Вычитание производится в два этапа: сначала осуществляется вычитание как для обычных двоичных чисел, "
            "а затем результат корректируется по следующим правилам:\n"
            "\t1) Если младшая тетрада AL меньше или равна десятичному числу 9 и флажое AF=0, то переход к шагу 3.\n"
            "\t2) Если младшая тетрада AL больше десятичного числа 9 и флажок AF=1, то из содержимого AL вычитается 6, "
            " из содержимого AH вычитается единица, а флажок AF устанавливается в 1.\n"
            "\t3) Сбрасывается старшая тетрада аккумулятора AL.\n"
            "\t4) Флажок CF устанавливается в то же состояние, что и флажок AF.\n"
            "Флажки AF и CF устанавливаются в 1, если вычитаемое больше уменьшаемого (AF и CF интерпретируются как флажки заема). \n"
            "Состояние остальных флажков не определено.\n"
            "Вычитание ASCII-чисел с повышенной точностью похоже на двоичную арифметику с повышенной точностью, но после каждого "
            "байтового вычитания необходимо производить символьную коррекцию";
    QTextEdit* info = new QTextEdit();
    info->setText(info_str);
    info->setReadOnly(true);

    QVBoxLayout* pvblGeneral = new QVBoxLayout();
    pvblGeneral->addWidget(info);
    pvblGeneral->addLayout(phblGeneral);

    setLayout(pvblGeneral);
}

QString GOpcodeAAS::sourceCode(void){
    QString str;
    str.append("aas");

    return(str);
}

void GOpcodeAAS::analyse(void){
    m_nTicks = 4;
    m_nBytes = 1;
}
