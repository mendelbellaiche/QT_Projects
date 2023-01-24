#include <QApplication>
#include <QPushButton>
#include "Window.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Window w = Window(nullptr, Qt::Window);;
    w.show();

    return QApplication::exec();
}
