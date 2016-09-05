#ifndef SELECTITEMINFO_H
#define SELECTITEMINFO_H
#include<QDir>
#include<QFileInfo>
#include <QObject>
#include<QFile>
class SelectItemInfo : public QObject
{
    Q_OBJECT
public:
    explicit SelectItemInfo(QObject *parent = 0);
    QString SelectDirInfo(QDir dir);
    QString SelectFileInfo(QFileInfo *fileinfo);
    QString DefaultInfo(void);
signals:

public slots:
};

#endif // SELECTITEMINFO_H
