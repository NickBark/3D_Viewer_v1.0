#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "controlpanel.h"
#include "dependencies.hpp"
#include "edge.h"
#include "glview.h"

class MainFrame : public QFrame {
    Q_OBJECT
   public:
    explicit MainFrame(QFrame* parent = nullptr);
    ~MainFrame();

    GLView* glView;
    ControlPanel* cPanel;

    LinkedListPolygon* poly;
    LinkedListVertex* list;

    QString* fileName;

    QLabel* lInfoModel;

    int numOfEdges;

    void Designer();
    void Layouts();
    void Properies();
    void Connector();

    int createLists(const char* fileName);
    int uniqueEdges();

    double xMoveSave;
    double yMoveSave;
    double zMoveSave;

   private:
    QVBoxLayout* vbl;
    QHBoxLayout* hbl;

    void setCenter();
    void setBack();

   private slots:
    void slotMove();
    void slotRotate();
    void slotScale();
    void slotSetHome();

   signals:
};

#endif  // MAINFRAME_H
