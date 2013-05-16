/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#ifndef DATA_H
#define DATA_H

#include <QtGui>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include "validators.h"

class GData : public QWidget{
    Q_OBJECT
public:
    explicit GData(QWidget *parent = 0);

    explicit GData(QString dataName_, QString dataType_, QVector<QString> lstValues_, QWidget* parent = 0)
        :QWidget(parent), m_strDataName(dataName_), m_strDataType(dataType_), m_pstrlstValues(&lstValues_){

    }

    void initUI(void);
    QString sourceCode(void);
    void clearSource(void);
    void saveData();
    
private:
    QLineEdit* m_pleName;
    QComboBox* m_pcbValues;
    QComboBox* m_pcbDataType;

    QString m_strDataName;
    QString m_strDataType;
    QVector<QString>* m_pstrlstValues;

public:

    void setStartFocus(void){
        m_pleName->setFocus();
    }

    QString dataName(void) const{
        return(this->m_strDataName);
    }

    QString dataType(void) const{
        return(this->m_strDataType);
    }

    QVector<QString>* valuesList(void) const{
        return(this->m_pstrlstValues);
    }

    void setDataName(QString str){
        this->m_strDataName = str;
    }

    void setDataType(QString str){
        this->m_strDataType = str;
    }

    void setValuesList(QVector<QString>* values){
        this->m_pstrlstValues = values;
    }

signals:
    
public slots:
    bool validate(void);
};

#endif // DATA_H
