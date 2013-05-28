/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_cbw.h"
#include <QtWidgets/QTextEdit>

GOpcodeCBW::GOpcodeCBW(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeCBW::initUI(void){
    QLabel* plblCBW = new QLabel("<h1><strong><center>cbw</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblCBW);

    QString info_str = "Преобразует байт в слово, расширяя (копируя) знак содержимого регистра "
            "AL в регистр AH. Если значение в регистре AL положительно, команда заполняет регистр "
            "AH нулями, если отрицательно - единицами. Расширение знака числа, представленного "
            "в дополнительном коде, не изменяет значение числа.\n"
            "Регистр флажков не модифицируется.\n"
            "Используется для превращения знакового делимого одинарной длины в делимое двойной "
            "длины путем расширения знака. Если используется беззнаковое деление, то применяется "
            "обнуление расширения аккумулятора (например: SUB AH, AH).";
    QTextEdit* info = new QTextEdit();
    info->setText(info_str);
    info->setReadOnly(true);

    QVBoxLayout* pvblGeneral = new QVBoxLayout();
    pvblGeneral->addWidget(info);
    pvblGeneral->addLayout(phblGeneral);

    setLayout(pvblGeneral);
}

QString GOpcodeCBW::sourceCode(void){
    QString str;
    str.append("cbw");

    return(str);
}

void GOpcodeCBW::analyse(void){
    m_nTicks = 2;
    m_nBytes = 1;
}
