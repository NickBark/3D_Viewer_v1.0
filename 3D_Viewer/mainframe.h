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

   private:
    QVBoxLayout* vbl;
    QHBoxLayout* hbl;

   private slots:
    void slotMove();
    void slotRotate();
    void slotScale();

   signals:
};

#endif  // MAINFRAME_H
