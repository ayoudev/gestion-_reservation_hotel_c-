#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
     this->setFixedSize(671,619);
    ptrmain = new MainWindow(this);

    QPixmap pm("c:/Hotel_Management_in_QT/image1.jpg"); // <- path to image file
    ui->label_4->setPixmap(pm);
    ui->label_4->setScaledContents(true);


//    QPixmap pm2("c:/Hotel_Management_in_QT/icons8-male-user-50.png"); // <- path to image file
//    ui->toolButton->setPixmap(pm2);
//    ui->toolButton->setScaledContents(true);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{

    QString username,password;

    username=ui->lineEdit_userName->text();
    password=ui->lineEdit_Password->text();
    QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE", "DATA");
       Database.setDatabaseName("c:/Hotel_Management_in_QT/hotelmanagement.db");
       if(QFile::exists("c:/Hotel_Management_in_QT/hotelmanagement.db"))
           qDebug() << "DB file exist";
       else
          qDebug() << "DB file doesn't exists";

       if (!Database.open())
           qDebug() << Database.lastError().text();
       else
           qDebug() << "Database loaded successfull!";

       QSqlQuery query(Database);
       query.prepare("select * from login where username='"+username+"' and password='"+password+"'");
       if(query.exec()){
           if(query.next()){
               ptrmain->show();
               // this->setVisible(false);
           }else{
                qDebug() << query.lastError().text() << query.lastQuery();
           }

       }

//       if(!query.exec())
//           qDebug() << query.lastError().text() << query.lastQuery();
//       else{
//           qDebug() << "Ups sucdate wacessful "<< query.lastQuery();
//           ptrmain->show();
//            this->setVisible(false);
//       }


}

