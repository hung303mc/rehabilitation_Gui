#include <QApplication>
#include "jrdgui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JrdGui w;
    w.show();
    return a.exec();
}
