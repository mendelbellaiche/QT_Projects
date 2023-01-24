//
// Created by mendel bellaiche on 05/12/2022.
//

#include "MyWindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextBlock>
#include <QDateEdit>
#include <QInputDialog>
#include <QFileDialog>

MyWindow::MyWindow(QWidget *parent): QMainWindow(parent) {

    setWindowTitle("Flash Cards");
    resize(500, 400);

    initUI();
    initMenuBar();
    initConnections();

}

void MyWindow::initUI() {
    m_vbox = new QVBoxLayout();
    m_table = new QTableWidget(1, 2);

    QHeaderView *headerView = m_table->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

    auto *name = new QTableWidgetItem("Front");
    auto *email = new QTableWidgetItem("Back");

    QFont font = QFont();
    font.setBold(true);
    font.setFamily("Helvetica");
    font.setPointSize(14);
    font.setItalic(true);

    name->setFont(font);
    email->setFont(font);

    name->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    email->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    name->setTextAlignment(Qt::AlignCenter);
    email->setTextAlignment(Qt::AlignCenter);

    m_table->setItem(0, 0, name);
    m_table->setItem(0, 1, email);

    m_addPushButton = new QPushButton("Add");

    m_vbox->addWidget(m_table);
    m_vbox->addWidget(m_addPushButton);

    m_qWidget = new QWidget;
    m_qWidget->setLayout(m_vbox);
    setCentralWidget(m_qWidget);

}

void MyWindow::initConnections() {

    connect(m_addAction, SIGNAL(triggered(bool)), this, SLOT(addLine()));
    connect(m_saveAction, SIGNAL(triggered(bool)), this, SLOT(save()));
    connect(m_table, SIGNAL(cellChanged(int, int)), this, SLOT(cellChangedConnect(int, int)));
    connect(m_addPushButton, SIGNAL(clicked(bool)), this, SLOT(addLine()));

}

void MyWindow::initMenuBar() {
    m_menuBar = new QMenuBar();

    m_editMenu = new QMenu("Edit");

    m_addAction = new QAction("New line");
    m_addAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    m_editMenu->addAction(m_addAction);

    m_saveAction = new QAction("Save");
    m_saveAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    m_editMenu->addAction(m_saveAction);

    m_menuBar->addMenu(m_editMenu);

    setMenuBar(m_menuBar);
}

void MyWindow::cellChangedConnect(int r, int c) {
    auto *cell = m_table->item(r, c);
    cell->setTextAlignment(Qt::AlignCenter);
}

void MyWindow::addLine() {
    m_table->setRowCount(m_table->rowCount()+1);
}

void MyWindow::save() {

    if (m_table->rowCount() > 1) {
        QString filename = QFileDialog::getSaveFileName(this,
                                                        tr("Save file"),
                                                        "",
                                                        tr("Text File (*.txt);;CSV File (*.csv);;All Files (*)"));
        QFile f( filename );
        f.open( QIODevice::WriteOnly );

        for (int i=0; i < m_table->rowCount(); i++) {

            QByteArray ba1 = m_table->item(i, 0)->text().toLocal8Bit();
            char *c_str1 = ba1.data();
            f.write(c_str1);

            f.write(";");

            QByteArray ba2 = m_table->item(i, 1)->text().toLocal8Bit();
            char *c_str2 = ba2.data();
            f.write(c_str2);

            f.write("\n");

        }

        f.close();
    }

}

MyWindow::~MyWindow() = default;