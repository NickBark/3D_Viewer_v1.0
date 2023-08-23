#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    Designer();
    Layouts();
    Properies();
    Connector();
    timerCounter = 0;
    gifWidth = 640;
    gifHeight = 480;
}

MainWindow::~MainWindow() {}

void MainWindow::Designer() {
    mainFrame = new MainFrame();
    menuBar = new QMenuBar(this);
    menu = new QMenu("File", this);
    recordMenu = new QMenu("Record", this);
    settings = new Settings();
    timer = new QTimer(this);
}

void MainWindow::Layouts() {}

void MainWindow::Properies() {
    menuBar->setFixedWidth(this->width());
    menuBar->setFixedHeight(25);
    menuBar->addMenu(menu);
    menuBar->addMenu(recordMenu);
    connect(this, SIGNAL(resized(int, int)), this, SLOT(slotMenuResize()));

    menu->addAction("Open file", this, SLOT(slotOpenFile()));
    menu->addAction("Settings", this, SLOT(slotOpenSettings()));

    recordMenu->addAction("Make screen *.jpeg", this, SLOT(slotMakeScreen()));
    recordMenu->addAction("Make screen *.bmp", this, SLOT(slotMakeScreen()));
    recordMenu->addAction("Make *.gif", this, SLOT(slotStartTimer()));
    //    recordMenu->addAction("Make screen *.bmp", this);

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

void MainWindow::slotMakeScreen() {
    QImage image = mainFrame->glView->grabFrameBuffer();
    QString fileName;
    fileName += "3D_Viewer_Screen_";
    fileName += QDate::currentDate().toString("yyyy-MM-dd");
    fileName += "_";
    fileName += QTime::currentTime().toString("hh:mm:ss");

    if (qobject_cast<QAction*>(sender()) == recordMenu->actions().at(0)) {
        fileName += ".jpeg";
        image.save(fileName, "JPEG", 85);
        qDebug() << fileName;
    } else if (qobject_cast<QAction*>(sender()) ==
               recordMenu->actions().at(1)) {
        fileName += ".bmp";
        image.save(fileName, "BMP");
        qDebug() << fileName;
    }
}

void MainWindow::slotStartTimer() {
    gif = new QGifImage(QSize(gifWidth, gifHeight));
    gif->setDefaultDelay(10);
    timer->start(100);
    connect(timer, &QTimer::timeout, this, &MainWindow::slotMakeGif);
}

void MainWindow::slotMakeGif() {
    QString fileName = "OPA2.gif";
    QImage image =
        mainFrame->glView->grabFrameBuffer().scaled(gifWidth, gifHeight);
    gif->addFrame(image);
    timerCounter++;
    if (timerCounter == 50) {
        timerCounter = 0;
        timer->stop();
        gif->save(fileName);
        delete gif;
    }
}
