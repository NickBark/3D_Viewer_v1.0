#include <QApplication>

#include "mainwindow.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    const char* previousLocale = setlocale(LC_NUMERIC, nullptr);
    setlocale(LC_NUMERIC, "C");

    MainWindow w;
    w.show();

    setlocale(LC_NUMERIC, previousLocale);

    return a.exec();
}
