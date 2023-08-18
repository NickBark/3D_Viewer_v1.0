#ifndef GLVIEW_H
#define GLVIEW_H

// временно для работы мыши
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QPoint>

#include "dependencies.hpp"

class GLView : public QGLWidget {
    Q_OBJECT
   public:
    explicit GLView(QWidget* parent = nullptr);
    ~GLView();

   private:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;

   public:
    void createArrays(LinkedListVertex* vertexList,
                      LinkedListPolygon* polyList);
    double* createVertexArr(LinkedListVertex* list);
    unsigned int* createPolyArr(LinkedListPolygon* list);

    double foundMin(double* arr);
    double foundMax(double* arr);
    void drawVertex();
    void drawPolygons();

    //   private:
    //    QMatrix4x4 m_projectionMatrix;

    float xRot, yRot, zRot;  // координаты вращения
    int mouse_x0, mouse_y0;  //координаты мышки
    float xMove, yMove;

    GLdouble minCoord;  // минимальное значение в массиве вершин
    GLdouble maxCoord;  // максимальное значение в массиве вершин

    double* vertexArr;
    int vertexCount;

    unsigned int* polyArr;
    int vertexArrNum;
    //    int polyArrNum;
    int pointInPolygon;

    LinkedListVertex* pVertexList;
    LinkedListPolygon* pPolyList;

   signals:
};

#endif  // GLVIEW_H
