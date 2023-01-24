//
// Created by mendel bellaiche on 08/12/2022.
//

#include "Window.h"
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

Window::Window(QWidget *parent, const Qt::WindowFlags &flags) : QMainWindow(parent, flags) {
    initWindow();
    initWidgets();
    initConnections();
}

void Window::initWindow() {
    setWindowTitle("Application 5");
    resize(600, 500);
    setMinimumSize(500, 400);
}

void Window::initWidgets() {
    m_dataTextBlock = new QTextEdit();
    m_requestBtn = new QPushButton("Request");
    m_vBox = new QVBoxLayout();
    m_vBox->addWidget(m_dataTextBlock);
    m_vBox->addWidget(m_requestBtn);
    manager = new QNetworkAccessManager();
    auto *widget = new QWidget();
    widget->setLayout(m_vBox);
    setCentralWidget(widget);
}

void Window::initConnections() {
    connect(m_requestBtn, &QPushButton::clicked, this, &Window::launchRequest);
    QObject::connect(manager, &QNetworkAccessManager::finished, this,
         [=](QNetworkReply *reply) {
            if (reply->error()) { qDebug() << reply->errorString(); return; }
            this->managerRequest(reply->readAll());
        }
    );
}

Window::~Window() {
    delete manager;
}

void Window::managerRequest(const QString& answer) {
    QJsonDocument doc1 = QJsonDocument::fromJson(answer.toUtf8());
    if (!doc1.isObject()) {
        qDebug() << "Error...";
    }

    QJsonObject obj = doc1.object();
    QString value = obj["value"].toString();
    m_dataTextBlock->setText(value);

}

void Window::launchRequest() {
    request.setUrl(QUrl("https://matchilling-chuck-norris-jokes-v1.p.rapidapi.com/jokes/random"));
    request.setRawHeader("X-RapidAPI-Key", "f7db5e1a66msh0c599a35d52bd12p1fcd55jsn1f1fc3ed0dd0");
    request.setRawHeader("accept", "application/json");
    manager->get(request);
}
