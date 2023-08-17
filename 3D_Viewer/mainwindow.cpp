#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    mainFrame = new MainFrame();
    menuBar = new QMenuBar(this);
    menu = new QMenu("File", this);

    menuBar->setMinimumWidth(WIDTH);
    menuBar->setFixedHeight(25);
    menuBar->addMenu(menu);

    menu->addAction("Open file", this, SLOT(slotOpenFile()));

    setMinimumSize(WIDTH, HEIGHT);
    setCentralWidget(mainFrame);

    menuBar->raise();
}

MainWindow::~MainWindow() {}

void MainWindow::slotOpenFile() {
    mainFrame->fileName->clear();

    *(mainFrame->fileName) = QFileDialog::getOpenFileName(
        this, "Select file", "../references", "(*.obj)");

    mainFrame->createLists(mainFrame->fileName->toUtf8().constData());
}
