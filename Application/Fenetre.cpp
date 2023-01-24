//
// Created by mendel bellaiche on 05/12/2022.
//

#include "Fenetre.h"
#include <vector>
#include <QHeaderView>
#include <QVBoxLayout>

Fenetre::Fenetre(QWidget *parent) {
    setWindowTitle("My list of url");
    resize(500, 300);

    std::vector<QString> v;
    v.emplace_back("https://www.google.com/");
    v.emplace_back("https://www.youtube.com/");
    v.emplace_back("https://www.apple.com/");
    v.emplace_back("https://dico.elix-lsf.fr/");
    v.emplace_back("https://www.chess.com/");
    v.emplace_back("https://www.hostinger.com/");
    v.emplace_back("https://www.udemy.com/fr/");

    table = new QTableWidget(v.size(), 1);
    open = new QPushButton("Open");

    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i=0; i<v.size(); i++) {
        auto *newValue = new QTableWidgetItem(v.at(i));
        table->setItem(i, 0, newValue);
    }

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(table);
    // layout->addWidget(open);

    connect(table, SIGNAL(cellClicked(int, int)), this, SLOT(cellClicked(int, int)));

}

Fenetre::~Fenetre() {}

void Fenetre::cellClicked(int r, int c) {
    if (c == 0) {
        auto *item = table->item(r, c);

        QString str1 = QString("open %1").arg(item->text());
        QByteArray ba = str1.toLocal8Bit();
        system(ba.data());
    }
}
