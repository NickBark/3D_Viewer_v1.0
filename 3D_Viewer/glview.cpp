#include "glview.h"

// не забыть очистить память массивов и списков
// при очистке памяти массивов происходит вылет в некоторых случаях

GLView::GLView(QWidget* parent) : QGLWidget{parent} {
    setGeometry(10, 35, 600, 400);
    maxCoord = 100;
    minCoord = 100;
    vertexArr = NULL;
    polyArr = NULL;
    vertexCount = 0;
    polyArrNum = 0;
    pVertexList = NULL;
    pPolyList = NULL;
}

void GLView::createArrays(LinkedListVertex* vertexList,
                          LinkedListPolygon* polyList) {
    pVertexList = vertexList;
    pPolyList = polyList;
    //    if (vertexArr) delete[] vertexArr;
    //    if (polyArr) delete[] polyArr;
    vertexArr = createVertexArr(pVertexList);
    polyArr = createPolyArr(pPolyList);
    //    minCoord = foundMin(vertexArr);
    maxCoord = foundMax(vertexArr);

    vertexCount = pVertexList->vertexCount;

    updateGL();
}

// void GLView::createConnectVertexArray(){
//     for(int i = 1; i < pPolyList
// }

GLView::~GLView() {}

void GLView::initializeGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    //    glEnable(GL_CULL_FACE); // отсечение задних граней
}

void GLView::resizeGL(int w, int h) {
    //    float aspect = w / (float)h;
    //    m_projectionMatrix.setToIdentity();
    //    m_projectionMatrix.perspective(45, aspect, 0.1f, 10.0f);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //    glOrtho(-1, 1, -1, 1, 1, 2);

    glFrustum(-1, 1, -1, 1, 1, 500.0);
}
// double ppp[] = {0, 0, 0,  0, 1, 0,  1, 1, 0,  1, 0, 0,    //
//                 0, 0, -2, 0, 1, -2, 1, 1, -2, 1, 0, -2};  //

// GLubyte indices[] = {0, 1, 2, 3,         // 36 of indices
//                      0, 3, 4, 4,         //
//                      0, 5, 6, 6, 1, 0,   //
//                      1, 6, 7, 7, 2, 1,   //
//                      7, 4, 3, 3, 2, 7,   //
//                      4, 7, 6, 6, 5, 4};  //
void GLView::paintGL() {
    //    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();

    glTranslatef(0 + xMove / 25, 0 + yMove / 25, -50.0f);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);

    if (pPolyList && pVertexList) {
        drawVertex();
        //        drawPolygons();
    }

    glPopMatrix();
}

void GLView::drawVertex() {
    glVertexPointer(3, GL_DOUBLE, 0, vertexArr);
    glEnableClientState(GL_VERTEX_ARRAY);
    glPointSize(2);
    glColor3d(0, 0, 1);
    glDrawArrays(GL_POINTS, 0, pVertexList->vertexCount);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void GLView::drawPolygons() {
    glEnableClientState(GL_VERTEX_ARRAY);

    glColor3d(1, 0, 0);
    glVertexPointer(3, GL_DOUBLE, 0, vertexArr);

    glDrawArrays(GL_LINE_STRIP, 0, 4);

    //    glColor3d(1, 0, 0);
    //    glDrawRangeElements(GL_LINE, 0, 4, polyArrNum, GL_UNSIGNED_INT,
    //    polyArr);

    glDisableClientState(GL_VERTEX_ARRAY);
}

double* GLView::createVertexArr(LinkedListVertex* list) {
    vertexArrNum = list->vertexCount * 3;
    double* arr = new double[vertexArrNum];
    Vertex* current = NULL;
    for (int i = 0, j = 1; j <= list->vertexCount;) {
        current = findVertex(list, j);
        if (current) {
            arr[i++] = current->x;
            arr[i++] = current->y;
            arr[i++] = current->z;
        }
        j++;
    }
    qDebug() << "SUCCESS CREATE ARR VERTEX";
    return arr;
}

unsigned int* GLView::createPolyArr(LinkedListPolygon* list) {
    polyArrNum = 0;
    for (int i = 1; i <= list->polygonCount; i++) {
        polyArrNum += findPoly(list, i)->numOfElem;
        //        qDebug() << polyArrNum;
    }
    //    qDebug() << "poly arr num: " << polyArrNum;

    unsigned int* arr = new unsigned int[polyArrNum];

    Polygon* current = NULL;
    for (int i = 0, j = 1; j <= list->polygonCount;) {
        current = findPoly(list, j);
        if (current)
            for (int k = 0; k < current->numOfElem; k++)
                if (current->pointArr[k] > 0)
                    arr[i++] = current->pointArr[k] - 1;
        j++;
    }
    //    for (int i = 0; i < polyArrNum; i++) {
    //        qDebug() << arr[i];
    //    }
    qDebug() << "SUCCESS CREATE ARRAY POLY";
    return arr;
}

double GLView::foundMin(double* arr) {
    double min = *arr;
    for (int i = 1; i < vertexArrNum; i++) {
        if (min > arr[i]) min = arr[i];
    }
    return min;
}

double GLView::foundMax(double* arr) {
    double max = *arr;
    for (int i = 1; i < vertexArrNum; i++) {
        if (max < arr[i]) max = arr[i];
    }
    return max;
}

void GLView::mousePressEvent(QMouseEvent* mo) {
    mouse_x0 = mo->pos().x();
    mouse_y0 = mo->pos().y();
}

void GLView::mouseMoveEvent(QMouseEvent* mo) {
    if (mo->buttons() & Qt::LeftButton) {
        setCursor(Qt::OpenHandCursor);
        xRot += 1 / M_PI * (mo->pos().y() - mouse_y0);
        yRot += 1 / M_PI * (mo->pos().x() - mouse_x0);

        mouse_x0 = mo->pos().x();
        mouse_y0 = mo->pos().y();

        updateGL();
    } else if (mo->buttons() & Qt::RightButton) {
        setCursor(Qt::OpenHandCursor);

        xMove += (mo->pos().x() - mouse_x0);
        yMove += (mo->pos().y() - mouse_y0);

        mouse_x0 = mo->pos().x();
        mouse_y0 = mo->pos().y();
        updateGL();
    }
}

void GLView::mouseReleaseEvent(QMouseEvent* mo) {
    mo = mo;
    setCursor(Qt::ArrowCursor);  // Standart Cursor
}
