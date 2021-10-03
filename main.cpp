#include "mainwindow.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString strPath = QApplication::applicationDirPath();
    strPath += "/icon6.png";
    a.setWindowIcon(QIcon(strPath));

    return a.exec();
}
