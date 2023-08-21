#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    mainFrame = new MainFrame();
    menuBar = new QMenuBar(this);
    menu = new QMenu("File", this);

    menuBar->setFixedWidth(this->width());
    menuBar->setFixedHeight(25);
    menuBar->addMenu(menu);
    connect(this, SIGNAL(resized(int, int)), this, SLOT(slotMenuResize()));

    menu->addAction("Open file", this, SLOT(slotOpenFile()));

    setMinimumSize(WIDTH, HEIGHT);
    setCentralWidget(mainFrame);

    menuBar->raise();
}

MainWindow::~MainWindow() {}

void MainWindow::slotOpenFile() {
    mainFrame->fileName->clear();
    //    qDebug() << "--------------------->" << mainFrame->fileName;
    *(mainFrame->fileName) = QFileDialog::getOpenFileName(
        this, "Select file", "../references", "(*.obj)");

    mainFrame->createLists(mainFrame->fileName->toUtf8().constData());
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    QMainWindow::resizeEvent(event);
    emit resized(event->size().width(), event->size().height());
}

void MainWindow::slotMenuResize() { menuBar->setFixedWidth(width()); }
