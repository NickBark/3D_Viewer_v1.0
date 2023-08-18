#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QLabel>

#include "dependencies.hpp"

class ControlPanel : public QFrame {
    Q_OBJECT
   public:
    explicit ControlPanel(QFrame* parent = nullptr);

   private:
    void Init();
    void Designer();
    void Layouts();
    void Properies();
    void Connector();

   public:
    QGridLayout* glControl;

    QLabel* labelMove;
    QPushButton* pbMoveLeftX;
    QDoubleSpinBox* dsbMoveXVal;
    QPushButton* pbMoveRightX;

    QPushButton* pbMoveLeftY;
    QDoubleSpinBox* dsbMoveYVal;
    QPushButton* pbMoveRightY;

    QPushButton* pbMoveLeftZ;
    QDoubleSpinBox* dsbMoveZVal;
    QPushButton* pbMoveRightZ;

    QLabel* labelRotate;
    QPushButton* pbRotateLeftX;
    QDoubleSpinBox* dsbRotateXVal;
    QPushButton* pbRotateRightX;

    QPushButton* pbRotateLeftY;
    QDoubleSpinBox* dsbRotateYVal;
    QPushButton* pbRotateRightY;

    QPushButton* pbRotateLeftZ;
    QDoubleSpinBox* dsbRotateZVal;
    QPushButton* pbRotateRightZ;

    QLabel* labelScale;
    QPushButton* pbScaleLeftX;
    QDoubleSpinBox* dsbScaleXVal;
    QPushButton* pbScaleRightX;

    QPushButton* pbScaleLeftY;
    QDoubleSpinBox* dsbScaleYVal;
    QPushButton* pbScaleRightY;

    QPushButton* pbScaleLeftZ;
    QDoubleSpinBox* dsbScaleZVal;
    QPushButton* pbScaleRightZ;

    //    QSlider* slMoveX;
    //    QSlider* slMoveY;
    //    QSlider* slMoveZ;

   signals:
};

#endif  // CONTROLPANEL_H
