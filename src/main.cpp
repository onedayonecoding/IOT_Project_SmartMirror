#include "header/ui.h"

#include <QApplication>
#include<qdebug.h>
#include <qdir.h>

int main(int argc, char *argv[])
{
    //날씨 프로세스

    QProcess *process =new QProcess;
    process->setWorkingDirectory("weather/dist");
    process->start("./weather");

    QApplication a(argc, argv);
    UI w;
    w.show();

    return a.exec();
}



