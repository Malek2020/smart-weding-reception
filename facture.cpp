#include "facture.h"
#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>

facture::facture()
{

}

facture::facture(QString ID, QString type, QString nom, QString date, int prix)
{
    this->ID=ID;
    this->type=type;
    this->nom=nom;
    this->date=date;
    this->prix=prix;

}

bool facture::ajouter()
{
    QSqlQuery query;
        QString res = QString::number(prix);



        query.prepare("insert into FACTURES (ID,TYPE,NOM,DATE_,prix)" "values (:id,:type,:nom,:date,:prix)");
        query.bindValue(":id",ID);
        query.bindValue(":type",type);
        query.bindValue(":nom",nom);
        query.bindValue(":date",date);
        query.bindValue(":prix",res);


        return query.exec();
}

QSqlQueryModel *facture::afficher()
{
    QSqlQueryModel *model =new QSqlQueryModel();

    model->setQuery("select *from FACTURES");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE"));


    return model ;
}

bool facture::supprimer(QString id)
{
   QSqlQuery query ;
   query.prepare("Delete from FACTURES where id=:id");
   query.bindValue(":id",id);

   return query.exec();
}

bool facture::modifier()
{
    QSqlQuery query;
    QString res = QString::number(prix);


    query.prepare("update FACTURES set prix=:prix,type=:type,DATE_=:date where id=:id");

    query.bindValue(":id",ID);

    query.bindValue(":prix",res);
    query.bindValue(":type",type);
     query.bindValue(":date",date);
    return query.exec();

}

QSqlQueryModel *facture::afficher(QString checki)
{
    QSqlQueryModel *model =new QSqlQueryModel();
    QSqlQuery query ;
   model->setQuery("Select * from FACTURES where ID like '%"+checki+"%' or NOM like '%"+checki+"%' or DATE_ like '%"+checki+"%' or TYPE like '%"+checki+"%' or PRIX like '%"+checki+"%'");



        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
           model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOM"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX"));
    return model ;


}



QSqlQueryModel *  facture::trie(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from factures order by "+critere+" "+mode+"");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("type "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("marge_de_benefice"));

    return model;
}
