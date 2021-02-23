#include <QCoreApplication>
#include <QtDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPluginLoader>
#include <QVariant>


bool testPlugin()
{
    qInfo()<<"Testing plugin";
    QPluginLoader myLoader("C:\Qt\5.14.2\mingw73_64\plugins\sqldrivers\qsqlodbc.dll");
    qInfo()<<myLoader.metaData();

    if (myLoader.load())
    {
        qInfo()<<"Loaded the plugin.";
        return true;
    }

    qInfo()<<myLoader.errorString();
    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (testPlugin())
    {
        //to do connect
    }

    return a.exec();
}
