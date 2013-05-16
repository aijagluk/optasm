/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "data_dup.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>

GDataDup::GDataDup(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GDataDup::initUI(){
    m_pstrlstValues = new QVector<QString>();
    m_pleName = new QLineEdit();
    m_pleName->setPlaceholderText("ИМЯ");    
    m_pleName->setAlignment(Qt::AlignCenter);
    LabelValidator* plabelValidator = new LabelValidator(m_pleName);
    m_pleName->setValidator(plabelValidator);
    m_psbNumOfDup = new QSpinBox();
    m_psbNumOfDup->setAlignment(Qt::AlignCenter);
    m_psbNumOfDup->setRange(1, 1000000);
    m_psbNumOfDup->setValue(1);
    m_pcbDataType = new QComboBox();
    m_pcbValues = new QComboBox();
    m_pcbValues->setFixedWidth(250);
    m_pcbValues->setEditable(true);

    QStringList strLst;
    strLst << "db" << "dw" << "du" << "dd" << "df" << "dp" << "dq" << "dt";
    m_pcbDataType->addItems(strLst);

    QLabel* plblDup1 = new QLabel("<h1><strong>dup (</strong></h1>");
    QLabel* plblDup2 = new QLabel("<h1><strong>)</strong></h1>");

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(m_pleName);
    phblGeneral->addWidget(m_pcbDataType);
    phblGeneral->addWidget(m_psbNumOfDup);
    phblGeneral->addWidget(plblDup1);
    phblGeneral->addWidget(m_pcbValues);
    phblGeneral->addWidget(plblDup2);
    phblGeneral->addStretch();
    //phblGeneral->setMargin(35);

    setLayout(phblGeneral);
}

QString GDataDup::sourceCode(){

    QRegExp rxp("^\\s*(\\d*|\".*\"|\\'.*\\'|[a-zA-Z_\\[\\?\\$]+[\\[\\]\\-\\+\\/\\*\\$0-9a-zA-Z_\\s]*)\\s*$");
    for(int i = 0; i < m_pcbValues->count(); ++i){
        if(!(m_pcbValues->itemText(i).contains(rxp))){
            return(";кажется, транслятор треснул...\n;выражение провалило валидацию!");
        }
    }

    QString str;
    str.append(m_strDataName);
    str.append(" ");
    str.append(m_strDataType);
    str.append(" ");
    str.append(QString::number(m_nDupValue));
    str.append(" dup ( ");

    if(m_pstrlstValues->count() == 1){
        str.append(m_pstrlstValues->at(0));
    }
    else{
        for(int i = 0; i < m_pstrlstValues->count(); ++i){
            str.append(m_pstrlstValues->at(i));
            if(i != m_pstrlstValues->count() - 1){
                str.append(", ");
            }
        }
    }

    str.append(" )");

    return(str);
}

void GDataDup::clearSource(){
    m_pleName->clear();
    m_psbNumOfDup->setValue(1);
    m_pcbValues->clear();
    m_pcbDataType->setCurrentIndex(0);
}

void GDataDup::saveData(void){
    setDataName(m_pleName->text());
    setDataType(m_pcbDataType->currentText());
    setDupValue(m_psbNumOfDup->text().toInt());

    for(int i = 0; i < m_pcbValues->count(); ++i){
        m_pstrlstValues->push_back(m_pcbValues->itemText(i));
    }
}
