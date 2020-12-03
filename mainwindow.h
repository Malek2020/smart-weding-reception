#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "pack.h"
#include "facture.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_rechercher__pack_textEdited(const QString &arg1);

    void on_lineEdit_rechercher__pack_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_rechercher__pack_textChanged(const QString &arg1);

    void on_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;
    pack pa;
    facture fac;
};
#endif // MAINWINDOW_H
