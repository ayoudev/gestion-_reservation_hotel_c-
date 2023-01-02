#include "transaction.h"
#include "ui_transaction.h"

transaction::transaction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transaction)
{
    ui->setupUi(this);
    this->setFixedSize(467,222);
    actualiser();


}





//void transaction::showEvent(QShowEvent *ev){
//    QMainWindow::showEvent(ev);
//    actualiser();
//    QMetaObject::invokeMethod(this, "afterWindowShown", Qt::ConnectionType::QueuedConnection);
//}

void transaction::actualiser(){
    QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE", "Data");
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
       query.prepare("select * from transactions");

       if(!query.exec())
           qDebug() << query.lastError().text() << query.lastQuery();
       else
           qDebug() << "Update was successful "<< query.lastQuery();

    // display db in tableView :
    QSqlQueryModel * nodal = new QSqlQueryModel();
    Database.open();
    QSqlQuery *qry = new QSqlQuery(Database);

    qry->prepare("select * from transactions");
    qry->exec();
    nodal->setQuery(*qry);
    ui->tableView->setModel(nodal);
    Database.close();
}





transaction::~transaction()
{
    delete ui;
}
