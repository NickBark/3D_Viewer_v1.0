#ifndef SETTINGS_H
#define SETTINGS_H

#include "dependencies.hpp"

class Settings : public QFrame {
    Q_OBJECT
   public:
    explicit Settings(QFrame* parent = nullptr);

    //    GLView* glView;

   private:
    void Designer();
    void Layouts();
    void Properies();
    void Connector();

   public:
    QGridLayout* glSettings;
    QLabel* lVertex;
    QLabel* lVertexColor;
    //    QSlider* sVertexRed;
    //    QSlider* sVertexGreen;
    //    QSlider* sVertexBlue;

    QPushButton* pbSetColorVertex;
    QColorDialog* cdColorVertex;
    QDoubleSpinBox* sbVertexSize;

   public slots:
    void slotSetColorVertex();
};

#endif  // SETTINGS_H
