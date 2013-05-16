/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/


//#include <QtGui/QApplication>
#include <QApplication>
#include <QtGui>
#include "mainwindow.h"
#include "processor.h"
#include "commandsPanel.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    MainWindow w;
    w.setWindowTitle("OptAsm v1.0");
    w.resize(800, 800);

    //QMainWindow w;

    /*command panel*/
//    GCommandsPanel* pcommands = new GCommandsPanel();
//    pcommands->setFixedWidth(250);

    /*initialize of the virtual processor*/
//    GProcessor* theProcessor = new GProcessor();
//    theProcessor->setAH(0x2F);
//    theProcessor->setBH(0x3F);
//    theProcessor->setCH(0x4F);
//    theProcessor->setDH(0x5F);
//    theProcessor->updateRegisters();

//    QDockWidget* pdockCommands = new QDockWidget();
//    QLabel* plblCommandsTitle = new QLabel("<center><b>Опкоды</b></center>");
//    QLabel* plblProcessorTitle = new QLabel("<center><b>Регистры процессора</b></center>");
//    pdockCommands->setTitleBarWidget(plblCommandsTitle);
//    pdockCommands->setWidget(pcommands);
//    pdockCommands->setFeatures(QDockWidget::NoDockWidgetFeatures);
//    QDockWidget* pdockProcessor = new QDockWidget();
//    pdockProcessor->setTitleBarWidget(plblProcessorTitle);
//    pdockProcessor->setWidget(theProcessor);
//    w.addDockWidget(Qt::RightDockWidgetArea, pdockProcessor);
//    w.addDockWidget(Qt::LeftDockWidgetArea, pdockCommands);

    w.show();

    return a.exec();
}
