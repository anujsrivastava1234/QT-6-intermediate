#include <QCoreApplication>
#include <QSettings>

void saveAge(QSettings *setting,QString group,QString name,int age)
{
    setting->beginGroup(group);
    setting->setValue(name,age);
    setting->endGroup();
}

int getAge(QSettings *setting,QString group,QString name)
{
    setting->beginGroup(group);
    if(!setting->contains(name))
    {
        qWarning()<<"Does not contain"<<name<<" in "<<group;
        setting->endGroup();
        return 0;
    }

    bool ok;
    qInfo()<<setting->value(name).toString();
    qInfo()<<setting->value(name).toInt(&ok);
    int value=setting->value(name).toInt(&ok);
    setting->endGroup();
    if(!ok)
    {
        qWarning()<<"Couldn't covert string to int";
        return 0;
    }

    return value;


}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setOrganizationDomain("QT");
    QCoreApplication::setOrganizationName("BridgeHealthCare");
    QCoreApplication::setApplicationName("Groups Tester");

    QSettings setting(QCoreApplication::organizationName(),QCoreApplication::applicationName());

    saveAge(&setting,"people","Anuj",22);
    qInfo()<<"Anuj (people) "<<getAge(&setting,"people","Anuj");
    return a.exec();
}
