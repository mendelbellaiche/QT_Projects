//
// Created by mendel bellaiche on 06/12/2022.
//

#ifndef APPLICATION4_WINDOW_H
#define APPLICATION4_WINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Window : public QMainWindow {

    Q_OBJECT;

public:
    Window(QWidget *parent, const Qt::WindowFlags &flags);
    ~Window() override;
    void initUI();
    void initConnections();

private slots:
    void managerRequest(QString);
    void launchRequest();

private:
    QNetworkAccessManager *manager{};
    QNetworkRequest request;

    QPushButton *m_request;

    QLabel *m_fullnameLbl;
    QLabel *m_yearsLbl;
    QLabel *m_birthdayLbl;
    QLabel *m_emailLbl;
    QLabel *m_phoneLbl;

    QLineEdit *m_fullnameLineEdit;
    QLineEdit *m_yearsLineEdit;
    QLineEdit *m_birthdayLineEdit;
    QLineEdit *m_emailLineEdit;
    QLineEdit *m_phoneLineEdit;
};


#endif //APPLICATION4_WINDOW_H
