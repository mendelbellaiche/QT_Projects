//
// Created by mendel bellaiche on 05/12/2022.
//

#ifndef APPLICATION2_MYWINDOW_H
#define APPLICATION2_MYWINDOW_H

#import <QWidget>
#import <QMainWindow>
#import <QVBoxLayout>
#import <QTableWidget>
#import <QPushButton>
#import <QMenuBar>
#import <QMenu>
#import <QHeaderView>

class MyWindow: public QMainWindow {

    Q_OBJECT

public:
    explicit MyWindow(QWidget *parent = nullptr);
    ~MyWindow() override;
    void initUI();
    void initConnections();
    void initMenuBar();

public slots:
    void addLine();
    void cellChangedConnect(int r, int c);
    void save();

private:
    QVBoxLayout *m_vbox{};
    QTableWidget *m_table{};
    QPushButton *m_addPushButton{};

    QMenuBar *m_menuBar{};
    QMenu *m_editMenu{};
    QAction *m_addAction{};
    QAction *m_saveAction{};

    QWidget* m_qWidget{};
};


#endif //APPLICATION2_MYWINDOW_H
