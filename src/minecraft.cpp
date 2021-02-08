#include "minecraft.h"
#include <QDebug>


QString Minecraft::getMinecraftPath()
{
    QString path;
    #ifdef Q_OS_WIN
        QString home = QDir::homePath();
        QString appdata = qEnvironmentVariable("APPDATA")
        path = appdata + "\\.minecraft";
    #endif
    #ifdef Q_OS_MACOS
        QString home = QDir::homePath();
        path = home + "/Library/Application Support/minecraft";
    #endif
    #ifdef Q_OS_LINUX
        QString home = QDir::homePath();
        path = home + "/.minecraft";
    #endif

    return path;
}

void Minecraft::intoMinecraftPath(int type, QString oriPath)
{
    /*
        type 은 0이 모드 1이 리소스 팩
    */

    QStringList pathList = oriPath.split("/");
    QString fileName = pathList.at(pathList.length()-1);

   QString minePath;
   switch (type)
   {
   case 0:
       minePath = Minecraft::getMinecraftPath() + "/mods/" + fileName;
       break;
   case 1:
       minePath = Minecraft::getMinecraftPath() + "/resourcepacks/" + fileName;
       break;
   default:
       break;
   }
    QFile::copy(oriPath, minePath);
    qDebug() << oriPath << " -> " << minePath;
}