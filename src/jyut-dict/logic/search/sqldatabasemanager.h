#ifndef SQLDATABASEMANAGER_H
#define SQLDATABASEMANAGER_H

#include <QSqlDatabase>

// TODO: support for French Database

class SQLDatabaseManager
{
public:
    SQLDatabaseManager();
    ~SQLDatabaseManager();

    void openEnglishDatabase();
//    void openFrenchDatabase();

    QSqlDatabase getEnglishDatabase();
    bool isEnglishDatabaseOpen();

//    QSqlDatabase getFrenchDatabase();
//    bool isFrenchDatabaseOpen();

private:
    QSqlDatabase _EnglishDB;
//    QSqlDatabase _FrenchDB;
};

#endif // SQLDATABASEMANAGER_H
