/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "opcode_das.h"
#include <QtWidgets/QTextEdit>

GOpcodeDAS::GOpcodeDAS(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GOpcodeDAS::initUI(void){
    QLabel* plblDAS = new QLabel("<h1><strong><center>das</center></strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblDAS);

    QString info_str = "Производит десятичную коррекцию результата двоичного вычитания байтовых BCD-чисел, "
            "который содержится в регистре AL.\n"
            "Вычитание производится в два этапа: сначала осуществляется вычитание как для обычных двоичных чисел, "
            "а затем корректируется результат по следующим правилам:\n"
            "\t1) Если флажок AF=1 или младшая тетрада AL больше десятичной цифры 9, то из содержимого AL вычитается "
            "число 6 и флажок AF устанавливается в 1.\n"
            "\t2) Если флажок CF=1 или старшая тетрада AL больше десятичной цифры 9, то из содержимого AL вычитается "
            "число 60 и флажок CF устанавливается в 1.\n"
            "Устанавливаются все арифметические флажки в зависимости от полученного результата, за исключением "
            "флажков OF и AF, состояние которых после коррекции не определено. Флажок CF интерпретируется как "
            "флажок заема, он равен 1, если вычитаемое больше уменьшаемого.\n"
            "Вычитание BCD-чисел с повышенной точностью аналогично двоичному вычитанию с повышенной точностью (SBB). "
            "Но после каждого байтового вычитания необходимо производить десятичную коррекцию.";
    QTextEdit* info = new QTextEdit();
    info->setText(info_str);
    info->setReadOnly(true);

    QVBoxLayout* pvblGeneral = new QVBoxLayout();
    pvblGeneral->addWidget(info);
    pvblGeneral->addLayout(phblGeneral);

    setLayout(pvblGeneral);
}

QString GOpcodeDAS::sourceCode(void){
    QString str;
    str.append("das");

    return(str);
}

void GOpcodeDAS::analyse(void){
    m_nTicks = 4;
    m_nBytes = 1;
}
