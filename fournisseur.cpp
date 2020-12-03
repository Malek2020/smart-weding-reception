#include "fournisseurs.h"

fournisseur::fournisseur()
{

}
fournisseur::fournisseur(QString id , QString nom, QString produit)
{  this->id=id;
    this->nom=nom;
    this->produit=produit;

}

bool fournisseur::ajouter()
{QSqlQuery query;




    query.prepare("insert into fournisseur (ID,NOM_DE_FOURNISSEUR,PRODUIT°" "values (:id,:nom,:produit)");
    query.bindValue(":id",id);

    query.bindValue(":nom_de_fournisseur",nom);
    query.bindValue(":produit",produit);


    return query.exec();


}

QSqlQueryModel *fournisseur::afficher()
{
    QSqlQueryModel *model =new QSqlQueryModel();

    model->setQuery("select *from founisseur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_de_fournisseur"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("produit"));



    return model ;
}

bool fournisseur::supprimer(QString id)
{
   QSqlQuery query ;
   query.prepare("Delete from fournisseur where id=:id");
   query.bindValue(":id",id);

   return query.exec();
}

bool fournisseur::modifier()
{
    QSqlQuery query;



    query.prepare("update fournisseur set ID=:id,produit=:produit,nom_de_fournisseur=:nom where ID=:id");

    query.bindValue(":id",id);

    query.bindValue(":produit",produit);
    query.bindValue(":nom_de_fournisseur",nom);
    return query.exec();

}

QSqlQueryModel *fournisseur::afficher(QString checki)
{
    QSqlQueryModel *model =new QSqlQueryModel();
    QSqlQuery query ;
   model->setQuery("Select * from fournisseur where ID like '%"+checki+"%' or NOM_DE_FOURNISSEUR like '%"+checki+"%' or PRODUIT like '%"+checki+"%'");



        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_DE_FOURNISSEUR"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRODUIT"));

    return model ;


}
