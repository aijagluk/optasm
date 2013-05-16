/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#ifndef LABEL_GLOBAL_H
#define LABEL_GLOBAL_H

#include <QtGui>
#include "validators.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>

class GLabelGlobal : public QWidget{
    Q_OBJECT
public:
    explicit GLabelGlobal(QWidget *parent = 0);

    explicit GLabelGlobal(QString label, QWidget* parent = 0)
        :QWidget(parent), m_strLabelName(label){

    }
    
    void initUI(void);
    QString sourceCode(void);
    void clearSource(void);
    void saveData(void);

    QLineEdit* m_pleLabelName;

private:    
    QString m_strLabelName;

public:

    void setStartFocus(void){
        m_pleLabelName->setFocus();
    }

    void setLabelName(QString str){
        this->m_strLabelName = str;
    }

    QString labelName(void) const{
        return(this->m_strLabelName);
    }

signals:
    
public slots:
    
};

#endif // LABEL_GLOBAL_H
