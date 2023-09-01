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

    void saveSettings();
    void loadSettings();

    //    void drawPolygons();

    //   private:
    //    QMatrix4x4 m_projectionMatrix;
    int width;
    int height;
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

    // vertex
    double vertexColorRed, vertexColorGreen, vertexColorBlue;
    float vertexSize;
    int vertexType;

    // background color
    double clearColorR, clearColorG, clearColorB;

    // edge
    double edgeColorRed, edgeColorGreen, edgeColorBlue;
    float lineWidth;
    int edgeType;

    int projectionType;

   public slots:
    void slotStateOfAxis();
    void slotHome();
    void slotSetVertexColor(const QColor& color);
    void slotSetEdgeColor(const QColor& color);
    void slotSetBackgroundColor(const QColor& color);
    void slotVertexSize(double value);
    void slotEdgeWidth(double value);
    void slotSetVertexType(int value);
    void slotSetEdgeType(int value);
    void slotSetProjection(int value);
};

#endif  // GLVIEW_H
