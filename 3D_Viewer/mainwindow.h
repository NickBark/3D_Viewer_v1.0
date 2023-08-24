#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dependencies.hpp"
#include "mainframe.h"
#include "record.h"
#include "settings.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    QMenuBar* menuBar;
    QMenu* menu;
    QMenu* recordMenu;
    MainFrame* mainFrame;
    Settings* settings;
    Record* record;

    void Designer();
    void Layouts();
    void Properies();
    void Connector();

   private slots:
    void slotMenuResize();

   public slots:
    void slotOpenFile();
    void slotOpenSettings();

   signals:
    void resized(int width, int height);

   protected:
    void resizeEvent(QResizeEvent* event) override;
};
#endif  // MAINWINDOW_H
