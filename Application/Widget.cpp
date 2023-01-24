//
// Created by mendel bellaiche on 04/12/2022.
//

#include "Widget.h"
#include <QMessageBox>

#define MAX 20

Widget::Widget(QWidget *parent): QWidget(parent) {

    setWindowTitle("Application");
    resize(300, 200);

    vBox = new QVBoxLayout(this);
    edit = new QLineEdit();
    dataLbl = new QLabel("");
    counterLbl = new QLabel(QString("Click left: %1").arg(MAX));
    btn = new QPushButton("Click Here");


    edit->setPlaceholderText("Please to fill in here");
    edit->setStyleSheet("padding: 10px;");

    dataLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    dataLbl->setFont(QFont("Helvetica", 16));
    // dataLbl->setAlignment(Qt::AlignRight);

    btn->setFont(QFont("Helvetica", 16));
    btn->setStyleSheet("padding-top: 12px; padding-bottom: 10px;");

    counterLbl->setFixedHeight(20);
    counterLbl->setAlignment(Qt::AlignRight);
    counterLbl->setStyleSheet("color: grey;");
    vBox->addWidget(edit);
    vBox->addWidget(dataLbl);
    vBox->addWidget(btn);
    vBox->addWidget(counterLbl);


    connect(btn, SIGNAL(clicked(bool)), this, SLOT(clicked(bool)));

}

Widget::~Widget() {}

void Widget::clicked(bool b) {
    QString url = edit->text();

    if (!url.isEmpty()) {

        if (
                (url.startsWith("http://") || url.startsWith("https://")) &&
                (url.endsWith(".fr") || url.endsWith(".com")
                 || url.endsWith(".org") || url.endsWith(".net")
                 || url.endsWith(".edu") || url.endsWith(".uk")
                 || url.endsWith(".fr/") || url.endsWith(".com/")
                 || url.endsWith(".org/") || url.endsWith(".net/")
                 || url.endsWith(".edu/") || url.endsWith(".uk/") )
                ) {
            counter++;

            QString s = QString(edit->text());
            dataLbl->setText(s);

            counterLbl->setText(QString("Counter: %1").arg(MAX-counter));

            QString str1 = QString("open %1").arg(edit->text());
            QByteArray ba = str1.toLocal8Bit();
            system(ba.data());

            if (counter == MAX) {
                btn->setEnabled(false);
                btn->setToolTip("No avalaible");
            }
        } else {
            QMessageBox msgBox;
            msgBox.setText("Url not valid");
            msgBox.exec();
        }

    } else {
        QMessageBox msgBox;
        msgBox.setText("Please to fill in");
        msgBox.exec();
    }



}
