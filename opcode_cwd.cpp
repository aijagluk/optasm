/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_cwd.h"
#include <QtWidgets/QTextEdit>

GOpcodeCWD::GOpcodeCWD(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeCWD::initUI(void){
    QLabel* plblCWD = new QLabel("<h1><strong><center>cwd</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblCWD);

    QString info_str = "Преобразует слово в двойное слово, расширяя (копируя) знак содержимого регистра AX в регистр DX. "
            "Если значение в регистре AX положительно, команда заполняет DX нулями, если отрицательно - единицами. "
            "Расширение знака числа, представленного в дополнительном коде, не изменяет значение числа.\n"
            "Регистр флажков не модифицируется.\n"
            "Используется для превращения знакового делимого одинарной длины в делимое двойной длины путем расширения "
            "знака. Если используется беззнаковое деление, то применяется обнуление расширения аккумулятора "
            "(например: SUB DX, DX).";
    QTextEdit* info = new QTextEdit();
    info->setText(info_str);
    info->setReadOnly(true);

    QVBoxLayout* pvblGeneral = new QVBoxLayout();
    pvblGeneral->addWidget(info);
    pvblGeneral->addLayout(phblGeneral);

    setLayout(pvblGeneral);
}

QString GOpcodeCWD::sourceCode(void){
    QString str;
    str.append("cwd");

    return(str);
}

void GOpcodeCWD::analyse(void){
    m_nTicks = 5;
    m_nBytes = 1;
}
