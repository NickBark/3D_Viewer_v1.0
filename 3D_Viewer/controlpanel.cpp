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
    labelMove = new QLabel("Move", this);
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
    labelRotate = new QLabel("Rotate", this);
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
    labelScale = new QLabel("Scale", this);
    pbScaleLeftX = new QPushButton("<-", this);
    dsbScaleXVal = new QDoubleSpinBox(this);
    pbScaleRightX = new QPushButton("->", this);

    pbScaleLeftY = new QPushButton("<-", this);
    dsbScaleYVal = new QDoubleSpinBox(this);
    pbScaleRightY = new QPushButton("->", this);

    pbScaleLeftZ = new QPushButton("<-", this);
    dsbScaleZVal = new QDoubleSpinBox(this);
    pbScaleRightZ = new QPushButton("->", this);

    lShowXMove = new QLabel("X:", this);
    lShowYMove = new QLabel("Y:", this);
    lShowZMove = new QLabel("Z:", this);
    lShowXRotate = new QLabel("X:", this);
    lShowYRotate = new QLabel("Y:", this);
    lShowZRotate = new QLabel("Z:", this);
    lShowXScale = new QLabel("X:", this);
    lShowYScale = new QLabel("Y:", this);
    lShowZScale = new QLabel("Z:", this);

    lShowAxis = new QLabel("Show Axis:", this);
    cbShowAxis = new QCheckBox(this);
}

void ControlPanel::Layouts() {
    setLayout(glControl);
    int indexRow = 0;
    // Move
    glControl->addWidget(labelMove, indexRow++, 0, 1, 1);
    glControl->addWidget(lShowXMove, indexRow, 0, 1, 1);
    glControl->addWidget(pbMoveLeftX, indexRow, 1, 1, 1);
    glControl->addWidget(dsbMoveXVal, indexRow, 2, 1, 1);
    glControl->addWidget(pbMoveRightX, indexRow++, 3, 1, 1);

    glControl->addWidget(lShowYMove, indexRow, 0, 1, 1);
    glControl->addWidget(pbMoveLeftY, indexRow, 1, 1, 1);
    glControl->addWidget(dsbMoveYVal, indexRow, 2, 1, 1);
    glControl->addWidget(pbMoveRightY, indexRow++, 3, 1, 1);

    glControl->addWidget(lShowZMove, indexRow, 0, 1, 1);
    glControl->addWidget(pbMoveLeftZ, indexRow, 1, 1, 1);
    glControl->addWidget(dsbMoveZVal, indexRow, 2, 1, 1);
    glControl->addWidget(pbMoveRightZ, indexRow++, 3, 1, 1);
    // Rotate
    glControl->addWidget(labelRotate, indexRow++, 0, 1, 1);
    glControl->addWidget(lShowXRotate, indexRow, 0, 1, 1);
    glControl->addWidget(pbRotateLeftX, indexRow, 1, 1, 1);
    glControl->addWidget(dsbRotateXVal, indexRow, 2, 1, 1);
    glControl->addWidget(pbRotateRightX, indexRow++, 3, 1, 1);

    glControl->addWidget(lShowYRotate, indexRow, 0, 1, 1);
    glControl->addWidget(pbRotateLeftY, indexRow, 1, 1, 1);
    glControl->addWidget(dsbRotateYVal, indexRow, 2, 1, 1);
    glControl->addWidget(pbRotateRightY, indexRow++, 3, 1, 1);

    glControl->addWidget(lShowZRotate, indexRow, 0, 1, 1);
    glControl->addWidget(pbRotateLeftZ, indexRow, 1, 1, 1);
    glControl->addWidget(dsbRotateZVal, indexRow, 2, 1, 1);
    glControl->addWidget(pbRotateRightZ, indexRow++, 3, 1, 1);

    // Scale
    glControl->addWidget(labelScale, indexRow++, 0, 1, 1);
    glControl->addWidget(lShowXScale, indexRow, 0, 1, 1);
    glControl->addWidget(pbScaleLeftX, indexRow, 1, 1, 1);
    glControl->addWidget(dsbScaleXVal, indexRow, 2, 1, 1);
    glControl->addWidget(pbScaleRightX, indexRow++, 3, 1, 1);

    glControl->addWidget(lShowYScale, indexRow, 0, 1, 1);
    glControl->addWidget(pbScaleLeftY, indexRow, 1, 1, 1);
    glControl->addWidget(dsbScaleYVal, indexRow, 2, 1, 1);
    glControl->addWidget(pbScaleRightY, indexRow++, 3, 1, 1);

    glControl->addWidget(lShowZScale, indexRow, 0, 1, 1);
    glControl->addWidget(pbScaleLeftZ, indexRow, 1, 1, 1);
    glControl->addWidget(dsbScaleZVal, indexRow, 2, 1, 1);
    glControl->addWidget(pbScaleRightZ, indexRow++, 3, 1, 1);

    glControl->addWidget(lShowAxis, indexRow, 0, 1, 1);
    glControl->addWidget(cbShowAxis, indexRow++, 1, 1, 1);

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
    dsbRotateXVal->setValue(0.1);
    dsbRotateYVal->setFixedWidth(50);
    dsbRotateYVal->setValue(0.1);
    dsbRotateZVal->setFixedWidth(50);
    dsbRotateZVal->setValue(0.1);

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
    dsbScaleXVal->setValue(2);
    dsbScaleYVal->setFixedWidth(50);
    dsbScaleYVal->setValue(2);
    dsbScaleZVal->setFixedWidth(50);
    dsbScaleZVal->setValue(2);

    lShowXMove->setMaximumWidth(30);

    cbShowAxis->setChecked(true);

    //    setStyleSheet("background-color: black;");
    //    slMoveX->setOrientation(Qt::Horizontal);
    //    slMoveX->setRange(-180, 180);

    //    slMoveY->setOrientation(Qt::Horizontal);
    //    slMoveY->setRange(-180, 180);

    //    slMoveZ->setOrientation(Qt::Horizontal);
    //    slMoveZ->setRange(-180, 180);
}

void ControlPanel::Connector() {}
