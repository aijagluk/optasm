/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#ifndef COMMENT_H
#define COMMENT_H

#include <QtGui>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>

class GComment : public QWidget{
    Q_OBJECT
public:
    explicit GComment(QWidget *parent = 0);

    explicit GComment(QString comment_, QWidget* parent = 0)
        :QWidget(parent), m_strComment(comment_){

    }

    void initUI();
    QString sourceCode(void);
    void clearSource(void);
    void saveData(void);

    QLineEdit* m_pleComment;

private:    
    QString m_strComment;

public:

    void setStartFocus(void){
        m_pleComment->setFocus();
    }

    QString comment(void) const{
        return(m_strComment);
    }

    void setComment(QString str){
        this->m_strComment = str;
    }

signals:
    
public slots:
    
};

#endif // COMMENT_H
