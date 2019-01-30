#include "sqldatabasemanager.h"

#include <QCoreApplication>
#include <QFile>

// Todo: move database to QStandardPaths::AppDataLocation, a cross-platform
// solution for data files.

SQLDatabaseManager::SQLDatabaseManager()
{
}

void SQLDatabaseManager::openEnglishDatabase()
{
    if (!_EnglishDB.isOpen()) {
        _EnglishDB = QSqlDatabase::addDatabase("QSQLITE");
#ifdef __APPLE__
        _EnglishDB.setDatabaseName(QCoreApplication::applicationDirPath() + "/../Resources/eng.db");
#else
        _EnglishDB.setDatabaseName(QCoreApplication::applicationDirPath() + "./eng.db");
#endif
        _EnglishDB.open();
    }
}

//void SQLDatabaseManager::openOtherDatabase()
//{
//    _FrenchDB = QSqlDatabase::addDatabase("QSQLITE");
//    _FrenchDB.setDatabaseName(QCoreApplication::applicationDirPath() + "/../Resources/fra.db");
//    _FrenchDB.open();
//}

QSqlDatabase SQLDatabaseManager::getEnglishDatabase()
{
    return _EnglishDB;
}

bool SQLDatabaseManager::isEnglishDatabaseOpen()
{
    return _EnglishDB.isOpen();
}

//QSqlDatabase SQLDatabaseManager::getFrenchDatabase()
//{
//    return _FrenchDB;
//}

//bool SQLDatabaseManager::isFrenchDatabaseOpen()
//{
//    return _FrenchDB.isOpen();
//}

SQLDatabaseManager::~SQLDatabaseManager()
{
    _EnglishDB.close();
//    _FrenchDB.close();
}
