#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "planning.h"
#include "promotion.h"
#include <QPixmap>
#include <QMovie>
#include <QMediaPlayer>
#include<QtMultimedia>
#include<QSound>
#include<QPrintDialog>
#include<QPrinter>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*controle de saisie*/
        ui->setupUi(this);
        //planning int
    ui->lineEdit_id_planning->setValidator(new QIntValidator(100, 999, this));  // des nombres entre 100 et 999
    //promotion int
    ui->lineEdit_id_promotion->setValidator(new QIntValidator(100, 999, this));

    //planning varchar
    ui->lineEdit_description_planning->setMaxLength(100);
    ui->lineEdit_nom_planning->setMaxLength(10);//controle de saisie je ne peut pas depasser les 10 lettres
    ui->lineEdit_lieu_planning->setMaxLength(10);
     //promotion varchar
      ui->lineEdit_date_de_promotion->setMaxLength(10);
      ui->lineEdit_promotion_promotion->setMaxLength(10);




    QPixmap image("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/logo_groupe.png");
    int w2=ui->label_image->width();
    int h2=ui->label_image->height();

    ui->label_image->setPixmap(image.scaled(w2,h2,Qt::KeepAspectRatio));


    QMovie *movie=new QMovie("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/source.gif");
    int w=ui->label_image_gif->width();
    int h=ui->label_image_gif->height();
    movie->setScaledSize(QSize().scaled(w,h,Qt::KeepAspectRatio));
    ui->label_image_gif->setMovie(movie);
    movie->start();




}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
       player->setVolume(100);
       player->play();


    int id =ui->lineEdit_id_planning->text().toInt();
    QString descri =ui->lineEdit_description_planning->text();
    QString lieu =ui->lineEdit_lieu_planning->text();
    QString nom =ui->lineEdit_nom_planning->text();

    planning pla(id,descri,lieu,nom);
    bool test = pla.ajouter();
    if (test)
    {   ui->tableView->setModel(plan.afficher()) ;
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("ajout effectue\n"
                            "Clich cancel to exit ."),QMessageBox::Cancel );
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{  QString val =ui->tableView->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select *from PLANNING where ID='"+val+"' or DESCRIPTION='"+val+"' or NOM='"+val+"' or LIEU='"+val+"'");

    if(query.exec())
    { while(query.next())
        {  ui->lineEdit_id_planning->setText(query.value(0).toString());
           ui->lineEdit_description_planning->setText(query.value(1).toString());
           ui->lineEdit_lieu_planning->setText(query.value(2).toString());
           ui->lineEdit_nom_planning->setText(query.value(3).toString());

        }

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
       player->setVolume(100);
       player->play();

    int id=ui->lineEdit_id_planning->text().toInt();


    bool test=plan.supprimer(id);
    if (test)
    {  ui->tableView->setModel(plan.afficher()) ;
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("yspr effectue\n"
                            "Clich cancel to exit ."),QMessageBox::Cancel );
    }

    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                    QObject::tr("suprfailed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton_3_clicked()
{  /*sound*/
    QMediaPlayer *player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
    player->setVolume(100);
    player->play();

    int id=ui->lineEdit_id_planning->text().toInt();
     QString descr=ui->lineEdit_description_planning->text();
     QString lieu=ui->lineEdit_lieu_planning->text();
     QString nom=ui->lineEdit_nom_planning->text();

     planning pla(id,descr,lieu,nom);
     bool test=pla.modifier();
     if (test)
     {   ui->tableView->setModel(plan.afficher());
         QMessageBox::information(nullptr,QObject::tr("ok"),
                 QObject::tr("ajout effectue\n"
                             "Clich cancel to exit ."),QMessageBox::Cancel );
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                     QObject::tr("connection failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     ui->lineEdit_id_planning->setText("");
     ui->lineEdit_nom_planning->setText("");
     ui->lineEdit_lieu_planning->setText("");
     ui->lineEdit_description_planning->setText("");


}

void MainWindow::on_pushButton_4_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
       player->setVolume(100);
       player->play();

    ui->tableView->setModel(plan.afficher());
}

void MainWindow::on_pushButton_10_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
       player->setVolume(100);
       player->play();

    int id =ui->lineEdit_id_promotion->text().toInt();
    QString date =ui->lineEdit_date_de_promotion->text();
    QString promo =ui->lineEdit_promotion_promotion->text();

    Promotion pro(id,date,promo);
    bool test = pro.ajouter();
    if (test)
    {  ui->tableView_promotion->setModel(prom.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("ajout effectue\n"
                            "Clich cancel to exit ."),QMessageBox::Cancel );
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_9_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
       player->setVolume(100);
       player->play();

    ui->tableView_promotion->setModel(prom.afficher());
}

void MainWindow::on_pushButton_11_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
       player->setVolume(100);
       player->play();

    int id =ui->lineEdit_id_promotion->text().toInt();

    bool test=prom.supprimer(id);
    if (test)
    {  ui->tableView_promotion->setModel(prom.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("ajout effectue\n"
                            "Clich cancel to exit ."),QMessageBox::Cancel );
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_12_clicked()
{
    /*sound*/
    QMediaPlayer *player = new QMediaPlayer;

    player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
    player->setVolume(100);
    player->play();

    int id =ui->lineEdit_id_promotion->text().toInt();
    QString date =ui->lineEdit_date_de_promotion->text();
    QString promo =ui->lineEdit_promotion_promotion->text();
    Promotion pro(id,date,promo);
    bool test=pro.modifier();


    if (test)
    {  ui->tableView_promotion->setModel(prom.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("ajout effectue\n"
                            "Clich cancel to exit ."),QMessageBox::Cancel );
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_tableView_promotion_activated(const QModelIndex &index)
{
    QString val =ui->tableView_promotion->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select * from PROMOTION where ID='"+val+"' or DATE_PROMO='"+val+"' or PROMOTION='"+val+"'");

        if(query.exec())
        { while(query.next())
            {  ui->lineEdit_id_promotion->setText(query.value(0).toString());
               ui->lineEdit_date_de_promotion->setText(query.value(1).toString());
               ui->lineEdit_promotion_promotion->setText(query.value(2).toString());


            }

        }
}


void MainWindow::on_pushButton_5_clicked()
{
    plan.genererPDFplan();


}


void MainWindow::on_pushButton_6_clicked()
{
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
       ui->tableView_promotion->setModel(prom.trie(critere,mode));
}

void MainWindow::on_pushButton_7_clicked()
{
    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
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
       ui->tableView->setModel(plan.trie(critere,mode));
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if(ui->lineEdit->text() == "")
            {
                ui->tableView->setModel(plan.afficher());
            }
            else
            {
                 ui->tableView->setModel(plan.rechercher(ui->lineEdit->text()));
            }

}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    if(ui->lineEdit->text() == "")
            {
                ui->tableView_promotion->setModel(plan.afficher());
            }
            else
            {
                 ui->tableView_promotion->setModel(plan.rechercher(ui->lineEdit->text()));
            }

}

void MainWindow::on_pushButton_13_clicked()
{
    /*impression pdf*/

    /*sound*/
       QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
       player->setVolume(100);
       player->play();


          {
              QString strStream;
                      QTextStream out(&strStream);
                      const int rowCount = ui->tableView_promotion->model()->rowCount();
                      const int columnCount =ui->tableView_promotion->model()->columnCount();

                      out <<  "<html>\n"
                              "<head>\n"
                              "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                              <<  QString("<title>%1</title>\n").arg("PROMOTION")
                              <<  "</head>\n"
                              "<body bgcolor=#D3D3D3 link=#5000A0>\n"
                                  "<img src='C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/logo_groupe' width='100' height='100'>\n"
                                  "<h1>Liste de promotion </h1>"



                                  "<table border=1 cellspacing=0 cellpadding=2>\n";


                      // headers
                          out << "<thead><tr bgcolor=#f0f0f0>";
                          for (int column = 0; column < columnCount; column++)
                              if (!ui->tableView_promotion->isColumnHidden(column))
                                  out << QString("<th>%1</th>").arg(ui->tableView_promotion->model()->headerData(column, Qt::Horizontal).toString());
                          out << "</tr></thead>\n";
                          // data table
                             for (int row = 0; row < rowCount; row++) {
                                 out << "<tr>";
                                 for (int column = 0; column < columnCount; column++) {
                                     if (!ui->tableView_promotion->isColumnHidden(column)) {
                                         QString data = ui->tableView_promotion->model()->data(ui->tableView_promotion->model()->index(row, column)).toString().simplified();
                                         out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                     }
                                 }
                                 out << "</tr>\n";
                             }
                             out <<  "</table>\n"
                                 "</body>\n"
                                 "</html>\n";

                             QTextDocument *document = new QTextDocument();
                             document->setHtml(strStream);

                             QPrinter printer;

                             QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                             if (dialog->exec() == QDialog::Accepted) {
                                 document->print(&printer);
                          }
          }
}
