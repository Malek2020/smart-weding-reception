#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


class connection
{ QSqlDatabase db ; //db=database
public:
    connection(); //constructeur
    bool creatconnect(); //creer la conn
    void closeconnection(); // fermer

};

#endif // CONNECTION_H
