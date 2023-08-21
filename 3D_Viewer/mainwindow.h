#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dependencies.hpp"
#include "mainframe.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    QMenuBar* menuBar;
    QMenu* menu;
    MainFrame* mainFrame;

    //    QVBoxLayout* hblMain;

   private slots:
    void slotMenuResize();

   public slots:
    void slotOpenFile();

   signals:
    void resized(int width, int height);

   protected:
    void resizeEvent(QResizeEvent* event) override;
};
#endif  // MAINWINDOW_H
