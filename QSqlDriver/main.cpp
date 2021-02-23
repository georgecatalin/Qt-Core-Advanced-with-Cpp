#include <QCoreApplication>

#include <QDebug>
#include <QtSql>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo()<<"Inspecting drivers.";

    foreach(QString driver,QSqlDatabase::drivers())
    {
        qInfo()<<driver;

        QSqlDatabase myDb=QSqlDatabase::addDatabase(driver); //adds the default driver

        QSqlDriver * myDriver=myDb.driver();


        // Whether the driver supports SQL transactions.
        qInfo()<<"Has Transactions:"<<myDriver->hasFeature(QSqlDriver::Transactions);

        // Whether the database is capable of reporting the size of a query.
        qInfo()<<"Database is capable of reporting the size of a query: "<<myDriver->hasFeature(QSqlDriver::QuerySize);

        // Whether the driver supports Binary Large Object fields (BLOB)
        qInfo()<<"Whether the driver supports BLOB: "<<myDriver->hasFeature(QSqlDriver::BLOB);

        // Whether the driver supports Unicode strings if the database server does.
        qInfo()<<"Whether the driver supports Unicode strings if the database supports:"<<myDriver->hasFeature(QSqlDriver::Unicode);

        // Whether the driver supports prepared query execution.
        qInfo()<<"Whether the driver supports prepared query execution: "<<myDriver->hasFeature(QSqlDriver::PreparedQueries);

        // Whether the driver supports the use of named placeholders.
        qInfo()<<"Whether the driver supports the use of named placeholders."<<myDriver->hasFeature(QSqlDriver::NamedPlaceholders);

        // Whether the driver supports the use of positional placeholders.
        qInfo()<<"Whether the driver supports the use of positional placeholders. "<< myDriver->hasFeature(QSqlDriver::PositionalPlaceholders);

        // Whether the driver supports returning the Id of the last touched row.
        qInfo()<<"Whether the driver supports returning the Id of the last touched row: "<<myDriver->hasFeature(QSqlDriver::LastInsertId);

        // Whether the driver supports batched operations
        qInfo()<<"Whether the driver supports batched operations: "<<myDriver->hasFeature(QSqlDriver::BatchOperations);

        // Whether the driver disallows a write lock on a table while other queries have a read lock on it.
        qInfo()<<"Whether the driver disallows a write lock on a table while other queries have a read lock on it: "<<myDriver->hasFeature(QSqlDriver::SimpleLocking);

        // Whether the driver allows fetching numerical values with low precision
        qInfo()<<"Whether the driver allows fetching numerical values with low precision: "<<myDriver->hasFeature(QSqlDriver::LowPrecisionNumbers);

        // Whether the driver supports database event notifications.
        qInfo()<<"Whether the driver supports database event modifications: "<<myDriver->hasFeature(QSqlDriver::EventNotifications);

        // Whether the driver can do any low-level resource cleanup
        qInfo()<<"Whether the driver can do any low-level resource cleanup :"<<myDriver->hasFeature(QSqlDriver::FinishQuery);

        // Whether the driver can access multiple result sets returned from batched statements or stored procedures.
        qInfo()<<"Whether the driver can access multiple result sets returned from batched statements or stored procedures."<<myDriver->hasFeature(QSqlDriver::MultipleResultSets);

        // Whether the driver allows cancelling a running query.
        qInfo()<<"Whether the driver allows cancelling a running query: "<<myDriver->hasFeature(QSqlDriver::CancelQuery);
        qInfo()<<"";

    }

    return a.exec();
}
