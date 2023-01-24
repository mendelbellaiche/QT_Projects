//
// Created by mendel bellaiche on 06/12/2022.
//

#include "Window.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QtPrintSupport/QtPrintSupport>
#include <QLabel>
#include <QPushButton>

Window::Window(QWidget *parent, const Qt::WindowFlags &flags) : QMainWindow(parent, flags) {

    initWindow();
    initMenuBar();
    initWidgets();
    initConnections();
    initStyles();

}

void Window::initWindow() {

    setWindowTitle("Editor");
    resize(500, 400);
    setMinimumSize(400, 300);

}

void Window::initMenuBar() {
    m_menuBar = new QMenuBar();
    m_fileMenu = new QMenu("File");
    m_newAction = new QAction("New");
    m_openAction = new QAction("Open");
    m_saveAction = new QAction("Save");
    m_saveAsAction = new QAction("Save As");
    m_printAction = new QAction("Print");

    m_newAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    m_openAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    m_saveAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    m_saveAsAction->setShortcut(QKeySequence("Ctrl+Shift+S"));
    m_printAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_P));

    m_fileMenu->addAction(m_newAction);
    m_fileMenu->addAction(m_openAction);
    m_fileMenu->addAction(m_saveAction);
    m_fileMenu->addAction(m_saveAsAction);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_printAction);

    m_menuBar->addMenu(m_fileMenu);

    setMenuBar(m_menuBar);

}

void Window::initWidgets() {
    auto *vBox = new QVBoxLayout();

    m_textBlock = new QTextEdit();

    vBox->addWidget(m_textBlock);

    m_qWidget = new QWidget;
    m_qWidget->setLayout(vBox);
    setCentralWidget(m_qWidget);

}

void Window::initConnections() {
    // OLD
    // connect(m_newAction, SIGNAL(triggered(bool)), this, SLOT(newFile()));
    // connect(m_openAction, SIGNAL(triggered(bool)), this, SLOT(openFile()));
    // connect(m_saveAction, SIGNAL(triggered(bool)), this, SLOT(saveFile()));
    // connect(m_saveAsAction, SIGNAL(triggered(bool)), this, SLOT(saveAsFile()));
    // connect(m_printAction, SIGNAL(triggered(bool)), this, SLOT(printFile()));

    // NEW
    connect(m_newAction, &QAction::triggered, this, &Window::newFile);
    connect(m_openAction, &QAction::triggered, this, &Window::openFile);
    connect(m_saveAction, &QAction::triggered, this, &Window::saveFile);
    connect(m_saveAsAction, &QAction::triggered, this, &Window::saveAsFile);
    connect(m_printAction, &QAction::triggered, this, &Window::printFile);

    /* connect(m_newAction, &QAction::triggered, this,
        [this](bool) {
        this->newFile();
    }); */


}

void Window::newFile() {
    m_textBlock->setText("");
}

void Window::openFile() {

    m_filename = QFileDialog::getOpenFileName(this, tr("Open Text File"), "", tr("All Files (*)"));
    QFile file(m_filename);

    file.open(QIODeviceBase::ReadOnly);
    if (file.isOpen()) {
        m_textBlock->setText(file.readAll());
    }

    file.close();
}

void Window::saveFile() {
    if (m_filename == nullptr) {
        m_filename = QFileDialog::getSaveFileName(this,
                                                  tr("Save file"),
                                                  "",
                                                  tr("Text File (*.txt);;All Files (*)"));
        m_filenameBfr = m_filename;
    }

    QByteArray ba1 = m_textBlock->toPlainText().toLocal8Bit(); // m_table->item(i, 0)->text().toLocal8Bit();
    char *contentBlock = ba1.data();

    QFile f( m_filename );
    f.open( QIODevice::WriteOnly );
    f.write(contentBlock);
    f.close();

}

void Window::saveAsFile() {
    m_filename = QFileDialog::getSaveFileName(this,
                                              tr("Save file"),
                                              "",
                                              tr("Text File (*.txt);;All Files (*)"));

    QByteArray ba1 = m_textBlock->toPlainText().toLocal8Bit(); // m_table->item(i, 0)->text().toLocal8Bit();
    char *contentBlock = ba1.data();

    QFile f( m_filename );
    f.open( QIODevice::WriteOnly );
    f.write(contentBlock);
    f.close();

    if (m_filename == nullptr) {
        m_filename = m_filenameBfr;
    }


}

void Window::initStyles() {
    this->setStyleSheet("background-color: black;");
    this->m_textBlock->setStyleSheet("color: white; background-color: #222222;");
}

void Window::printFile() {
    QPrinter printer;
    auto printDialog = QPrintDialog(&printer, this);
    printDialog.setWindowTitle("Print");
    if (printDialog.exec() == QDialog::Accepted) {
        this->m_textBlock->print(&printer);
    }

}

Window::~Window() = default;
