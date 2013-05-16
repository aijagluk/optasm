/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#ifndef LABEL_UNNAMED_H
#define LABEL_UNNAMED_H

#include <QtGui>
#include <QtWidgets/QWidget>

class GLabelUnnamed : public QWidget{    
    Q_OBJECT
public:
    explicit GLabelUnnamed(QWidget *parent = 0);
//    GLabelUnnamed(QString str, QWidget* pwgt = 0);
    
    void initUI();
    QString sourceCode(void);

signals:
    
public slots:
    
};

#endif // LABEL_UNNAMED_H
