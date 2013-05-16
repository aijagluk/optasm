/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/


#include "data.h"
#include "validators.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

GData::GData(QWidget *parent)
    :QWidget(parent){

    initUI();
}

void GData::initUI(void){
    m_pstrlstValues = new QVector<QString>();
    m_pleName = new QLineEdit();
    m_pleName->setPlaceholderText("ИМЯ");
    m_pleName->setAlignment(Qt::AlignCenter);
    LabelValidator* plabelValidator = new LabelValidator(m_pleName);
    m_pleName->setValidator(plabelValidator);
    m_pcbValues = new QComboBox();
    m_pcbValues->setFixedWidth(250);
    m_pcbValues->setEditable(true);

    m_pcbDataType = new QComboBox();
    QStringList strLst;
    strLst << "db" << "dw" << "du" << "dd" << "df" << "dp" << "dq" << "dt";
    m_pcbDataType->addItems(strLst);    

    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addStretch();
    phblGeneral->addWidget(m_pleName);
    phblGeneral->addWidget(m_pcbDataType);
    phblGeneral->addWidget(m_pcbValues);
    phblGeneral->addStretch();    

    setLayout(phblGeneral);
}

QString GData::sourceCode(void){    
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

    return(str);
}

void GData::clearSource(void){
    m_pleName->clear();
    m_pcbValues->clear();
    m_pcbDataType->setCurrentIndex(0);
}

void GData::saveData(void){
    setDataName(m_pleName->text());
    setDataType(m_pcbDataType->currentText());

    if(m_pcbValues->count() == 0){
        m_pcbValues->insertItem(0, "?");
    }

    for(int i = 0; i < m_pcbValues->count(); ++i){
        m_pstrlstValues->push_back(m_pcbValues->itemText(i));
    }
}

bool GData::validate(void){
    QRegExp rxp = QRegExp("^(0[x|X][a-fA-F0-9]+|0[0-7]*|\".*\"|\d*|\'.*\'|\?)$");
    QPalette pal;

    for(int i = 0; i < m_pcbValues->count(); ++i){
        if(!m_pcbValues->itemText(i).contains(rxp)){
            pal = m_pcbValues->palette();
            pal.setColor(QPalette::Window, Qt::red);
            m_pcbValues->setPalette(pal);
            return(false);
        }
    }

    return(true);
}
