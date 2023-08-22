#include "glview.h"

// не забыть очистить память массивов и списков

// добавил строку list->current = list->head везде что бы ускорить проход по
// списку (по скольку значение list->current всегда сохраняет последнюю позицию)

GLView::GLView(QWidget* parent) : QGLWidget{parent} {
    setGeometry(10, 35, 600, 400);
    maxCoord = 10;
    //    minCoord = 100;
    vertexArr = NULL;
    polyArr = NULL;
    vertexCount = 0;
    //    polyArrNum = 0;
    pVertexList = NULL;
    pPolyList = NULL;

    // control
    xRot = 0.;
    yRot = 0.;
    xMove = 0.;
    yMove = 0.;
    zoom = 0.;
    stateOfAxis = 1;

    loadSettings();
}

void GLView::createArrays(LinkedListVertex* vertexList,
                          LinkedListPolygon* polyList) {
    pVertexList = vertexList;
    pPolyList = polyList;
    if (vertexArr) delete[] vertexArr;
    if (polyArr) delete[] polyArr;
    vertexArr = createVertexArr(pVertexList);
    polyArr = createPolyArr(pPolyList);

    qDebug() << "max Coords: " << maxCoord;

    vertexCount = pVertexList->vertexCount;

    updateGL();
}

GLView::~GLView() {}

void GLView::initializeGL() {
    glClearColor(clearColorR, clearColorG, clearColorB, 1.0f);
    glEnable(GL_DEPTH_TEST);

    //    glEnable(GL_CULL_FACE); // отсечение задних граней
}

void GLView::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double k = (double)w / (double)h;
    //    glOrtho(-100, 100, -100, 100, 1, 500.0);
    glFrustum(-k, k, -1, 1, 1, 500.0);
}

void GLView::paintGL() {
    //    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -maxCoord - 5.0f);

    //    drawAxis();
    glTranslatef(0.0f + xMove / 25.0f, 0.0f + yMove / 25.0f, zoom);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);
    if (stateOfAxis) drawAxis();
    if (pPolyList && pVertexList) {
        drawVertex();
    }
}

void GLView::drawVertex() {
    glPushMatrix();

    glVertexPointer(3, GL_DOUBLE, 0, vertexArr);
    glEnableClientState(GL_VERTEX_ARRAY);

    if (vertexType != 2) {
        glDisable(GL_POINT_SMOOTH);
        if (vertexType) glEnable(GL_POINT_SMOOTH);
        glPointSize(vertexSize);
        glColor3d(vertexColorRed, vertexColorGreen, vertexColorBlue);
        glDrawArrays(GL_POINTS, 0, pVertexList->vertexCount);
    }

    glDisable(GL_LINE_STIPPLE);
    if (edgeType) {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(10, GL_LINE_STIPPLE_PATTERN);
    }

    glLineWidth(lineWidth);
    glColor3d(edgeColorRed, edgeColorGreen, edgeColorBlue);

    Polygon* current = NULL;
    int tmp = 0;
    pPolyList->current = pPolyList->head;
    for (int i = 0; i < pPolyList->polygonCount; i++) {
        current = findPoly(pPolyList, i + 1);
        glDrawElements(GL_LINE_LOOP, current->numOfElem, GL_UNSIGNED_INT,
                       polyArr + tmp);
        tmp += current->numOfElem;
    }

    glDisable(GL_LINE_STIPPLE);

    glDisableClientState(GL_VERTEX_ARRAY);

    glPopMatrix();
}

double* GLView::createVertexArr(LinkedListVertex* list) {
    vertexArrNum = list->vertexCount * 3;
    double* arr = new double[vertexArrNum];
    Vertex* current = NULL;
    list->current = list->head;
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
    qDebug() << "poly arr num: " << list->numOfIndex;

    unsigned int* arr = new unsigned int[list->numOfIndex];

    Polygon* current = NULL;
    list->current = list->head;
    for (int i = 0, j = 1; j <= list->polygonCount;) {
        current = findPoly(list, j);
        if (current)
            for (int k = 0; k < current->numOfElem; k++)
                if (current->pointArr[k] > 0)
                    arr[i++] = current->pointArr[k] - 1;
        j++;
    }

    qDebug() << "SUCCESS CREATE ARRAY POLY";
    return arr;
}

double GLView::foundMax(LinkedListVertex* list) {
    double max = list->head->z;
    Vertex* current = NULL;
    list->current = list->head;
    for (int i = 2; i < list->vertexCount; i++) {
        current = findVertex(list, i);
        if (max < current->z) max = current->z;
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
        yMove -= (mo->pos().y() - mouse_y0);

        mouse_x0 = mo->pos().x();
        mouse_y0 = mo->pos().y();
        updateGL();
    }
}

void GLView::mouseReleaseEvent(QMouseEvent* mo) {
    mo = mo;
    setCursor(Qt::ArrowCursor);  // Standart Cursor
}

void GLView::wheelEvent(QWheelEvent* event) {
    QPoint numDergees = event->angleDelta();
    zoom += numDergees.y() / 120.0f;
    updateGL();
}

void GLView::MoveCamera() {
    //    QMatrix4x4 viewMatrix  =
    //    QMatrix4x4 modelMatrix;
    //    QMatrix4X4 modelViewMatrix = viewMatrix * modelMatrix;
}

void GLView::drawAxis() {
    float arr[] = {0,  0,  0,    // 0
                   10, 0,  0,    // 1
                   0,  10, 0,    // 2
                   0,  0,  10};  // 3

    unsigned int index[] = {0, 1, 0, 2, 0, 3};

    glPushMatrix();

    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, arr);
    glLineWidth(1);
    glColor3d(1, 0, 0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_INT, index);
    glColor3d(0, 1, 0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_INT, index + 2);
    glColor3d(0, 0, 1);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_INT, index + 4);

    glDisableClientState(GL_VERTEX_ARRAY);

    glPopMatrix();
}

void GLView::slotStateOfAxis() {
    stateOfAxis = !stateOfAxis;
    updateGL();
}

void GLView::slotHome() {
    yRot = 0;
    xRot = 0;
    xMove = 0;
    yMove = 0;
    zoom = 0;
    updateGL();
}

// void GLView::slotSetVertexSettings(int a, const QString& senderName) {
////    if (senderName == "Red") vertexColorRed = static_cast<double>(a) / 255.;
////    if (senderName == "Green") vertexColorGreen = static_cast<double>(a) /
/// 255.; /    if (senderName == "Blue") vertexColorBlue =
/// static_cast<double>(a) / 255.;

////    updateGL();
//}

void GLView::slotSetVertexColor(const QColor& color) {
    vertexColorRed = static_cast<double>(color.red()) / 255.;
    vertexColorGreen = static_cast<double>(color.green()) / 255.;
    vertexColorBlue = static_cast<double>(color.blue()) / 255.;
    saveSettings();
    updateGL();
}

void GLView::slotSetEdgeColor(const QColor& color) {
    edgeColorRed = static_cast<double>(color.red()) / 255.;
    edgeColorGreen = static_cast<double>(color.green()) / 255.;
    edgeColorBlue = static_cast<double>(color.blue()) / 255.;
    saveSettings();
    updateGL();
}

void GLView::slotSetBackgroundColor(const QColor& color) {
    clearColorR = static_cast<double>(color.red()) / 255.;
    clearColorG = static_cast<double>(color.green()) / 255.;
    clearColorB = static_cast<double>(color.blue()) / 255.;
    glClearColor(clearColorR, clearColorG, clearColorB, 1.0f);
    saveSettings();
    updateGL();
}

void GLView::slotVertexSize(double value) {
    vertexSize = static_cast<float>(value);
    saveSettings();
    updateGL();
}

void GLView::slotEdgeWidth(double value) {
    lineWidth = static_cast<float>(value);
    saveSettings();
    updateGL();
}

void GLView::slotSetVertexType(int value) {
    vertexType = value;
    saveSettings();
    updateGL();
}

void GLView::slotSetEdgeType(int value) {
    edgeType = value;
    saveSettings();
    updateGL();
}

void GLView::saveSettings() {
    QSettings settings("Bober", "3D_Viewer_Settings");
    settings.setValue("vertexColorRed", vertexColorRed);
    settings.setValue("vertexColorGreen", vertexColorGreen);
    settings.setValue("vertexColorBlue", vertexColorBlue);
    settings.setValue("vertexSize", vertexSize);
    settings.setValue("vertexType", vertexType);

    settings.setValue("edgeColorRed", edgeColorRed);
    settings.setValue("edgeColorGreen", edgeColorGreen);
    settings.setValue("edgeColorBlue", edgeColorBlue);
    settings.setValue("lineWidth", lineWidth);
    settings.setValue("edgeType", edgeType);

    settings.setValue("clearColorR", clearColorR);
    settings.setValue("clearColorG", clearColorG);
    settings.setValue("clearColorB", clearColorB);
}

void GLView::loadSettings() {
    QSettings settings("Bober", "3D_Viewer_Settings");
    // vertex
    vertexColorRed = settings.value("vertexColorRed", 0.).toDouble();
    vertexColorGreen = settings.value("vertexColorGreen", 0.).toDouble();
    vertexColorBlue = settings.value("vertexColorBlue", 1.).toDouble();
    vertexSize = settings.value("vertexSize", 2.0f).toFloat();
    vertexType = settings.value("vertexType", 0.).toInt();

    // edge
    edgeColorRed = settings.value("edgeColorRed", 1.).toDouble();
    edgeColorGreen = settings.value("edgeColorGreen", 0.).toDouble();
    edgeColorBlue = settings.value("edgeColorBlue", 0.).toDouble();
    lineWidth = settings.value("lineWidth", 1.0f).toFloat();
    edgeType = settings.value("edgeType", 0.).toInt();

    // background
    clearColorR = settings.value("clearColorR", 0.).toDouble();
    clearColorG = settings.value("clearColorG", 0.).toDouble();
    clearColorB = settings.value("clearColorB", 0.).toDouble();
}
