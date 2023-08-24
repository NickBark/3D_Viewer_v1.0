#include "mainframe.h"

MainFrame::MainFrame(QFrame* parent) : QFrame{parent} {
    Designer();
    Properies();
    Layouts();
    Connector();
}

MainFrame::~MainFrame() {
    while (!vertexPop(list)) {
    }

    while (!polyPop(poly)) {
    }

    delete list;
    delete poly;
    delete fileName;
    qDebug() << "FREE MAIN_FRAME";
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
        QString info;

        //        numOfEdges = list->vertexCount + poly->polygonCount - 2;
        //        qDebug() << "EDGES: " << numOfEdges;

        glView->createArrays(list, poly);
        glView->maxCoord = glView->foundMax(list);

        info += "Model Name: ";
        info += fileName;
        info += "\nVertex count: ";
        info += QString::number(list->vertexCount);
        info += "\nEdge count: ";
        info += QString::number(uniqueEdges());

        //        qDebug() << "Euler: " << list->vertexCount +
        //        poly->polygonCount - 2;

        lInfoModel->setText(info);
        glView->updateGL();

        //        glView->MoveCamera();
    }

    return ret;
}

int MainFrame::uniqueEdges() {
    set<Edge> uniqueEdges;
    Polygon* current;
    for (int i = 1; i <= poly->polygonCount; i++) {
        current = findPoly(poly, i);
        for (int j = 0; j < current->numOfElem; j++) {
            int v1 = current->pointArr[j];
            int v2 = current->pointArr[(j + 1) % current->numOfElem];
            uniqueEdges.insert(Edge(v1, v2));
        }
    }
    return uniqueEdges.size();
}

void MainFrame::Designer() {
    list = new LinkedListVertex();
    poly = new LinkedListPolygon();

    fileName = new QString();
    glView = new GLView(this);
    cPanel = new ControlPanel(this);

    vbl = new QVBoxLayout(this);
    hbl = new QHBoxLayout(this);

    lInfoModel = new QLabel(this);
}

void MainFrame::Layouts() {
    setLayout(vbl);
    vbl->addLayout(hbl, 9);
    hbl->addWidget(glView, 4);
    hbl->addWidget(cPanel, 1);

    vbl->addWidget(lInfoModel, 1);
}

void MainFrame::Properies() { vbl->setContentsMargins(10, 30, 10, 10); }

void MainFrame::Connector() {
    connect(cPanel->pbMoveLeftX, SIGNAL(clicked(bool)), this, SLOT(slotMove()));
    connect(cPanel->pbMoveRightX, SIGNAL(clicked(bool)), this,
            SLOT(slotMove()));
    connect(cPanel->pbMoveLeftY, SIGNAL(clicked(bool)), this, SLOT(slotMove()));
    connect(cPanel->pbMoveRightY, SIGNAL(clicked(bool)), this,
            SLOT(slotMove()));
    connect(cPanel->pbMoveLeftZ, SIGNAL(clicked(bool)), this, SLOT(slotMove()));
    connect(cPanel->pbMoveRightZ, SIGNAL(clicked(bool)), this,
            SLOT(slotMove()));

    connect(cPanel->pbRotateLeftX, SIGNAL(clicked(bool)), this,
            SLOT(slotRotate()));
    connect(cPanel->pbRotateRightX, SIGNAL(clicked(bool)), this,
            SLOT(slotRotate()));
    connect(cPanel->pbRotateLeftY, SIGNAL(clicked(bool)), this,
            SLOT(slotRotate()));
    connect(cPanel->pbRotateRightY, SIGNAL(clicked(bool)), this,
            SLOT(slotRotate()));
    connect(cPanel->pbRotateLeftZ, SIGNAL(clicked(bool)), this,
            SLOT(slotRotate()));
    connect(cPanel->pbRotateRightZ, SIGNAL(clicked(bool)), this,
            SLOT(slotRotate()));

    connect(cPanel->pbScaleLeftX, SIGNAL(clicked(bool)), this,
            SLOT(slotScale()));
    connect(cPanel->pbScaleRightX, SIGNAL(clicked(bool)), this,
            SLOT(slotScale()));
    connect(cPanel->pbScaleLeftY, SIGNAL(clicked(bool)), this,
            SLOT(slotScale()));
    connect(cPanel->pbScaleRightY, SIGNAL(clicked(bool)), this,
            SLOT(slotScale()));
    connect(cPanel->pbScaleLeftZ, SIGNAL(clicked(bool)), this,
            SLOT(slotScale()));
    connect(cPanel->pbScaleRightZ, SIGNAL(clicked(bool)), this,
            SLOT(slotScale()));

    connect(cPanel->cbShowAxis, SIGNAL(stateChanged(int)), glView,
            SLOT(slotStateOfAxis()));
    connect(cPanel->pbHome, SIGNAL(clicked(bool)), glView, SLOT(slotHome()));
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

void MainFrame::slotScale() {
    if (list && list->head) {
        if (sender() == cPanel->pbScaleLeftX)
            s21_scale(list, 1.0 / cPanel->dsbScaleXVal->value(), 1, 1);
        else if (sender() == cPanel->pbScaleRightX)
            s21_scale(list, cPanel->dsbScaleXVal->value(), 1, 1);
        else if (sender() == cPanel->pbScaleLeftY)
            s21_scale(list, 1, 1.0 / cPanel->dsbScaleYVal->value(), 1);
        else if (sender() == cPanel->pbScaleRightY)
            s21_scale(list, 1, cPanel->dsbScaleYVal->value(), 1);
        else if (sender() == cPanel->pbScaleLeftZ)
            s21_scale(list, 1, 1, 1.0 / cPanel->dsbScaleZVal->value());
        else if (sender() == cPanel->pbScaleRightZ)
            s21_scale(list, 1, 1, cPanel->dsbScaleZVal->value());

        glView->createArrays(list, poly);
    }
}
