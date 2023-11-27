#include <QCoreApplication>
#include <QSettings>
#include <QStringList>
#include <QRandomGenerator>

void saveAge(QSettings *setting,QString group,QString name,int age)
{
    setting->beginGroup(group);
    setting->setValue(name,age);
    setting->endGroup();
}

int getAge(QSettings *settings,QString group,QString name)
{
    settings->beginGroup(group);
    if(!settings->contains(name))
    {
        qWarning()<<"Does not contain"<<name<<"in"<<group;
        settings->endGroup();
        return 0;
    }

    bool ok;
    int value=settings->value(name).toInt(&ok);
    settings->endGroup();
    if(!ok)
    {
        qInfo()<<"Couldn't convert string to int";
        return 0;
    }

    return value;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setOrganizationDomain("QT");
    QCoreApplication::setOrganizationName("BridgeHealthCare");
    QCoreApplication::setApplicationName("Navigating Groups");

    QSettings settings(QCoreApplication::organizationName(),QCoreApplication::applicationName());

    QStringList list;
    list<<"Bryan"<<"Tammy"<<"Heather"<<"Chris";

    foreach (QString person, list) {
        int value=QRandomGenerator::global()->bounded(100);
        saveAge(&settings,"People",person,value);
    }

    //SAVE the changes
    settings.sync();
    qInfo()<<"File : "<<settings.fileName();

    foreach (QString group, settings.childGroups())
    {
        settings.beginGroup(group);
        qInfo()<<"Groups : "<<group;
        foreach (QString key, settings.childKeys()) {
            qInfo()<<"...key"<<key<<" = "<<settings.value(key).toString();
        }

        settings.endGroup();
    }

    return a.exec();
}
