#include "glview.h"

GLView::GLView(QWidget* parent, LinkedListVertex* vertexList,
               LinkedListPolygon* polyList)
    : QGLWidget{parent} {
    setGeometry(10, 35, 600, 400);
    int n = vertexList->vertexCount * 3;
    arr = new double[n];
    for (int i = 0, j = 1; j <= vertexList->vertexCount;) {
        arr[i++] = findVertex(vertexList, j)->x;
        arr[i++] = findVertex(vertexList, j)->y;
        arr[i++] = findVertex(vertexList, j)->z;
        j++;
    }
    for (int i = 0; i < n; i++) {
        qDebug() << arr[i];
    }
}

GLView::~GLView() {}

void GLView::initializeGL() {
    glEnable(GL_DEPTH_TEST);
    ;
}

void GLView::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //    glOrtho(-1, 1, -1, 1, 1, 2);
    glFrustum(-1, 1, -1, 1, 1, 2);
}

void GLView::paintGL() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //    glVertexPointer(3, GL_FLOAT, 0, arr);
    //    glEnableClientState(GL_VERTEX_ARRAY);
    //    glColor3d(1, 0, 0);
    //    glDrawArrays(GL_LINES, 0, 3);
    //    glDisableClientState(GL_VERTEX_ARRAY);
}
