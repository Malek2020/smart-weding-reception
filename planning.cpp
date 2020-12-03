#include "planning.h"
#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>

planning::planning()
{

}



planning::planning(int id , QString  desci,QString lieu ,QString nom)
{
    this->ID=id;
    this->description=desci ;
    this->lieu=lieu;
    this->nom=nom;


}

bool planning::ajouter()
{
    QSqlQuery query ;
    QString res=QString::number(ID);
    query.prepare("insert into PLANNING (ID,DESCRIPTION,LIEU,NOM) " "values(:id,:description,:lieu,:nom)"); //commande

    query.bindValue(":id",res);
    query.bindValue(":description",description);
    query.bindValue(":lieu",lieu);
    query.bindValue(":nom",nom);

    return query.exec();
}

QSqlQueryModel *planning::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel;


    model->setQuery("select *from PLANNING"); //selection de la table à afficher
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DESCRIPTION"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("lieu"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom"));

    return model;


}

bool planning::supprimer(int id)
{  //supprimer suvant l'id
    QSqlQuery query ;
    QString res=QString::number(id);
    query.prepare("delete from PLANNING where ID=:id");
    query.bindValue(":id",res);
    return query.exec();

}

bool planning::modifier()
{
    QSqlQuery query ;
    QString res=QString::number(ID);
    query.prepare("update PLANNING set DESCRIPTION=:descri,nom=:nom,lieu=:lieu where ID=:id");


    query.bindValue(":id",res);
    query.bindValue(":descri",description);
    query.bindValue(":nom",nom);
    query.bindValue(":lieu",lieu);

    return query.exec();



}

void  planning::genererPDFplan(){
//QDateTime datecreation = date.currentDateTime();
              //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                     QPdfWriter pdf("C:\\Users\\user2\\Desktop\\2A\\QT\\CRUD_EVENT\\pdfplan.pdf");
                     QPainter painter(&pdf);
                    int i = 4000;
                         painter.setPen(Qt::blue);
                         painter.setFont(QFont("Arial", 30));
                         painter.drawText(1100,1200,"Liste Des plannings");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial", 15));
                        // painter.drawText(1100,2000,afficheDC);
                         painter.drawRect(100,100,7300,2600);
                         //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                         painter.drawRect(0,3000,9600,500);
                         painter.setFont(QFont("Arial", 9));
                         painter.drawText(200,3300,"ID");
                         painter.drawText(1300,3300,"DESCRIPTION");
                         painter.drawText(2500,3300,"LIEU");
                         painter.drawText(2900,3300,"NOM");

                         QSqlQuery query;
                         query.prepare("select * from PLANNING");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(200,i,query.value(0).toString());
                             painter.drawText(1300,i,query.value(1).toString());
                             painter.drawText(2200,i,query.value(2).toString());
                             painter.drawText(3200,i,query.value(3).toString());

                            i = i + 500;
                         }


      int reponse = QMessageBox::Yes;
          if (reponse == QMessageBox::Yes)
          {
              QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
              notifyIcon->show();
              notifyIcon->setIcon(QIcon("icone.png"));

              notifyIcon->showMessage("GESTION DES  PLANNING ","Liste plannig pret dans PDF",QSystemTrayIcon::Information,15000);

              painter.end();
          }
          if (reponse == QMessageBox::No)
          {
               painter.end();
          }
}

QSqlQueryModel *  planning::trie(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PLANNING order by "+critere+" "+mode+"");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIEU"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM"));
return  model ;
}


  QSqlQueryModel * planning::rechercher (const QString &aux)
  {
QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from PLANNING where ((ID || DESCRIPTION || LIEU || NOM ) LIKE '%"+aux+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIEU "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM"));

    return model;
  }




