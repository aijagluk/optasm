/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/


#ifndef SOURCE_CODE_H
#define SOURCE_CODE_H

#include <QWidget>
#include <QPair>
#include "source_string.h"

class GSourceCode : public QWidget{
    Q_OBJECT
public:
    explicit GSourceCode(QWidget *parent = 0);

    void addString(GSourceString* pstr);
    void removeString(int index);
    int getTicks(int index);
    int getBytes(int index);
    QStringList* getStringList(void);
    int getCommonTicks(void);
    int getTicksBetweenLines(int from, int to);
    int getCommonBytes(void);
    int getBytesBetweenLines(int from, int to);
    QPair<int, int> *getFirstCycleFrom(int fromLine);
    QVector<QPair<int, int>*>* getAllCycles(void);

private:
    void fullAnalyse(void);

private:
    QVector<GSourceString*>* m_pstrsSrc;
    
signals:
    
public slots:
    
};

#endif // SOURCE_CODE_H
