#ifndef RECORD_H
#define RECORD_H

#include "dependencies.hpp"
#include "glview.h"

class Record : public QObject {
    Q_OBJECT
   public:
    explicit Record(QObject* parent = nullptr);
    explicit Record(GLView* gl = nullptr, QMenu* menu = nullptr)
        : glView(gl), recordMenu(menu) {
        timerCounter = 0;
        gifWidth = 640;
        gifHeight = 480;
    }

    GLView* glView;
    QMenu* recordMenu;
    QGifImage* gif;
    QTimer* timer;

   private:
    int timerCounter;
    int gifWidth;
    int gifHeight;

   public slots:
    void slotMakeScreen();
    void slotStartTimer();
    void slotMakeGif();
};

#endif  // RECORD_H
