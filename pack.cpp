#include "pack.h"

pack::pack()
{

}

pack::pack(QString id , QString nom, int prix, int benef)
{  this->id=id;
    this->nom=nom;
    this->prix=prix;
    this->marge_de_benef=benef;

}

bool pack::ajouter()
{QSqlQuery query;
    QString res = QString::number(prix);
    QString res2=QString::number(marge_de_benef);


    query.prepare("insert into PACK (ID,MARGE_DE_BENIFICE,PRIX,NOM)" "values (:id,:benef,:prix,:nom)");
    query.bindValue(":id",id);
    query.bindValue(":benef",res2);
    query.bindValue(":prix",res);
    query.bindValue(":nom",nom);


    return query.exec();


}

QSqlQueryModel *pack::afficher()
{
    QSqlQueryModel *model =new QSqlQueryModel();

    model->setQuery("select *from PACK");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("MARGE_DE_BENIFICE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOM"));


    return model ;
}

bool pack::supprimer(QString id)
{
   QSqlQuery query ;
   query.prepare("Delete from PACK where id=:id");
   query.bindValue(":id",id);

   return query.exec();
}

bool pack::modifier()
{
    QSqlQuery query;
    QString res = QString::number(prix);
    QString res2=QString::number(marge_de_benef);

    query.prepare("update PACK set MARGE_DE_BENIFICE=:benef,PRIX=:prix,NOM=:nom where ID=:id");

    query.bindValue(":id",id);
    query.bindValue(":benef",res2);
    query.bindValue(":prix",res);
    query.bindValue(":nom",nom);
    return query.exec();

}

QSqlQueryModel *pack::afficher(QString checki)
{
    QSqlQueryModel *model =new QSqlQueryModel();
    QSqlQuery query ;
   model->setQuery("Select * from PACK where ID like '%"+checki+"%' or MARGE_DE_BENIFICE like '%"+checki+"%' or PRIX like '%"+checki+"%' or NOM like '%"+checki+"%'");



        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("MARGE_DE_BENIFICE"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOM"));
    return model ;


}

QSqlQueryModel *  pack::trie(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PACK order by "+critere+" "+mode+"");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("marge_de_benefice "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));

    return model;
}

