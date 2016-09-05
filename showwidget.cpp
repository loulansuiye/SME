#include "showwidget.h"
#include<QVBoxLayout>
#include<QSplitter>
ShowWidget::ShowWidget(QWidget *parent) : QWidget(parent)
{


   text  = new QTextEdit;
   treeViewWid = new TreeViewWid;
   treeViewWid->sizeAdjustPolicy ();
   treeViewWid->setContentsMargins(0,0,0,0);
   QSplitter *splitter_main = new QSplitter(this);
   splitter_main->addWidget (treeViewWid);
   splitter_main->adjustSize();
    QSize size_main = QSize(splitter_main->width (),splitter_main->height ());
  treeViewWid->resize (size_main);
   QSplitter *splitter_right = new QSplitter(splitter_main);
   splitter_right->setOpaqueResize (false);
   splitter_right->adjustSize();
   splitter_main->addWidget (text);
   QSize size = QSize(parent->width (),parent->height ());
   //splitter_right->resize (size);

   splitter_main->resize (size);
}
