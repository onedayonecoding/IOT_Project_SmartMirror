#include "header/ui.h"

#include <QApplication>
#include <QThread>

int main(int argc, char *argv[])
{
    //날씨 프로세스
    QProcess::execute("weather/dist/weather");

    QApplication a(argc, argv);
    UI w;
    w.show();

    return a.exec();
}



