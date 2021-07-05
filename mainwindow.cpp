#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db2= QSqlDatabase::addDatabase("QSQLITE");
    db2.setDatabaseName("try.db");
    if(!db2.open()){
        qDebug()<<"failed to open"<<db2.lastError();
    }else{
        qDebug()<<"open successfully";
    query =QSqlQuery:: QSqlQuery (db2);
    }


    QString sqlCreate = QString("create table try (id integer primary key autoincrement,"
                                "name varchar(20),"
                                "age int);");
    if(!query.exec(sqlCreate)){
        qDebug()<<"failed to create"<<db2.lastError();
    }else{
        qDebug()<<"successfully created";
    };

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int t =ui->lineEdit->text().toInt();

    QString sqlinsert = QString ("insert into try (id) values (%1);").arg(t);

    if (!query.exec(sqlinsert)){
    qDebug()<<"insert failed"<<db2.lastError();
    };
}
