//
// Created by mendel bellaiche on 06/12/2022.
//

#ifndef APPLICATION3_WINDOW_H
#define APPLICATION3_WINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QString>
#include <QTextEdit>


class Window: public QMainWindow {

    Q_OBJECT;

public:

    Window(QWidget *parent, const Qt::WindowFlags &flags);
    ~Window() override;
    void initWindow();
    void initMenuBar();
    void initWidgets();
    void initConnections();
    void initStyles();


public slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveAsFile();
    void printFile();

private:
    QWidget *m_qWidget{};
    QMenuBar *m_menuBar{};
    QMenu *m_fileMenu{};
    QAction *m_newAction{};
    QAction *m_openAction{};
    QAction *m_saveAction{};
    QAction *m_saveAsAction{};
    QAction *m_printAction{};
    QTextEdit *m_textBlock{};

    QString m_filename;
    QString m_filenameBfr;
};


#endif //APPLICATION3_WINDOW_H
