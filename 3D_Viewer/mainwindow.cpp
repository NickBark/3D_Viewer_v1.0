#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    Designer();
    Layouts();
    Properies();
    Connector();
}

MainWindow::~MainWindow() {}

void MainWindow::Designer() {
    mainFrame = new MainFrame();
    menuBar = new QMenuBar(this);
    menu = new QMenu("File", this);
    settings = new Settings();
}

void MainWindow::Layouts() {}

void MainWindow::Properies() {
    menuBar->setFixedWidth(this->width());
    menuBar->setFixedHeight(25);
    menuBar->addMenu(menu);
    connect(this, SIGNAL(resized(int, int)), this, SLOT(slotMenuResize()));

    menu->addAction("Open file", this, SLOT(slotOpenFile()));
    menu->addAction("Settings", this, SLOT(slotOpenSettings()));

    setMinimumSize(WIDTH, HEIGHT);
    setWindowTitle("3D Viewer");
    setCentralWidget(mainFrame);

    menuBar->raise();
}

void MainWindow::Connector() {
    //    connect(settings->sVertexRed, &QSlider::valueChanged,
    //    mainFrame->glView,
    //            [=](int value) {
    //                mainFrame->glView->slotSetVertexSettings(value, "Red");
    //            });
    //    connect(settings->sVertexGreen, &QSlider::valueChanged,
    //    mainFrame->glView,
    //            [=](int value) {
    //                mainFrame->glView->slotSetVertexSettings(value, "Green");
    //            });
    //    connect(settings->sVertexBlue, &QSlider::valueChanged,
    //    mainFrame->glView,
    //            [=](int value) {
    //                mainFrame->glView->slotSetVertexSettings(value, "Blue");
    //            });

    connect(settings->cdColorVertex, &QColorDialog::colorSelected,
            mainFrame->glView, &GLView::slotSetVertexColor);
}

void MainWindow::slotOpenFile() {
    mainFrame->fileName->clear();
    *(mainFrame->fileName) = QFileDialog::getOpenFileName(
        this, "Select file", "../references", "(*.obj)");

    mainFrame->createLists(mainFrame->fileName->toUtf8().constData());
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    QMainWindow::resizeEvent(event);
    emit resized(event->size().width(), event->size().height());
}

void MainWindow::slotMenuResize() { menuBar->setFixedWidth(width()); }

void MainWindow::slotOpenSettings() { settings->show(); }
