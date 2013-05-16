/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "label_unnamed.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

GLabelUnnamed::GLabelUnnamed(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GLabelUnnamed::initUI(){
    QLabel* plblUnnamedLabel = new QLabel("<h1><center><strong>@@:</strong></center></h1>");
    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(plblUnnamedLabel);
    phblGeneral->addStretch();

    setLayout(phblGeneral);
}

QString GLabelUnnamed::sourceCode(void){

    QString str;
    str.append("@@:");

    return(str);
}
