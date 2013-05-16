/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#ifndef OPCODE_JZ_H
#define OPCODE_JZ_H

#include <QtGui>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

class GOpcodeJZ : public QWidget{
    Q_OBJECT
public:
    explicit GOpcodeJZ(QWidget *parent = 0);

    explicit GOpcodeJZ(QString op1, QWidget* parent = 0)
        :QWidget(parent), m_strOp1(op1){

    }

    void initUI(void);
    QString sourceCode(void);
    void clearSource();
    void saveData(void);
    void analyse(void);

    QLineEdit* m_pleOp;

private:    
    
    QString m_strOp1;

    int m_nTicks;
    int m_nBytes;

public:

    void setStartFocus(void){
        m_pleOp->setFocus();
    }

    void setOp1(QString str){
        this->m_strOp1 = str;
    }

    QString op1(void) const{
        return(this->m_strOp1);
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

#endif // OPCODE_JZ_H
