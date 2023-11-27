#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>
#include <QFileSystemWatcher>
#include <QDir>
class Watcher : public QObject
{
    Q_OBJECT
public:
    explicit Watcher(QObject *parent = nullptr);

signals:

public slots:
    void directoryChanged(const QString &path);
    void fileChanged(const QString &path);

private:
    QFileSystemWatcher fsw;

};

#endif // WATCHER_H
