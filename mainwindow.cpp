#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
//#include <QTableView>
//#include <QMovie>
#include "pack.h"
#include "facture.h"
#include <QPixmap>
#include <QMediaPlayer>
#include<QtMultimedia>
#include<QSound>
#include<QPrintDialog>
#include<QPrinter>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    /*controle de saisie*/
        ui->setupUi(this);
        //pack int
    ui->lineEdit_prix_pack->setValidator(new QIntValidator(100, 999, this));  // des nombres entre 100 et 999
     ui->lineEdit_marge_de_benefice_pack->setValidator(new QIntValidator(100, 999, this));
    //facture int
    ui->lineEdit_prix_facture->setValidator(new QIntValidator(100, 999, this));

    //pack varchar
    ui->lineEdit_id_pack->setMaxLength(100);
    ui->lineEdit_nom_pack->setMaxLength(10);//controle de saisie je ne peut pas depasser les 10 lettres

     //facture varchar
      ui->lineEdit_id_facture->setMaxLength(10);
      ui->lineEdit_nom_facture->setMaxLength(10);
      ui->lineEdit_date_facture->setMaxLength(10);



    QPixmap image("C:/Users/hp/Desktop/married.JPG");
    int w =ui->label_image->width();
    int h =ui->label_image->height();

    ui->label_image->setPixmap(image.scaled(w,h,Qt::KeepAspectRatio));

    QMovie *movie = new QMovie("C:/Users/hp/Desktop/source.gif");
    //QLabel *processLabel = new QLabel(this);

    int w2 =ui->label_animation->width();
    int h2 =ui->label_animation->height();
    movie->setScaledSize(QSize().scaled(w2,h2,Qt::KeepAspectRatio));
    ui->label_animation->setMovie(movie);
    movie->start();


    ui->comboBox_facture->addItem("facture client");
    ui->comboBox_facture->addItem("fiche de paie");
    ui->comboBox_facture->addItem("facture collaborateur");
    ui->comboBox_facture->addItem("facture de pack");



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Documents/projet_pack_facture/button-3.mp3"));
       player->setVolume(100);
       player->play();

    QString id =ui->lineEdit_id_pack->text();
    QString nom =ui->lineEdit_nom_pack->text();
    int prix =ui->lineEdit_prix_pack->text().toInt();
    int benef =ui->lineEdit_marge_de_benefice_pack->text().toInt();


    pack P(id,nom,prix,benef);
    bool test=P.ajouter();
    if (test)
    {   ui->tableView->setModel(P.afficher()) ;
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("ajout effectue\n"
                            "Clich cancel to exit ."),QMessageBox::Cancel );
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    ui->lineEdit_id_pack->setText("");
    ui->lineEdit_nom_pack->setText("");
    ui->lineEdit_prix_pack->setText("");
    ui->lineEdit_marge_de_benefice_pack->setText("");


}

void MainWindow::on_pushButton_3_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Documents/projet_pack_facture/button-3.mp3"));
       player->setVolume(100);
       player->play();

    QString id=ui->lineEdit_id_pack->text();
    bool test=pa.supprimer(id);
    if (test)
    {  ui->tableView->setModel(pa.afficher()) ;
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("yspr effectue\n"
                            "Clich cancel to exit ."),QMessageBox::Cancel );
    }

    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                    QObject::tr("suprfailed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select * from PACK where ID ='"+val+"' or MARGE_DE_BENIFICE='"+val+"' or NOM='"+val+"' or PRIX='"+val+"' ");

        if (query.exec())
        {  while(query.next())
            {
                ui->lineEdit_id_pack->setText(query.value(0).toString());
                ui->lineEdit_marge_de_benefice_pack->setText(query.value(1).toString());
                ui->lineEdit_prix_pack->setText(query.value(2).toString());
                ui->lineEdit_nom_pack->setText(query.value(3).toString());

                       }
        }


}

void MainWindow::on_pushButton_4_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Documents/projet_pack_facture/button-3.mp3"));
       player->setVolume(100);
       player->play();


    ui->tableView->setModel(pa.afficher());
}

void MainWindow::on_pushButton_2_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Documents/projet_pack_facture/button-3.mp3"));
       player->setVolume(100);
       player->play();


    QString id=ui->lineEdit_id_pack->text();
    QString nom=ui->lineEdit_nom_pack->text();
    int prix=ui->lineEdit_prix_pack->text().toInt();
    int benef =ui->lineEdit_marge_de_benefice_pack->text().toInt();

pack P(id,nom,prix,benef);
bool test=P.modifier();
 if (test)
 {   ui->tableView->setModel(pa.afficher()) ;
     QMessageBox::information(nullptr,QObject::tr("ok"),
             QObject::tr("ajout effectue\n"
                         "Clich cancel to exit ."),QMessageBox::Cancel );
 }
 else
     QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                 QObject::tr("connection failed.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

 ui->lineEdit_id_pack->setText("");
 ui->lineEdit_nom_pack->setText("");
 ui->lineEdit_prix_pack->setText("");
 ui->lineEdit_marge_de_benefice_pack->setText("");


}

void MainWindow::on_pushButton_5_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Documents/projet_pack_facture/button-3.mp3"));
       player->setVolume(100);
       player->play();

    QString type=ui->lineEdit_rechercher__pack->text();
       ui->tableView->setModel(pa.afficher(type));
}

void MainWindow::on_pushButton_6_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Documents/projet_pack_facture/button-3.mp3"));
       player->setVolume(100);
       player->play();

    ui->tableView_2->setModel(fac.afficher());
}

void MainWindow::on_pushButton_7_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Documents/projet_pack_facture/button-3.mp3"));
       player->setVolume(100);
       player->play();

    QString id =ui->lineEdit_id_facture->text();
    QString nom =ui->lineEdit_nom_facture->text();
    int prix =ui->lineEdit_prix_facture->text().toInt();
    QString date =ui->lineEdit_date_facture->text();
    QString type=ui->comboBox_facture->currentText();



    facture fa(id,type,nom,date,prix);
    bool test=fa.ajouter();
    if (test)
    {   ui->tableView_2->setModel(fac.afficher()) ;
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("ajout effectue\n"
                            "Clich cancel to exit ."),QMessageBox::Cancel );
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    ui->lineEdit_id_pack->setText("");
    ui->lineEdit_nom_pack->setText("");
    ui->lineEdit_prix_pack->setText("");
    ui->lineEdit_marge_de_benefice_pack->setText("");

}

void MainWindow::on_pushButton_8_clicked()
{  /*sound*/
    QMediaPlayer *player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Documents/projet_pack_facture/button-3.mp3"));
    player->setVolume(100);
    player->play();

    QString id =ui->lineEdit_id_facture->text();
    bool test=fac.supprimer(id);
    if (test)
    {  ui->tableView_2->setModel(fac.afficher()) ;
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("yspr effectue\n"
                            "Clich cancel to exit ."),QMessageBox::Cancel );
    }

    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                    QObject::tr("suprfailed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_9_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Documents/projet_pack_facture/button-3.mp3"));
       player->setVolume(100);
       player->play();


    QString id =ui->lineEdit_id_facture->text();
    QString nom =ui->lineEdit_nom_facture->text();
    int prix =ui->lineEdit_prix_facture->text().toInt();
    QString date =ui->lineEdit_date_facture->text();
    QString type=ui->comboBox_facture->currentText();



    facture fa(id,type,nom,date,prix);
    bool test=fa.modifier();
     if (test)
     {   ui->tableView->setModel(fac.afficher()) ;
         QMessageBox::information(nullptr,QObject::tr("ok"),
                 QObject::tr("ajout effectue\n"
                             "Clich cancel to exit ."),QMessageBox::Cancel );
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                     QObject::tr("connection failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     ui->lineEdit_id_pack->setText("");
     ui->lineEdit_nom_pack->setText("");
     ui->lineEdit_prix_pack->setText("");
     ui->lineEdit_marge_de_benefice_pack->setText("");
}

void MainWindow::on_pushButton_10_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Documents/projet_pack_facture/button-3.mp3"));
       player->setVolume(100);
       player->play();


    QString critere=ui->comboBox->currentText();
               QString mode;
               if (ui->checkBox->checkState()==false)
           {
                    mode="DESC";
           }
                else if(ui->checkBox_2->checkState()==false)
                {
                    mode="ASC";
                }
           ui->tableView->setModel(pa.trie(critere,mode));
    }

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

    if(ui->lineEdit->text() == "")
              {
                  ui->tableView_2->setModel(fac.afficher());
              }
              else
              {
                   ui->tableView_2->setModel(fac.rechercher(ui->lineEdit->text()));
              }
}









void MainWindow::on_pushButton_11_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Documents/projet_pack_facture/button-3.mp3"));
    player->setVolume(100);
    player->play();


 QString critere=ui->comboBox_facture->currentText();
            QString mode;
            if (ui->checkBox_4 checkState()==false)
        {
                 mode="DESC";
        }
             else if(ui->checkBox_3->checkState()==false)
             {
                 mode="ASC";
             }
        ui->tableView->setModel(fac.trie(critere,mode));
}
