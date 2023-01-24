//
// Created by mendel bellaiche on 04/12/2022.
//

#ifndef APPLICATION_WIDGET_H
#define APPLICATION_WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class Widget: public QWidget {

    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void clicked(bool);

private:
    int counter = 0;
    QPushButton *btn;
    QLabel *dataLbl;
    QLabel *counterLbl;
    QLineEdit *edit;

    QVBoxLayout *vBox;
};


#endif //APPLICATION_WIDGET_H
