#ifndef LOGIN_H
#define LOGIN_H
#include <QSqlDatabase>

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    MainWindow *ptrmain;
    QSqlDatabase db;
};

#endif // LOGIN_H
