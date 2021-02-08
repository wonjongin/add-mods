#ifndef MINECRAFT_H
#define MINECRAFT_H

#include <QString>
#include <QDir>
#include <QtGlobal>
#include <QFile>

namespace Minecraft
{
    QString getMinecraftPath();
    void intoMinecraftPath(int type, QString oriPath);

} // namespace Minecraft


#endif