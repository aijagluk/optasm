/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (aijagluk@gmail.com)          *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2012 *
**********************************************************************/

#ifndef COMMANDSPANEL_H
#define COMMANDSPANEL_H

#include <QWidget>
#include <QToolBox>

class GCommandsPanel : public QWidget{
    Q_OBJECT
public:
    explicit GCommandsPanel(QWidget *parent = 0);
    
private:
    QToolBox* m_ptoolCommandsPanel;

signals:
    
public slots:
    
};

#endif // COMMANDSPANEL_H
