#include <QCoreApplication>
#include <QStorageInfo>
#include <QFileInfo>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QStorageInfo root=QStorageInfo::root();
    qInfo()<<"Root : "<<root.rootPath();
    QDir dir(root.rootPath());
    foreach (QFileInfo fi,dir.entryInfoList( QDir::Dirs | QDir::NoDotAndDotDot)) {
        qInfo()<<fi.filePath();
    }

    qInfo()<<"-------------------------";
    foreach (QStorageInfo storage, QStorageInfo::mountedVolumes()) {
        qDebug() << "name:" << storage.name();
        qDebug() << "fileSystemType:" << storage.fileSystemType();
        qDebug() << "size:" << storage.bytesTotal()/1000/1000 << "MB";
        qDebug() << "availableSize:" << storage.bytesAvailable()/1000/1000 << "MB";
        qDebug() << "Device:" << storage.device();
        qDebug() << "isRoot:" << storage.isRoot();
    }

    return a.exec();
}
