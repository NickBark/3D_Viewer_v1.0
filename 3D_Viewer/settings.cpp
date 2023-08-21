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
    lVertexColor = new QLabel("Vertex colors", this);
    //    sVertexRed = new QSlider(this);
    //    sVertexGreen = new QSlider(this);
    //    sVertexBlue = new QSlider(this);
    pbSetColorVertex = new QPushButton("Vertex Color", this);
    cdColorVertex = new QColorDialog(this);
    sbVertexSize = new QDoubleSpinBox(this);
}

void Settings::Layouts() {
    int index = 0;
    setLayout(glSettings);
    glSettings->addWidget(lVertex, index++, 0, 1, 1);
    glSettings->addWidget(lVertexColor, index++, 0, 1, 1);
    //    glSettings->addWidget(sVertexRed, index++, 0, 1, 1);
    //    glSettings->addWidget(sVertexGreen, index++, 0, 1, 1);
    //    glSettings->addWidget(sVertexBlue, index++, 0, 1, 1);
    glSettings->addWidget(pbSetColorVertex, index++, 0, 1, 1);
    glSettings->addWidget(sbVertexSize, index++, 0, 1, 1);
}

void Settings::Properies() {
    //    sVertexRed->setOrientation(Qt::Horizontal);
    //    sVertexRed->setRange(0, 255);
    //    sVertexRed->setValue(0);
    //    sVertexGreen->setOrientation(Qt::Horizontal);
    //    sVertexGreen->setRange(0, 255);
    //    sVertexGreen->setValue(0);
    //    sVertexBlue->setOrientation(Qt::Horizontal);
    //    sVertexBlue->setRange(0, 255);
    //    sVertexBlue->setValue(255);

    sbVertexSize->setPrefix("Vertex Size:");
    sbVertexSize->setRange(0, 255);
    sbVertexSize->setValue(2);
}

void Settings::Connector() {
    connect(pbSetColorVertex, &QPushButton::clicked, this,
            &Settings::slotSetColorVertex);
}

void Settings::slotSetColorVertex() { cdColorVertex->show(); }
