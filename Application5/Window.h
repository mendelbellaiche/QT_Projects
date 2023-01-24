//
// Created by mendel bellaiche on 08/12/2022.
//

#ifndef APPLICATION5_WINDOW_H
#define APPLICATION5_WINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSslSocket>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>

class Window: public QMainWindow {

    Q_OBJECT;

    public:
        Window(QWidget *parent, const Qt::WindowFlags &flags);
        ~Window() override;
        void initWindow();
        void initWidgets();
        void initConnections();

    public slots:
        void managerRequest(const QString&);
        void launchRequest();

    private:
        QTextEdit *m_dataTextBlock{};
        QPushButton *m_requestBtn{};
        QVBoxLayout *m_vBox{};

        QNetworkAccessManager *manager{};
        QNetworkRequest request;

};


#endif //APPLICATION5_WINDOW_H
