/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/


#include "comment.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

GComment::GComment(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GComment::initUI(void){

    m_pleComment = new QLineEdit();
    m_pleComment->setPlaceholderText("КОММЕНТАРИЙ");
    m_pleComment->setAlignment(Qt::AlignCenter);
    QLabel* plblSemicolon = new QLabel("<h1><center><strong>;</strong></center></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(plblSemicolon);
    phblGeneral->addWidget(m_pleComment);
    phblGeneral->setMargin(25);

    setLayout(phblGeneral);
}

QString GComment::sourceCode(void){
    QString str;
    str.append(";");
    str.append(m_strComment);

    return(str);
}

void GComment::clearSource(void){
    m_pleComment->clear();
}

void GComment::saveData(void){
    setComment(m_pleComment->text());
}

