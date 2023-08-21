#ifndef GLVIEW_H
#define GLVIEW_H

// временно для работы мыши
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QPoint>

#include "dependencies.hpp"
#include "settings.h"

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
    void wheelEvent(QWheelEvent*) override;

   public:
    void createArrays(LinkedListVertex* vertexList,
                      LinkedListPolygon* polyList);
    double* createVertexArr(LinkedListVertex* list);
    unsigned int* createPolyArr(LinkedListPolygon* list);

    void MoveCamera();

    //    double foundMin(double* arr);
    double foundMax(LinkedListVertex* list);
    void drawVertex();
    void drawAxis();
    //    void drawPolygons();

    //   private:
    //    QMatrix4x4 m_projectionMatrix;

    float xRot, yRot, zRot;  // координаты вращения
    int mouse_x0, mouse_y0;  //координаты мышки
    float xMove, yMove;
    float zoom;
    int stateOfAxis;

    double xCenter, yCenterm, zCenter;

    //    GLdouble minCoord;  // минимальное значение в массиве вершин
    double maxCoord;  // максимальное значение в массиве вершин

    double* vertexArr;
    int vertexCount;

    unsigned int* polyArr;
    int vertexArrNum;
    //    int polyArrNum;
    int pointInPolygon;

    LinkedListVertex* pVertexList;
    LinkedListPolygon* pPolyList;

    //    Settings* settings;
    // vertex colors
    double vertexColorRed, vertexColorGreen, vertexColorBlue;

    // background color
    double clearColorR, clearColorG, clearColorB;

    float vertexSize;

   public slots:
    void slotStateOfAxis();
    void slotHome();
    //    void slotSetVertexSettings(int a, const QString& senderName);
    void slotSetVertexColor(const QColor& color);
    void slotVertexSize(double value);
};

#endif  // GLVIEW_H
