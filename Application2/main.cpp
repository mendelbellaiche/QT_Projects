#include <QApplication>
#include <QPushButton>
#include "MyWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MyWindow win;
    win.show();

    return QApplication::exec();
}
