#include <QApplication>
#include "Widget.h"
#include "Fenetre.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // QPushButton button("Click here", nullptr);
    // button.resize(200, 100);
    // button.show();

    // Widget w;
    // w.show();

    Fenetre f;
    f.show();

    return QApplication::exec();
}
