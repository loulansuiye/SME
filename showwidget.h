#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>
#include<QTextEdit>
#include"treeviewwid.h"
class ShowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ShowWidget(QWidget *parent = 0);
    QTextEdit *text;
signals:

public slots:
private:
     TreeViewWid *treeViewWid;
};

#endif // SHOWWIDGET_H
