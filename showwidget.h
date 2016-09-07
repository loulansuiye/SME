#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>
#include<QTextEdit>
#include"treeviewwid.h"
#include<QListView>
class ShowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ShowWidget(QWidget *parent = 0);
    QTextEdit *edit_text;
    QTextEdit *down_dist;
signals:

public slots:
private:
     TreeViewWid *treeViewWid;
     QListView  *listView;
};

#endif // SHOWWIDGET_H
