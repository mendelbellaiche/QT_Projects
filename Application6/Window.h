//
// Created by mendel bellaiche on 25/12/2022.
//

#ifndef APPLICATION6_WINDOW_H
#define APPLICATION6_WINDOW_H

#include <QMainWindow>
#include <QWidget>

class Window: public QMainWindow {

    Q_OBJECT

    public:

        Window(QWidget *parent, const Qt::WindowFlags &flags);
        ~Window() override;


};


#endif //APPLICATION6_WINDOW_H
