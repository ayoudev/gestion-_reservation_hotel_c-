#include "checkoutdialog.h"
#include "ui_checkoutdialog.h"
#include "QDebug"

CheckOutDialog::CheckOutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckOutDialog)
{
    ui->setupUi(this);
    this->setFixedSize(417,168);
    qDebug()<<"in constructor of CheckOutDialog";

}

void CheckOutDialog::readData()
{
    std::vector<int>rooms = Hotel::getInstance()->getRoomList("n");
    this->ui->cmbRoomList->clear();
    char flag = 0;
    for(std::vector<int>::iterator it = rooms.begin(); it!=rooms.end(); it++ )
    {
        this->ui->cmbRoomList->addItem(QString::number(*it));
        flag = 1;
    }

    if(flag==1) this->ui->btnCheckout->setEnabled(true);

}
CheckOutDialog::~CheckOutDialog()
{
    delete ui;
}

void CheckOutDialog::on_btnCancel_clicked()
{
    this->hide();
}

void CheckOutDialog::on_btnCheckout_clicked()
{

    //call hotels's checkout
    int  roomno = ui->cmbRoomList->currentText().toInt();

    if(roomno < 1)
    {
            QMessageBox::information(
            this,
            tr("Avertissement!"),
            tr("Pas de place pour vérifier") );
            return;
     }
    int ret = Hotel::getInstance()->CheckOut(roomno);

    QString msg = "";
    ret==0?msg="Success!":"Failure!";

    this->hide();

    if(ret == 0)
    {
        QMessageBox::information(
        this,
        tr("Succès!"),
        tr("La chambre a été libérée ! Dites merci au client") );
    }
}
