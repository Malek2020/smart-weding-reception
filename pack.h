#ifndef PACK_H
#define PACK_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include<QThread>

#include<QDate>
class pack
{private:
    QString id,nom;
    int prix,marge_de_benef;
public:
    pack();
    pack(QString,QString,int,int);



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString id) ;
    bool modifier();

 QSqlQueryModel * afficher(QString type);

 QSqlQueryModel *  trie(const QString &critere, const QString &mode );
};

#endif // PACK_H
