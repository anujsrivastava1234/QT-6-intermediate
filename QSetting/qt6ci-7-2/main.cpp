#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

void info(QSettings &setting)
{
    qInfo()<<"File : "<<setting.fileName();
    qInfo()<<"Keys : "<<setting.allKeys();
}

void save(QSettings &setting)
{
    setting.setValue("Test",123);
    qInfo()<<setting.status();
    qInfo()<<"saved";
}

void load(QSettings &setting)
{
    info(setting);

    qInfo()<<setting.value("test").toString();
    bool ok;
    qInfo()<<setting.value("test").toInt(&ok);
    if(!ok)
    {
        //something bad happended
        qInfo()<<"Couldn't covert into string";
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setOrganizationDomain("QT");
    QCoreApplication::setOrganizationName("BridgeHealthCare");
    QCoreApplication::setApplicationName("QSetting Tester");

    QSettings settings(QCoreApplication::organizationName(),QCoreApplication::applicationName());
    if(settings.allKeys().length()==0)
    {
        //save
        qInfo()<<"No setting...saving...";
        save(settings);
    }else {
        qInfo()<<"Loading the setting...";
            load(settings);
    }

    return a.exec();
}
