#include "mainwindow.h"
#include "model.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    model model1;

    MainWindow w(model1);

    w.show();
    return a.exec();
}
