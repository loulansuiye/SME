#include "treeviewwid.h"

#include<QStringList>
#include<QTableWidgetItem>
#include<QFile>
#include <QtWidgets>
#include<QDebug>

#include <QTreeView>
#include <QListView>
TreeViewWid::TreeViewWid(QTreeWidget *parent) : QTreeWidget(parent)
{
    tree = new QTreeWidget(this);
   // tree->setHeaderLabel (tr("目录"));
    //tree->setAutoFillBackground(true);
   // tree->setAnimated(true);
   // tree->hideColumn(1);
   // tree->showColumn(0);
   // tree->showFullScreen();
   // tree->autoFillBackground();

    //connect(tree,SIGNAL(QTreeWidget::selectionChanged()),this,SLOT(showFileInfo()));
    currentDir =QDir::current ();
    files=currentDir.entryList(QStringList(currentDir.currentPath ()),QDir::AllDirs|QDir::Files |QDir::AllEntries|QDir::Drives);
    //QDir dir = QDir::current ();
    showFiles(files);
    //showDir(dir);

}
void TreeViewWid::showDir (const QDir &directory)
{
    currentPath = directory.currentPath ();
   // connect(tree, SIGNAL(QTreeWidget::itemClicked(QTreeWidgetItem *, int)),this, SLOT(showFileInfo(QTreeWidgetItem *, int)));
    qDebug()<<"current directory path is "<<currentPath;
}

void TreeViewWid::showFiles(const QStringList &files)
{
      QFileSystemModel  *model= new QFileSystemModel;
      model->setRootPath(QDir::currentPath());

      QTreeView *tree_local = new QTreeView(this);
      tree_local->setModel(model);
      //tree_local->setRootIndex(model->index(QDir::currentPath()));
}
void TreeViewWid::showFileInfo(QTreeWidgetItem * item, int column)
{
      qDebug("clicked");
}

void TreeViewWid::showDirectory()
{

}

