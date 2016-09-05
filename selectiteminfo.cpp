#include "selectiteminfo.h"

SelectItemInfo::SelectItemInfo(QObject *parent) : QObject(parent)
{

}
QString SelectItemInfo::SelectDirInfo(QDir dir)
{
    QString dir_str = NULL;
    QDir dir_local = dir;
   if(dir_local.isRoot())
   {
       qDebug("..");
       dir_str += "..";

   }
   if(dir_local.isAbsolute())
   {
       //qDebug(dir_local.absolutePath());
       dir_str += dir_local.absolutePath();
   }
   return dir_str;
}

QString SelectItemInfo::SelectFileInfo(QFileInfo *fileinfo)
{
    QString Filestr = fileinfo->fileName();
    return Filestr;
}

QString SelectItemInfo::DefaultInfo(void)
{

}
