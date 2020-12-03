#include "promotion.h"
#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>

Promotion::Promotion()
{

}
Promotion::Promotion (int ID , QString Date_Promo,QString promo )
{
    this->ID=ID;
    this->date_promo=Date_Promo ;
    this-> promo=promo ;
}


bool Promotion::ajouter()
{
    QSqlQuery query ;
    QString ress=QString::number(ID);
    query.prepare("insert into PROMOTION (ID,DATE_PROMO,PROMOTION) " "values(:id,:dp,:p)"); //commande

    query.bindValue(":id",ress);
    query.bindValue(":dp",date_promo);
    query.bindValue(":p",promo );

    return query.exec();
}



QSqlQueryModel *Promotion::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel ();


    model->setQuery("select *from PROMOTION"); //selection de la table à afficher
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_PROMO"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PROMOTION"));

    return model;


}


bool Promotion::supprimer(int id)
{  //supprimer suivant l'id
    QSqlQuery query ;
    QString ress=QString::number(id);
    query.prepare("delete from PROMOTION where ID=:id");
    query.bindValue(":id",id);
    return query.exec();

}

bool Promotion::modifier()
{
    QSqlQuery query ;
    QString ress=QString::number(ID);
    query.prepare("update PROMOTION set DATE_PROMO=:dp,PROMOTION=:P where ID=:id");

    query.bindValue(":id",ress);
    query.bindValue(":dp",date_promo);
    query.bindValue(":P",promo);


    return query.exec();

}




QSqlQueryModel *  Promotion::trie(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PROMOTION order by "+critere+" "+mode+""); //taayet il tab il mawjoud f base donnée
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));   //on est entrain de modifier par rapport au numéro de case
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_PROMO "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PROMOTION"));
return  model ;
}

QSqlQueryModel * Promotion::rechercher (const QString &aux)
{
QSqlQueryModel * model = new QSqlQueryModel();

  model->setQuery("select * from PROMOTION where ((ID || DATE_PROMO || PROMOTION ) LIKE '%"+aux+"%')");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_PROMO"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("PROMOTION "));

  return model;
}

