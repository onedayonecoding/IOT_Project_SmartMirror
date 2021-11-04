#include "header/ui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //날씨 프로세스
    QProcess::execute("../function/weather/weather");

    QApplication a(argc, argv);
    UI w;
    w.show();

    return a.exec();
}


