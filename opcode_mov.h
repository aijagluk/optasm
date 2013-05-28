/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#ifndef OPCODE_MOV_H
#define OPCODE_MOV_H

#include <QtGui>
#include "validators.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

class GOpcodeMOV : public QWidget{
    Q_OBJECT
public:
    explicit GOpcodeMOV(QWidget *parent = 0);

    explicit GOpcodeMOV(QString op1, QString op2, QWidget* parent = 0)
        :QWidget(parent), m_strOp1(op1), m_strOp2(op2){

    }
    
    void initUI(void);
    QString sourceCode(void);
    void clearSource();
    void saveData(void);
    int calcEA(QString str);
    void analyse(void);

    QLineEdit* m_pleOp2;

private:
    QLineEdit* m_pleOp1;

    QString m_strOp1;
    QString m_strOp2;

    int m_nTicks;
    int m_nBytes;

public:

    void setStartFocus(void){
        m_pleOp1->setFocus();
    }

    void setOp1(QString str){
        this->m_strOp1 = str;
    }

    void setOp2(QString str){
        this->m_strOp2 = str;
    }

    QString op1(void) const{
        return(this->m_strOp1);
    }

    QString op2(void) const{
        return(this->m_strOp2);
    }

    int ticks(void) const{
        return(m_nTicks);
    }

    int bytes(void) const{
        return(m_nBytes);
    }

signals:
    
public slots:
    
};

#endif // OPCODE_MOV_H
