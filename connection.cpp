#include "connection.h"

connection::connection()
{

}



bool connection::creatconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Test");//inserer le nom de la source de données ODBC
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("system");//inserer mot de passe de cet utilisateur

if (db.open()) test=true;





    return  test;
}



void connection::closeconnection(){db.close();}
