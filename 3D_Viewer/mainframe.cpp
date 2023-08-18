#include "mainframe.h"

MainFrame::MainFrame(QFrame* parent) : QFrame{parent} {
    //    createLists("../references/cat.obj");
    Designer();
    Properies();
    Layouts();
    Connector();
}

int MainFrame::createLists(const char* fileName) {
    while (!vertexPop(list)) {
    }

    while (!polyPop(poly)) {
    }

    poly->head = NULL;
    poly->tail = NULL;
    poly->current = NULL;
    poly->polygonCount = 0;
    poly->numOfIndex = 0;

    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
    list->vertexCount = 0;

    int ret = 0;

    if (readFile(fileName, list, poly)) {
        qDebug() << "ERROR";
        ret = 1;
    } else {
        qDebug() << "SUCCESS";
        //        numOfEdges = list->vertexCount + poly->polygonCount - 2;
        //        qDebug() << "EDGES: " << numOfEdges;
        glView->createArrays(list, poly);
    }

    return ret;
}

void MainFrame::Designer() {
    list = new LinkedListVertex();
    poly = new LinkedListPolygon();

    fileName = new QString();
    glView = new GLView(this);
    cPanel = new ControlPanel(this);

    vbl = new QVBoxLayout(this);
    hbl = new QHBoxLayout(this);
}

void MainFrame::Layouts() {
    setLayout(vbl);
    vbl->addLayout(hbl);
    hbl->addWidget(glView, 4);
    hbl->addWidget(cPanel, 1);
}

void MainFrame::Properies() { vbl->setContentsMargins(10, 30, 10, 10); }

void MainFrame::Connector() {
    connect(cPanel->pbMoveLeftX, SIGNAL(pressed()), this, SLOT(slotMove()));
    connect(cPanel->pbMoveRightX, SIGNAL(pressed()), this, SLOT(slotMove()));
    connect(cPanel->pbMoveLeftY, SIGNAL(pressed()), this, SLOT(slotMove()));
    connect(cPanel->pbMoveRightY, SIGNAL(pressed()), this, SLOT(slotMove()));
    connect(cPanel->pbMoveLeftZ, SIGNAL(pressed()), this, SLOT(slotMove()));
    connect(cPanel->pbMoveRightZ, SIGNAL(pressed()), this, SLOT(slotMove()));

    connect(cPanel->pbRotateLeftX, SIGNAL(pressed()), this, SLOT(slotRotate()));
    connect(cPanel->pbRotateRightX, SIGNAL(pressed()), this,
            SLOT(slotRotate()));
    connect(cPanel->pbRotateLeftY, SIGNAL(pressed()), this, SLOT(slotRotate()));
    connect(cPanel->pbRotateRightY, SIGNAL(pressed()), this,
            SLOT(slotRotate()));
    connect(cPanel->pbRotateLeftZ, SIGNAL(pressed()), this, SLOT(slotRotate()));
    connect(cPanel->pbRotateRightZ, SIGNAL(pressed()), this,
            SLOT(slotRotate()));

    connect(cPanel->pbScaleLeftX, SIGNAL(pressed()), this, SLOT(slotScale()));
    connect(cPanel->pbScaleRightX, SIGNAL(pressed()), this, SLOT(slotScale()));
    connect(cPanel->pbScaleLeftY, SIGNAL(pressed()), this, SLOT(slotScale()));
    connect(cPanel->pbScaleRightY, SIGNAL(pressed()), this, SLOT(slotScale()));
    connect(cPanel->pbScaleLeftZ, SIGNAL(pressed()), this, SLOT(slotScale()));
    connect(cPanel->pbScaleRightZ, SIGNAL(pressed()), this, SLOT(slotScale()));
}

void MainFrame::slotMove() {
    if (list && list->head) {
        if (sender() == cPanel->pbMoveLeftX)
            s21_move(list, -cPanel->dsbMoveXVal->value(), 0, 0);
        else if (sender() == cPanel->pbMoveRightX)
            s21_move(list, cPanel->dsbMoveXVal->value(), 0, 0);
        else if (sender() == cPanel->pbMoveLeftY)
            s21_move(list, 0, -cPanel->dsbMoveYVal->value(), 0);
        else if (sender() == cPanel->pbMoveRightY)
            s21_move(list, 0, cPanel->dsbMoveYVal->value(), 0);
        else if (sender() == cPanel->pbMoveLeftZ)
            s21_move(list, 0, 0, -cPanel->dsbMoveZVal->value());
        else if (sender() == cPanel->pbMoveRightZ)
            s21_move(list, 0, 0, cPanel->dsbMoveZVal->value());

        glView->createArrays(list, poly);
    }
}

void MainFrame::slotRotate() {
    if (list && list->head) {
        if (sender() == cPanel->pbRotateLeftX)
            s21_rotate(list, cPanel->dsbRotateXVal->value(), 'X', 'L');
        else if (sender() == cPanel->pbRotateRightX)
            s21_rotate(list, cPanel->dsbRotateXVal->value(), 'X', 'R');
        else if (sender() == cPanel->pbRotateLeftY)
            s21_rotate(list, cPanel->dsbRotateYVal->value(), 'Y', 'L');
        else if (sender() == cPanel->pbRotateRightY)
            s21_rotate(list, cPanel->dsbRotateYVal->value(), 'Y', 'R');
        else if (sender() == cPanel->pbRotateLeftZ)
            s21_rotate(list, cPanel->dsbRotateZVal->value(), 'Z', 'L');
        else if (sender() == cPanel->pbRotateRightZ)
            s21_rotate(list, cPanel->dsbRotateZVal->value(), 'Z', 'R');

        glView->createArrays(list, poly);
    }
}

void MainFrame::slotScale() {}
