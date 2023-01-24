#include <QApplication>
#include "Window.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto *w = new Window(nullptr, Qt::Window);
    w->show();

    return QApplication::exec();
}
