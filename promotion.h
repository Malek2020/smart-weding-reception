#ifndef PROMOTION_H
#define PROMOTION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Promotion
{
private :
     QString  date_promo, promo ;
     int    ID;


public:
    Promotion();
    Promotion (int, QString,QString);
    bool ajouter ();
    QSqlQueryModel * afficher();
    bool supprimer(int id) ;
    bool modifier();

 void genererPDFprom();

 QSqlQueryModel *  trie(const QString &critere, const QString &mode );
  QSqlQueryModel * rechercher (const QString &aux);
 };

#endif // PROMOTION_H

