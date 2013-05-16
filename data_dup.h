/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#ifndef DATA_DUP_H
#define DATA_DUP_H

#include <QtGui>
#include <QtWidgets/QSpinBox>
#include "validators.h"
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>

class GDataDup : public QWidget{
    Q_OBJECT
public:
    explicit GDataDup(QWidget *parent = 0);

    explicit GDataDup(QString dataName_, QString dataType_, QString dupValue_, QVector<QString> lstValues_, QWidget* parent = 0)
        :QWidget(parent), m_strDataName(dataName_), m_strDataType(dataType_), m_nDupValue(dupValue_.toInt()), m_pstrlstValues(&lstValues_){

    }
    
    void initUI(void);
    QString sourceCode(void);
    void clearSource(void);
    void saveData(void);

private:
    QLineEdit* m_pleName;
    QSpinBox* m_psbNumOfDup;
    QComboBox* m_pcbDataType;
    QComboBox* m_pcbValues;

    QString m_strDataName;
    QString m_strDataType;
    int m_nDupValue;
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

    int dupValue(void) const{
        return(this->m_nDupValue);
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

    void setDupValue(int val){
        this->m_nDupValue = val;
    }

    void setValuesList(QVector<QString>* values){
        this->m_pstrlstValues = values;
    }

signals:
    
public slots:
    
};

#endif // DATA_DUP_H
