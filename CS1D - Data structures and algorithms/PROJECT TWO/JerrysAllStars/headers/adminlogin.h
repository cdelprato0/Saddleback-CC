#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QMainWindow>

namespace Ui {
class AdminLogin;
}

class AdminLogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminLogin(QWidget *parent = 0);
    ~AdminLogin();

private slots:

    void on_loginButton_clicked();
    void on_cancelButton_clicked();
    void on_userNameLineEdit_returnPressed();
    void on_passwordLineEdit_returnPressed();

private:
    Ui::AdminLogin *ui;
    QWidget *p;
};

#endif // ADMINLOGIN_H
