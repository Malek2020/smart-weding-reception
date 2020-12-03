#ifndef PLANNING_H
#define PLANNING_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class planning
{
private :
     QString  description, nom ,lieu;
     int    ID;


public:
    planning();
    planning(int,QString,QString,QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int id) ;
    bool modifier();
    void genererPDFplan();

 QSqlQueryModel *  trie(const QString &critere, const QString &mode );
 QSqlQueryModel * rechercher (const QString &aux);

};

#endif // PLANNING_H
