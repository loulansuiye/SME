#include "showwidget.h"
#include<QHBoxLayout>
#include<QSplitter>
ShowWidget::ShowWidget(QWidget *parent) : QWidget(parent)
{

    QVBoxLayout *main_layout = new QVBoxLayout(this);
    QHBoxLayout  *up_layout = new QHBoxLayout(this);

    treeViewWid = new TreeViewWid;
    treeViewWid->setMaximumWidth(parent->width()*0.4);
    edit_text  = new QTextEdit;
    listView = new QListView;
    listView->setMaximumWidth(parent->width()*0.2);

    up_layout->addWidget (treeViewWid);
    up_layout->addWidget (edit_text);
    up_layout->addWidget(listView);

    down_dist = new QTextEdit;
    down_dist->setMaximumHeight(100);

    main_layout->addLayout(up_layout);
    main_layout->addWidget(down_dist);
}
