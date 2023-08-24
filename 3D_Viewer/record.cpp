#include "record.h"

Record::Record(QObject* parent) : QObject{parent} {}

void Record::slotMakeScreen() {
    QImage image = glView->grabFrameBuffer();

    if (qobject_cast<QAction*>(sender()) == recordMenu->actions().at(0)) {
        QString fileName = QFileDialog::getSaveFileName(
            qobject_cast<QWidget*>(this), "Save as...", "screen.jpeg",
            "JPEG (*.jpeg)");
        image.save(fileName, "JPEG", 85);
        qDebug() << fileName;
    } else if (qobject_cast<QAction*>(sender()) ==
               recordMenu->actions().at(1)) {
        QString fileName = QFileDialog::getSaveFileName(
            qobject_cast<QWidget*>(this), "Save as...", "screen.bmp",
            "BMP (*.bmp)");
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
    QImage image = glView->grabFrameBuffer().scaled(gifWidth, gifHeight);
    gif->addFrame(image);
    timerCounter++;
    if (timerCounter == 50) {
        QString fileName = QFileDialog::getSaveFileName(
            qobject_cast<QWidget*>(this), "Save as...", "animation.gif",
            "GIF (*.gif)");
        timerCounter = 0;
        timer->stop();
        gif->save(fileName);
        delete gif;
    }
}
