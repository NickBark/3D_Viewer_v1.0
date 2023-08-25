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

    lAdditionalSettings = new QLabel("Additional settings", this);

    pbSetBackColor = new QPushButton("Background color", this);
    cdColorBack = new QColorDialog(this);

    cbProjection = new QComboBox(this);
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

    glSettings->addWidget(lAdditionalSettings, index++, 0, 1, 1);
    glSettings->addWidget(pbSetBackColor, index++, 0, 1, 1);
    glSettings->addWidget(cbProjection, index++, 0, 1, 1);
}

void Settings::Properies() {
    sbVertexSize->setPrefix("Vertex Size:");
    sbVertexSize->setRange(1, 255);
    sbVertexSize->setValue(2);
    cbVertexType->addItems({"Rectangle", "Circle", "Absent"});

    sbEdgeSize->setPrefix("Edge Width:");
    sbEdgeSize->setRange(1, 10);
    sbEdgeSize->setValue(1);
    cbEdgeType->addItems({"Solid", "Dotted"});

    cbProjection->addItems({"Perspective", "Orthographic"});

    loadSettings();
}

void Settings::Connector() {
    connect(pbSetColorVertex, &QPushButton::clicked, cdColorVertex,
            &QColorDialog::show);
    connect(pbSetColorEdge, &QPushButton::clicked, cdColorEdge,
            &QColorDialog::show);
    connect(pbSetBackColor, &QPushButton::clicked, cdColorBack,
            &QColorDialog::show);

    connect(sbVertexSize,
            static_cast<void (QDoubleSpinBox::*)(double)>(
                &QDoubleSpinBox::valueChanged),
            this, &Settings::saveSettings);
    connect(
        cbVertexType,
        static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        this, &Settings::saveSettings);
    connect(sbEdgeSize,
            static_cast<void (QDoubleSpinBox::*)(double)>(
                &QDoubleSpinBox::valueChanged),
            this, &Settings::saveSettings);
    connect(
        cbEdgeType,
        static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        this, &Settings::saveSettings);
    connect(
        cbProjection,
        static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        this, &Settings::saveSettings);
}

void Settings::saveSettings() {
    QSettings settings("Bober", "3D_Viewer_Settings");
    settings.setValue("sbVertexSize", sbVertexSize->value());
    settings.setValue("cbVertexType", cbVertexType->currentIndex());
    settings.setValue("sbEdgeSize", sbEdgeSize->value());
    settings.setValue("cbEdgeType", cbEdgeType->currentIndex());
    settings.setValue("cbProjection", cbProjection->currentIndex());
}

void Settings::loadSettings() {
    QSettings settings("Bober", "3D_Viewer_Settings");
    sbVertexSize->setValue(settings.value("sbVertexSize", 2.).toDouble());
    cbVertexType->setCurrentIndex(settings.value("cbVertexType", 0).toInt());
    sbEdgeSize->setValue(settings.value("sbEdgeSize", 1.).toDouble());
    cbEdgeType->setCurrentIndex(settings.value("cbEdgeType", 0).toInt());
    cbProjection->setCurrentIndex(settings.value("cbProjection", 0).toInt());
}
