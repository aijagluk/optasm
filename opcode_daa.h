/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#ifndef OPCODE_DAA_H
#define OPCODE_DAA_H

#include <QtGui>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

class GOpcodeDAA : public QWidget{
    Q_OBJECT
public:
    explicit GOpcodeDAA(QWidget *parent = 0);
//    GOpcodeDAA(QString str, QWidget *parent = 0);

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

#endif // OPCODE_DAA_H
