#include "inc/ui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UI w;
    w.move(0,0);
    w.setStyleSheet("background:gray");
    w.show();

    return a.exec();
}
