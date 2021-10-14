#include "schedule.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Schedule w;

    w.show();
    return a.exec();
}
