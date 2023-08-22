#include "settings.h"

Settings::Settings(QFrame *parent) : QFrame{parent} {
    setFixedSize(400, 400);
    setWindowTitle("3D Viewer Settings");

    Designer();
    Layouts();
    Properies();
    Connector();
}

void Settings::Designer() {
    glSettings = new QGridLayout(this);

    lVertex = new QLabel("Vertex", this);
    pbSetColorVertex = new QPushButton("Vertex Color", this);
    cdColorVertex = new QColorDialog(this);
    sbVertexSize = new QDoubleSpinBox(this);
    cbVertexType = new QComboBox(this);

    lEdge = new QLabel("Edge", this);
    pbSetColorEdge = new QPushButton("Edge color", this);
    cdColorEdge = new QColorDialog(this);
    sbEdgeSize = new QDoubleSpinBox(this);
    cbEdgeType = new QComboBox(this);

    pbSetBackColor = new QPushButton("Background color", this);
    cdColorBack = new QColorDialog(this);
}

void Settings::Layouts() {
    int index = 0;
    setLayout(glSettings);

    glSettings->addWidget(lVertex, index++, 0, 1, 1);
    glSettings->addWidget(pbSetColorVertex, index++, 0, 1, 1);
    glSettings->addWidget(sbVertexSize, index++, 0, 1, 1);
    glSettings->addWidget(cbVertexType, index++, 0, 1, 1);

    glSettings->addWidget(lEdge, index++, 0, 1, 1);
    glSettings->addWidget(pbSetColorEdge, index++, 0, 1, 1);
    glSettings->addWidget(sbEdgeSize, index++, 0, 1, 1);
    glSettings->addWidget(cbEdgeType, index++, 0, 1, 1);

    glSettings->addWidget(pbSetBackColor, index++, 0, 1, 1);
}

void Settings::Properies() {
    sbVertexSize->setPrefix("Vertex Size:");
    sbVertexSize->setRange(0, 255);
    sbVertexSize->setValue(2);
    cbVertexType->addItems({"Rectangle", "Circle", "Absent"});

    sbEdgeSize->setPrefix("Edge Width:");
    sbEdgeSize->setRange(0, 255);
    sbEdgeSize->setValue(1);
    cbEdgeType->addItems({"Solid", "Dotted"});
}

void Settings::Connector() {
    connect(pbSetColorVertex, &QPushButton::clicked, cdColorVertex,
            &QColorDialog::show);
    connect(pbSetColorEdge, &QPushButton::clicked, cdColorEdge,
            &QColorDialog::show);
    connect(pbSetBackColor, &QPushButton::clicked, cdColorBack,
            &QColorDialog::show);
}

void Settings::saveSettings() {
    QSettings settings("3D_Viewer_Settings");
    settings.setValue("sbVertexSize", sbVertexSize->value());
    settings.setValue("cbVertexType", cbVertexType->currentIndex());
    settings.setValue("sbEdgeSize", sbEdgeSize->value());
    settings.setValue("cbEdgeType", cbEdgeType->currentIndex());
}

void Settings::loadSettings() {}
