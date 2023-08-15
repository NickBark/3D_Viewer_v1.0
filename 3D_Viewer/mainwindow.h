#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dependencies.hpp"
#include "mainframe.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    QMenuBar* menuBar;
    QMenu* menu;
    MainFrame* mainFrame;
};
#endif  // MAINWINDOW_H
