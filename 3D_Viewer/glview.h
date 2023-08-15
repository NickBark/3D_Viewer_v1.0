#ifndef GLVIEW_H
#define GLVIEW_H

#include "dependencies.hpp"

class GLView : public QGLWidget {
    Q_OBJECT
   public:
    explicit GLView(QWidget* parent = nullptr,
                    LinkedListVertex* vertexList = NULL,
                    LinkedListPolygon* polyList = NULL);
    ~GLView();
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    double* arr;

   signals:
};

#endif  // GLVIEW_H
