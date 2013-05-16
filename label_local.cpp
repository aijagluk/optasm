/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "label_local.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

GLabelLocal::GLabelLocal(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GLabelLocal::initUI(void){
    m_pleLabelName = new QLineEdit();
    m_pleLabelName->setPlaceholderText("ИМЯ ЛОКАЛЬНОЙ МЕТКИ");
    m_pleLabelName->setAlignment(Qt::AlignCenter);
    LabelValidator* plabelValidator = new LabelValidator(m_pleLabelName);
    m_pleLabelName->setValidator(plabelValidator);
    QLabel* plblDot = new QLabel("<h1><strong>.</strong></h1>");
    QLabel* plblColon = new QLabel("<h1><strong>:</strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(plblDot);
    phblGeneral->addWidget(m_pleLabelName);
    phblGeneral->addWidget(plblColon);
    phblGeneral->addStretch();

    setLayout(phblGeneral);
}

QString GLabelLocal::sourceCode(void){

    QString str;
    str.append(".");
    str.append(m_strLabelName);
    str.append(":");

    return(str);
}

void GLabelLocal::clearSource(void){
    m_pleLabelName->clear();
}

void GLabelLocal::saveData(void){
    setLabelName(m_pleLabelName->text());
}
