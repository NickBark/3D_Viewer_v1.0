#include "record.h"

Record::Record(QObject* parent) : QObject{parent} {}

void Record::slotMakeScreen() {
    QImage image = glView->grabFrameBuffer();
    QString fileName;
    fileName += "3D_Viewer_Screen_";
    fileName += QDate::currentDate().toString("yyyy-MM-dd");
    fileName += "_";
    fileName += QTime::currentTime().toString("hh:mm:ss");

    if (qobject_cast<QAction*>(sender()) == recordMenu->actions().at(0)) {
        fileName += ".jpeg";
        image.save(fileName, "JPEG", 85);
        qDebug() << fileName;
    } else if (qobject_cast<QAction*>(sender()) ==
               recordMenu->actions().at(1)) {
        fileName += ".bmp";
        image.save(fileName, "BMP");
        qDebug() << fileName;
    }
}

void Record::slotStartTimer() {
    timerCounter = 0;
    gifWidth = 640;
    gifHeight = 480;
    gif = new QGifImage(QSize(gifWidth, gifHeight));
    gif->setDefaultDelay(100);
    timer->start(100);
    connect(timer, &QTimer::timeout, this, &Record::slotMakeGif);
}

void Record::slotMakeGif() {
    QString fileName;
    fileName += "3D_Viewer_Screen_";
    fileName += QDate::currentDate().toString("yyyy-MM-dd");
    fileName += "_";
    fileName += QTime::currentTime().toString("hh:mm:ss");
    fileName += ".gif";
    QImage image = glView->grabFrameBuffer().scaled(gifWidth, gifHeight);
    gif->addFrame(image);
    timerCounter++;
    if (timerCounter == 50) {
        timerCounter = 0;
        timer->stop();
        gif->save(fileName);
        delete gif;
    }
}
