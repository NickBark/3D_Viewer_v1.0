#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "dependencies.hpp"
#include "glview.h"

class MainFrame : public QFrame {
    Q_OBJECT
   public:
    explicit MainFrame(QFrame* parent = nullptr);

    GLView* glView;

    LinkedListPolygon* poly;
    LinkedListVertex* list;

    int createLists();

   signals:
};

#endif  // MAINFRAME_H
