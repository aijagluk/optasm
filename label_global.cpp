/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "label_global.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

GLabelGlobal::GLabelGlobal(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GLabelGlobal::initUI(void){

    m_pleLabelName = new QLineEdit();
    m_pleLabelName->setPlaceholderText("ИМЯ ГЛОБАЛЬНОЙ МЕТКИ");
    m_pleLabelName->setAlignment(Qt::AlignCenter);
    LabelValidator* plabelValidator = new LabelValidator(m_pleLabelName);
    m_pleLabelName->setValidator(plabelValidator);
    QLabel* plblColon = new QLabel("<h1><strong>:</h1></strong>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(m_pleLabelName);
    phblGeneral->addWidget(plblColon);
    phblGeneral->addStretch();

    setLayout(phblGeneral);
}

QString GLabelGlobal::sourceCode(void){

    QString str;
    str.append(m_strLabelName);
    str.append(":");

    return(str);
}

void GLabelGlobal::clearSource(void){
    m_pleLabelName->clear();
}

void GLabelGlobal::saveData(void){
    setLabelName(m_pleLabelName->text());
}
