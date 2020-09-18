#include "adminlogin.h" // includes QMainWindow
#include "mainwindow.h"
#include "ui_adminlogin.h"
#include <QDebug>

// made a smaller obj name for ease
typedef QRegularExpression QRegex;
typedef QRegularExpressionValidator QRegexValidator;

AdminLogin::AdminLogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminLogin)
{
    ui->setupUi(this);

    p = parent; // Used to close previous mainwindow

    QRegex usernameRegex("[a-z0-9A-Z]{1,20}");  // Accepts up to 20 characters (lowercase/uppercase letters and numbers ONLY)
    QRegexValidator *usernameValidator = new QRegexValidator(usernameRegex, this);
    QRegex passwordRegex("[a-zA-Z0-9!@#$%^&*]{1,15}"); // Accepts up to 15 characters (SOME SPECIAL CHARS BUT NO WHITESPACE)
    QRegexValidator *passwordValidator = new QRegexValidator(passwordRegex, this);

    ui->invalidCredentialsLabel->setVisible(false); // Will make error message label invisible
    ui->userNameLineEdit->setFocus(); // Will make the cursor land on first line edit
    ui->userNameLineEdit->setValidator(usernameValidator); // will make the regex used on this line edit
    ui->passwordLineEdit->setValidator(passwordValidator); // will make the regex used on this line edit
}

AdminLogin::~AdminLogin()
{
    delete ui;
}

void AdminLogin::on_cancelButton_clicked()
{
    this->close();
}

void AdminLogin::on_userNameLineEdit_returnPressed()
{
    // Will not do anything unless there is input in the lineedit
     on_loginButton_clicked();
}

void AdminLogin::on_passwordLineEdit_returnPressed()
{
    // Will not do anything unless there is input in the lineedit
     on_loginButton_clicked();
}

void AdminLogin::on_loginButton_clicked()
{
    MainWindow *helper; // Allows the method to open a new mainwindow

    QString userName = ui->userNameLineEdit->text(); //Creating a variable string to hold the username
    QString password = ui->passwordLineEdit->text(); //Creating a variable string to hold the password

    // Hard coded username and password
    QString userNameKey = "admin";
    QString passwordKey = "admin";

    if((userName == userNameKey) && (password == passwordKey)) {
        qDebug() << userName << " AND " << password << " ARE VALID ADMINISTRATOR CREDENTIALS!" << endl << endl;
        ui->invalidCredentialsLabel->setVisible(false);
        p->close();
        this->close();
        helper = new MainWindow(this);

        // ****** Set Page Number to 6 for Admin Welcome Page on mainwindow ******
        helper->SetIndex(6);

        helper->show();
    }
    else{
        qDebug() << userName << " AND " << password << " ARE INVALID ADMINISTRATOR CREDENTIALS..." << endl << endl;
        ui->invalidCredentialsLabel->setVisible(true); // Will make the error message visable.
    }
}
