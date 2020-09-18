#include "mainwindow.h"
#include "database.h" // **testing**
#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    //Enables scaling for high DPI displays (don't remove)
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    MainWindow w;

    // Loading the font
    if(QFontDatabase::addApplicationFont("./assets/fish_chips.ttf") >= 0){
        qDebug() << "Font was opened correctly\n";
    }else{
        qDebug() << "Font was not opened correctly\n";
    }

    // Setting the cursor for the projuct.
    a.setOverrideCursor(QCursor(QPixmap("assets/cursor.png")));

    // Setting window icon
    QIcon icon("assets/logo.png");
    a.setWindowIcon(icon);

    // Will test the database and see if it opens or not.
    Database::getInstance();

    w.show();

    return a.exec();
}
