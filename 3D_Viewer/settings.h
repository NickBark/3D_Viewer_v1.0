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

    void loadSettings();

   public:
    QGridLayout* glSettings;

    // Vertex
    QLabel* lVertex;
    QPushButton* pbSetColorVertex;
    QColorDialog* cdColorVertex;
    QDoubleSpinBox* sbVertexSize;
    QComboBox* cbVertexType;

    // Edge
    QLabel* lEdge;
    QPushButton* pbSetColorEdge;
    QColorDialog* cdColorEdge;
    QDoubleSpinBox* sbEdgeSize;
    QComboBox* cbEdgeType;

    // background
    QPushButton* pbSetBackColor;
    QColorDialog* cdColorBack;

    // projection
    QComboBox* cbProjection;

   private slots:
    void saveSettings();
};

#endif  // SETTINGS_H
