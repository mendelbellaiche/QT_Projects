//
// Created by mendel bellaiche on 06/12/2022.
//

#include "Window.h"
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>

Window::Window(QWidget *parent, const Qt::WindowFlags &flags) : QMainWindow(parent, flags) {

    initUI();
    initConnections();

}

Window::~Window() {
    delete manager;
}

void Window::managerRequest(QString answer) {
    QJsonDocument doc1 = QJsonDocument::fromJson(answer.toUtf8());
    if (!doc1.isObject()) {
        qDebug() << "Error...";
    }

    QJsonObject obj = doc1.object();
    QJsonArray array = doc1["results"].toArray();
    QJsonObject userObj = array[0].toObject();

    QJsonObject dobObj = userObj["dob"].toObject();
    int dobAge = dobObj["age"].toInt();
    QString dobDate = dobObj["date"].toString();

    QString email = userObj["email"].toString();
    QString phone = userObj["phone"].toString();

    QJsonObject nameObj = userObj["name"].toObject();
    QString nameTitle = nameObj["title"].toString();
    QString nameFirst = nameObj["first"].toString();
    QString nameLast = nameObj["last"].toString();

    m_fullnameLineEdit->setText(QString("%1 %2 %3").arg(nameTitle, nameFirst, nameLast));
    m_yearsLineEdit->setText(QString("%1 yo").arg(dobAge));
    m_birthdayLineEdit->setText(dobDate);
    m_emailLineEdit->setText(email);
    m_phoneLineEdit->setText(phone);
}

void Window::launchRequest() {
    request.setUrl(QUrl("https://randomuser.me/api"));
    manager->get(request);
}

void Window::initUI() {
    setWindowTitle("Random User");
    resize(500, 400);
    setMinimumSize(500, 400);
    setMaximumSize(500, 400);

    m_fullnameLbl = new QLabel("Fullname:");
    m_yearsLbl = new QLabel("Age:");
    m_birthdayLbl = new QLabel("Birthday:");
    m_emailLbl = new QLabel("Email:");
    m_phoneLbl = new QLabel("Phone:");

    m_fullnameLineEdit = new QLineEdit();
    m_yearsLineEdit = new QLineEdit();
    m_birthdayLineEdit = new QLineEdit();
    m_emailLineEdit = new QLineEdit();
    m_phoneLineEdit = new QLineEdit();
    m_request = new QPushButton("Send Request");
    manager = new QNetworkAccessManager();

    QHBoxLayout *hBox1 = new QHBoxLayout();
    QHBoxLayout *hBox2 = new QHBoxLayout();
    QHBoxLayout *hBox3 = new QHBoxLayout();
    QHBoxLayout *hBox4 = new QHBoxLayout();
    QHBoxLayout *hBox5 = new QHBoxLayout();

    QVBoxLayout *vBox = new QVBoxLayout();

    m_fullnameLbl->setFixedWidth(100);
    m_yearsLbl->setFixedWidth(100);
    m_birthdayLbl->setFixedWidth(100);
    m_emailLbl->setFixedWidth(100);
    m_phoneLbl->setFixedWidth(100);

    m_fullnameLbl->setAlignment(Qt::AlignLeft);
    m_yearsLbl->setAlignment(Qt::AlignLeft);
    m_birthdayLbl->setAlignment(Qt::AlignLeft);
    m_emailLbl->setAlignment(Qt::AlignLeft);
    m_phoneLbl->setAlignment(Qt::AlignLeft);

    hBox1->addWidget(m_fullnameLbl);
    hBox1->addWidget(m_fullnameLineEdit);

    hBox2->addWidget(m_yearsLbl);
    hBox2->addWidget(m_yearsLineEdit);

    hBox3->addWidget(m_birthdayLbl);
    hBox3->addWidget(m_birthdayLineEdit);

    hBox4->addWidget(m_emailLbl);
    hBox4->addWidget(m_emailLineEdit);

    hBox5->addWidget(m_phoneLbl);
    hBox5->addWidget(m_phoneLineEdit);

    vBox->addLayout(hBox1);
    vBox->addLayout(hBox2);
    vBox->addLayout(hBox3);
    vBox->addLayout(hBox4);
    vBox->addLayout(hBox5);

    vBox->addWidget(m_request);

    m_request->setStyleSheet("background-color: #036; color: #FFFFFF; border-radius: 6px;");
    m_request->setFixedHeight(35);
    m_request->setFont(QFont("Helvetica", 14));

    m_fullnameLbl->setFixedHeight(35);
    m_fullnameLbl->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    m_fullnameLineEdit->setFixedHeight(35);
    m_fullnameLineEdit->setStyleSheet("padding-left: 5px; padding-right: 5px; border-radius: 6px;");

    m_yearsLbl->setFixedHeight(35);
    m_yearsLbl->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    m_yearsLineEdit->setFixedHeight(35);
    m_yearsLineEdit->setStyleSheet("padding-left: 5px; padding-right: 5px; border-radius: 6px;");

    m_birthdayLbl->setFixedHeight(35);
    m_birthdayLbl->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    m_birthdayLineEdit->setFixedHeight(35);
    m_birthdayLineEdit->setStyleSheet("padding-left: 5px; padding-right: 5px; border-radius: 6px;");

    m_emailLbl->setFixedHeight(35);
    m_emailLbl->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    m_emailLineEdit->setFixedHeight(35);
    m_emailLineEdit->setStyleSheet("padding-left: 5px; padding-right: 5px; border-radius: 6px;");

    m_phoneLbl->setFixedHeight(35);
    m_phoneLbl->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    m_phoneLineEdit->setFixedHeight(35);
    m_phoneLineEdit->setStyleSheet("padding-left: 5px; padding-right: 5px; border-radius: 6px;");

    QWidget *widget = new QWidget();
    widget->setLayout(vBox);
    setCentralWidget(widget);
}

void Window::initConnections() {
    connect(m_request, &QPushButton::clicked, this, &Window::launchRequest);
    QObject::connect(manager, &QNetworkAccessManager::finished,
                     this, [=](QNetworkReply *reply) {
                if (reply->error()) {
                    qDebug() << reply->errorString();
                    return;
                }

                // QString answer = reply->readAll();

                this->managerRequest(reply->readAll());

            }
    );
}

