#include "watcher.h"

Watcher::Watcher(QObject *parent)
    : QObject{parent}
{
    fsw.addPath(QDir::currentPath());
    fsw.addPath(QDir::currentPath()+QDir::separator()+"text.txt");

    connect(&fsw,&QFileSystemWatcher::fileChanged,this,&Watcher::fileChanged);
    connect(&fsw,&QFileSystemWatcher::directoryChanged,this,&Watcher::directoryChanged);
}

void Watcher::directoryChanged(const QString &path)
{
    qInfo()<<"Dir Changed"<<path;
    if(fsw.directories().length())
    {
        qInfo()<<"Dirs that have changed";
        foreach (QString dir, fsw.directories()) {
            qInfo()<<dir;
        }
    }
}

void Watcher::fileChanged(const QString &path)
{
    qInfo()<<"File Changed"<<path;
    if(fsw.files().length())
    {
        qInfo()<<"Files that have changed";
        foreach (QString files, fsw.files()) {
            qInfo()<<files;
                       }
    }
}
