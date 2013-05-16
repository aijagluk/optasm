/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#ifndef VALIDATORS_H
#define VALIDATORS_H

#include <QValidator>

class LabelValidator : public QValidator{
    Q_OBJECT
public:
    LabelValidator(QObject* parent)
        :QValidator(parent){

    }

    virtual State validate(QString& str, int& /*pos*/) const{
        QRegExp rxp = QRegExp("^([a-zA-Z_]+[0-9a-zA-Z_]*)?$");
        if(str.contains(rxp)){
            return(Acceptable);
        }
        return(Invalid);
    }
};

#endif // VALIDATORS_H
