#ifndef FACTURE_H
#define FACTURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class facture
{ private :
    QString ID,nom,date,type;
    int prix;
public:
    facture();
    facture(QString,QString,QString,QString,int);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString id) ;
    bool modifier();
    QSqlQueryModel * afficher(QString type);

    QSqlQueryModel * rechercher (const QString &aux);
     QSqlQueryModel *  trie(const QString &critere, const QString &mode );
};

#endif // FACTURE_H
