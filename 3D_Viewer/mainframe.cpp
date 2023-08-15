#include "mainframe.h"

MainFrame::MainFrame(QFrame *parent) : QFrame{parent} {
    if (!createLists())
        glView = new GLView(this, list, poly);
    else
        qDebug() << "Can't read file";
}

int MainFrame::createLists() {
    int ret = 0;
    list = new LinkedListVertex();
    poly = new LinkedListPolygon();

    poly->head = NULL;
    poly->tail = NULL;
    poly->current = NULL;
    poly->polygonCount = 0;

    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
    list->vertexCount = 0;

    if (readFile("../references/cat.obj", list, poly)) {
        qDebug() << "ERROR";
        ret = 1;
    } else {
        qDebug() << "SUCCESS";
        //        qDebug() << findVertex(list, 35290)->x;
        //        qDebug() << findVertex(list, 35290)->y;
        //        qDebug() << findVertex(list, 35290)->z;
        //        printPolyList(poly);
    }

    //    while (!vertexPop(list)) {
    //    }

    //    while (!polyPop(poly)) {
    //    }

    //    delete list;
    //    delete poly;
    return ret;
}
