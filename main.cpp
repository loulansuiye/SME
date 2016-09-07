#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
    a.setWindowIcon (QIcon(":/res/earth.png"));
    MainWindow w;
   // w.setMaximumSize (700,700);
    //w.setMinimumSize (900,900);
    w.showMaximized();
    w.show();

//      QDirModel model;
//       QTreeView tree;
//       tree.setModel(&model);
//       tree.setAnimated(false);
//       tree.setIndentation(20);
//       tree.setSortingEnabled(true);
//       tree.setWindowTitle(QObject::tr("Dir View"));
//       tree.resize(640, 480);
//       tree.show();

    return a.exec();
}
