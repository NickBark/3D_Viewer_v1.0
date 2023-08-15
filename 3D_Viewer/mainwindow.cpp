#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    mainFrame = new MainFrame();
    menuBar = new QMenuBar(this);
    menu = new QMenu("File", this);

    menuBar->setMinimumWidth(WIDTH);
    menuBar->setFixedHeight(25);
    menuBar->addMenu(menu);

    setMinimumSize(WIDTH, HEIGHT);
    setCentralWidget(mainFrame);

    menuBar->raise();
}

MainWindow::~MainWindow() {}
