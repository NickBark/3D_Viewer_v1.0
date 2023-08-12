#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <GL/gl.h>
#include <GL/glu.h>

//#include <QGLWidget>
#include <QMainWindow>
//#include <QtOpenGL>
//#include <QtPlugin>

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif  // MAINWINDOW_H
