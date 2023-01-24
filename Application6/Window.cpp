//
// Created by mendel bellaiche on 25/12/2022.
//

#include "Window.h"
#include <QGridLayout>

Window::Window(QWidget *parent, const Qt::WindowFlags &flags) : QMainWindow(parent, flags) {

    this->setWindowTitle("Qt Title");
    this->setMinimumSize(400, 300);
    this->setStyleSheet("background: #2B2B2B;");

}

Window::~Window() = default;