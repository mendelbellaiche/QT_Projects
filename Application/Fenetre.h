//
// Created by mendel bellaiche on 05/12/2022.
//

#ifndef APPLICATION_FENETRE_H
#define APPLICATION_FENETRE_H

#include <QWidget>
#include <QPushButton>
#include <QTableWidget>

class Fenetre: public QWidget {

    Q_OBJECT

    public:
        Fenetre(QWidget *parent = nullptr);
        ~Fenetre();

    private:
        QPushButton *open;
        QTableWidget *table;

    public slots:
        void cellClicked(int, int);

};


#endif //APPLICATION_FENETRE_H
