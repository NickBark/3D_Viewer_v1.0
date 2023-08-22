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
    connect(settings->cdColorVertex, &QColorDialog::colorSelected,
            mainFrame->glView, &GLView::slotSetVertexColor);
    connect(settings->sbVertexSize,
            static_cast<void (QDoubleSpinBox::*)(double)>(
                &QDoubleSpinBox::valueChanged),
            mainFrame->glView, &GLView::slotVertexSize);
    connect(
        settings->cbVertexType,
        static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        mainFrame->glView, &GLView::slotSetVertexType);

    connect(settings->cdColorEdge, &QColorDialog::colorSelected,
            mainFrame->glView, &GLView::slotSetEdgeColor);
    connect(settings->sbEdgeSize,
            static_cast<void (QDoubleSpinBox::*)(double)>(
                &QDoubleSpinBox::valueChanged),
            mainFrame->glView, &GLView::slotEdgeWidth);
    connect(
        settings->cbEdgeType,
        static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        mainFrame->glView, &GLView::slotSetEdgeType);

    connect(settings->cdColorBack, &QColorDialog::colorSelected,
            mainFrame->glView, &GLView::slotSetBackgroundColor);

    connect(
        settings->cbProjection,
        static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        mainFrame->glView, &GLView::slotSetProjection);
}

void MainWindow::slotOpenFile() {
    mainFrame->fileName->clear();
    *(mainFrame->fileName) = QFileDialog::getOpenFileName(
        this, "Select file", "../references", "(*.obj)");
    if (!mainFrame->fileName->isEmpty())
        mainFrame->createLists(mainFrame->fileName->toUtf8().constData());
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    QMainWindow::resizeEvent(event);
    emit resized(event->size().width(), event->size().height());
}

void MainWindow::slotMenuResize() { menuBar->setFixedWidth(width()); }

void MainWindow::slotOpenSettings() {
    settings->hide();
    settings->show();
}
