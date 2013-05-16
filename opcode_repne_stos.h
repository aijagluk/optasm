/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#ifndef OPCODE_REPNE_STOS_H
#define OPCODE_REPNE_STOS_H

#include <QtGui>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

class GOpcodeREPNE_STOS : public QWidget{
    Q_OBJECT
public:
    explicit GOpcodeREPNE_STOS(QWidget *parent = 0);
//    GOpcodeREPNE_STOS(QString str, QWidget *parent = 0);

    void initUI(void);
    QString sourceCode(void);
    void analyse(void);

private:

    int m_nTicks;
    int m_nBytes;

public:

    int ticks(void) const{
        return(m_nTicks);
    }

    int bytes(void) const{
        return(m_nBytes);
    }
    
signals:
    
public slots:
    
};

#endif // OPCODE_REPNE_STOS_H
