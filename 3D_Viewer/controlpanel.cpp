#include "controlpanel.h"

ControlPanel::ControlPanel(QFrame* parent) : QFrame{parent} {
    Init();
    Designer();
    Properies();
    Layouts();
    Connector();
}

void ControlPanel::Init() {}

void ControlPanel::Designer() {
    glControl = new QGridLayout(this);
    //    slMoveX = new QSlider(this);
    //    slMoveY = new QSlider(this);
    //    slMoveZ = new QSlider(this);

    // Move
    pbMoveLeftX = new QPushButton("<-", this);
    dsbMoveXVal = new QDoubleSpinBox(this);
    pbMoveRightX = new QPushButton("->", this);

    pbMoveLeftY = new QPushButton("<-", this);
    dsbMoveYVal = new QDoubleSpinBox(this);
    pbMoveRightY = new QPushButton("->", this);

    pbMoveLeftZ = new QPushButton("<-", this);
    dsbMoveZVal = new QDoubleSpinBox(this);
    pbMoveRightZ = new QPushButton("->", this);

    // Rotate
    pbRotateLeftX = new QPushButton("<-", this);
    dsbRotateXVal = new QDoubleSpinBox(this);
    pbRotateRightX = new QPushButton("->", this);

    pbRotateLeftY = new QPushButton("<-", this);
    dsbRotateYVal = new QDoubleSpinBox(this);
    pbRotateRightY = new QPushButton("->", this);

    pbRotateLeftZ = new QPushButton("<-", this);
    dsbRotateZVal = new QDoubleSpinBox(this);
    pbRotateRightZ = new QPushButton("->", this);

    // Scale
    pbScaleLeftX = new QPushButton("<-", this);
    dsbScaleXVal = new QDoubleSpinBox(this);
    pbScaleRightX = new QPushButton("->", this);

    pbScaleLeftY = new QPushButton("<-", this);
    dsbScaleYVal = new QDoubleSpinBox(this);
    pbScaleRightY = new QPushButton("->", this);

    pbScaleLeftZ = new QPushButton("<-", this);
    dsbScaleZVal = new QDoubleSpinBox(this);
    pbScaleRightZ = new QPushButton("->", this);
}

void ControlPanel::Layouts() {
    setLayout(glControl);
    // Move
    glControl->addWidget(pbMoveLeftX, 0, 0, 1, 1);
    glControl->addWidget(dsbMoveXVal, 0, 1, 1, 1);
    glControl->addWidget(pbMoveRightX, 0, 2, 1, 1);

    glControl->addWidget(pbMoveLeftY, 1, 0, 1, 1);
    glControl->addWidget(dsbMoveYVal, 1, 1, 1, 1);
    glControl->addWidget(pbMoveRightY, 1, 2, 1, 1);

    glControl->addWidget(pbMoveLeftZ, 2, 0, 1, 1);
    glControl->addWidget(dsbMoveZVal, 2, 1, 1, 1);
    glControl->addWidget(pbMoveRightZ, 2, 2, 1, 1);
    // Rotate
    glControl->addWidget(pbRotateLeftX, 3, 0, 1, 1);
    glControl->addWidget(dsbRotateXVal, 3, 1, 1, 1);
    glControl->addWidget(pbRotateRightX, 3, 2, 1, 1);

    glControl->addWidget(pbRotateLeftY, 4, 0, 1, 1);
    glControl->addWidget(dsbRotateYVal, 4, 1, 1, 1);
    glControl->addWidget(pbRotateRightY, 4, 2, 1, 1);

    glControl->addWidget(pbRotateLeftZ, 5, 0, 1, 1);
    glControl->addWidget(dsbRotateZVal, 5, 1, 1, 1);
    glControl->addWidget(pbRotateRightZ, 5, 2, 1, 1);

    // Scale
    glControl->addWidget(pbScaleLeftX, 6, 0, 1, 1);
    glControl->addWidget(dsbScaleXVal, 6, 1, 1, 1);
    glControl->addWidget(pbScaleRightX, 6, 2, 1, 1);

    glControl->addWidget(pbScaleLeftY, 7, 0, 1, 1);
    glControl->addWidget(dsbScaleYVal, 7, 1, 1, 1);
    glControl->addWidget(pbScaleRightY, 7, 2, 1, 1);

    glControl->addWidget(pbScaleLeftZ, 8, 0, 1, 1);
    glControl->addWidget(dsbScaleZVal, 8, 1, 1, 1);
    glControl->addWidget(pbScaleRightZ, 8, 2, 1, 1);

    //    glControl->addWidget(slMoveX, 0, 0, 1, 1);
    //    glControl->addWidget(slMoveY, 1, 0, 1, 1);
    //    glControl->addWidget(slMoveZ, 2, 0, 1, 1);
}

void ControlPanel::Properies() {
    // Move
    pbMoveLeftX->setAutoRepeat(true);
    pbMoveLeftX->setFixedWidth(25);
    pbMoveRightX->setAutoRepeat(true);
    pbMoveRightX->setFixedWidth(25);
    pbMoveLeftY->setAutoRepeat(true);
    pbMoveLeftY->setFixedWidth(25);
    pbMoveRightY->setAutoRepeat(true);
    pbMoveRightY->setFixedWidth(25);
    pbMoveLeftZ->setAutoRepeat(true);
    pbMoveLeftZ->setFixedWidth(25);
    pbMoveRightZ->setAutoRepeat(true);
    pbMoveRightZ->setFixedWidth(25);

    dsbMoveXVal->setFixedWidth(50);
    dsbMoveXVal->setValue(10);
    dsbMoveYVal->setFixedWidth(50);
    dsbMoveYVal->setValue(10);
    dsbMoveZVal->setFixedWidth(50);
    dsbMoveZVal->setValue(10);

    // Rotate
    pbRotateLeftX->setAutoRepeat(true);
    pbRotateLeftX->setFixedWidth(25);
    pbRotateRightX->setAutoRepeat(true);
    pbRotateRightX->setFixedWidth(25);
    pbRotateLeftY->setAutoRepeat(true);
    pbRotateLeftY->setFixedWidth(25);
    pbRotateRightY->setAutoRepeat(true);
    pbRotateRightY->setFixedWidth(25);
    pbRotateLeftZ->setAutoRepeat(true);
    pbRotateLeftZ->setFixedWidth(25);
    pbRotateRightZ->setAutoRepeat(true);
    pbRotateRightZ->setFixedWidth(25);

    dsbRotateXVal->setFixedWidth(50);
    dsbRotateYVal->setFixedWidth(50);
    dsbRotateZVal->setFixedWidth(50);

    // Scale
    pbScaleLeftX->setAutoRepeat(true);
    pbScaleLeftX->setFixedWidth(25);
    pbScaleRightX->setAutoRepeat(true);
    pbScaleRightX->setFixedWidth(25);
    pbScaleLeftY->setAutoRepeat(true);
    pbScaleLeftY->setFixedWidth(25);
    pbScaleRightY->setAutoRepeat(true);
    pbScaleRightY->setFixedWidth(25);
    pbScaleLeftZ->setAutoRepeat(true);
    pbScaleLeftZ->setFixedWidth(25);
    pbScaleRightZ->setAutoRepeat(true);
    pbScaleRightZ->setFixedWidth(25);

    dsbScaleXVal->setFixedWidth(50);
    dsbScaleYVal->setFixedWidth(50);
    dsbScaleZVal->setFixedWidth(50);
    //    setStyleSheet("background-color: black;");
    //    slMoveX->setOrientation(Qt::Horizontal);
    //    slMoveX->setRange(-180, 180);

    //    slMoveY->setOrientation(Qt::Horizontal);
    //    slMoveY->setRange(-180, 180);

    //    slMoveZ->setOrientation(Qt::Horizontal);
    //    slMoveZ->setRange(-180, 180);
}

void ControlPanel::Connector() {}
