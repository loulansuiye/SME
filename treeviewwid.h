#ifndef TREEVIEWWID_H
#define TREEVIEWWID_H
#include<QDir>
#include <QWidget>
#include<QTreeView>
#include<QTreeWidget>
#include<QTreeWidgetItem>
#include<QTreeWidgetItemIterator>
#include <QString>
#include <QDirModel>
QT_BEGIN_NAMESPACE
class QComboBox;
class QLabel;
class QPushButton;
class QTableWidget;
class QTableWidgetItem;
QT_END_NAMESPACE



class TreeViewWid : public QTreeWidget
{
    Q_OBJECT
public:
    explicit TreeViewWid(QTreeWidget *parent = 0);
    void showFiles(const QStringList &files);
    void showDir(const QDir &directory);
    QTreeWidget *tree;
signals:

public slots:
private:
    QDir currentDir;
    QStringList files;
    QTableWidget *filesTable;
    QDirModel *model ;
    QString currentPath;

};

#endif // TREEVIEWWID_H
