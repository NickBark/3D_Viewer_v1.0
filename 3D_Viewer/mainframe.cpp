#include "mainframe.h"

MainFrame::MainFrame(QFrame* parent) : QFrame{parent} {
    list = new LinkedListVertex();
    poly = new LinkedListPolygon();

    fileName = new QString();
    glView = new GLView(this);

    //    createLists("../references/cat.obj");
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
        glView->createArrays(list, poly);
    }

    return ret;
}
