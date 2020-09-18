#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stadiumvisitplan.h" // includes stadium.h

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

   /**
    * @brief SetIndex will set the index on the Pages stack widget that is part of the ui
    * @param passedIndex is the index of the page to be set on Pages stack widget
    */
    void SetIndex(int passedIndex);

private slots:
    // Menu Bar methods:
    void on_actiongo_triggered();

    // Welcome Page methods:
    void on_button_CustomPlanPage_clicked();
    void on_button_InformationPage_clicked();
    void on_button_PlanPage_clicked();

    // Plan Page methods
    void on_button_comericaPark_clicked();

    // Custom plan page methods
    void on_comboBox_selectStart_onCustom_currentIndexChanged(const QString &arg1);
    void on_pushButton_confirm_onCustom_clicked();

    // Purchase Souvenirs Page methods
    void on_pushButton_next_onPurchase_clicked();
    void on_pushButton_finish_onPurchase_clicked();
    void on_pushButton_confirm_onPurchase_clicked();
    void on_pushButton_cancel_onPurchase_clicked();

    // View Purchases and Plan Page methods
    void on_button_moveRight_clicked();
    void on_button_moveLeft_clicked();
    void on_button_restartPlan_clicked();

    // View Information page methods
    void on_button_both_clicked();
    void on_button_teams_clicked();
    void on_button_grass_clicked();
    void on_button_other_clicked();
    void on_button_allSurfaces_clicked();
    void on_comboBox_specificTypology_currentIndexChanged(int index);
    void on_button_AmericanLeague_clicked();
    void on_button_NationalLeague_clicked();
    void on_button_allLeague_clicked();
    void on_button_allSouvenirs_clicked();
    void on_comboBox_specificTeam_currentIndexChanged(int index);
    void on_button_allTypology_clicked();

    // Admin Welcome Page methods
    void on_button_souvenirManagement_clicked();
    void on_button_stadiumManagement_clicked();
    void on_button_loadFile_clicked();
    void on_button_viewTables_clicked();
    void on_button_logOut_clicked();

    // Admin Souvenir Management Page methods
    void on_comboBox_adminSouvTeam_currentTextChanged(const QString &arg1);
    void on_lineEdit_adminSouvName_textChanged(const QString &arg1);
    void on_pushButton_AddSouv_clicked();
    void on_pushButton_EditSov_clicked();
    void on_pushButton_DeleteSouv_clicked();
    void on_tableView_adminSouv_clicked(const QModelIndex &index);

    // Admin Stadium Management Page methods
    void on_doubleSpinBox_souvPrice_valueChanged(double arg1);
    void on_lineEdit_adminStad_textChanged(const QString &arg1);
    void on_tableView_adminStad_clicked(const QModelIndex &index);
    void on_pushButton_stadDelete_clicked();
    void on_pushButton_stadAdd_clicked();

    // View Database Tables Page methods
    // N/A


    void on_comboBox_selectTeam_currentTextChanged(const QString &arg1);

    void on_pushButton_AddInitialSouvenirs_clicked();

public slots:
    void go_to_previous_page();

private:
    Ui::MainWindow *ui;

    /**
     * @brief currentPlan the current plan that the user is making
     */
    StadiumVisitPlan *currentPlan;

    /**
     * @brief adminLoggedIn boolean true if admin is logged in
     */
    bool adminLoggedIn; // boolean if admin is logged in or not

    /**
     * @brief visitedPages a vector holding the indexes of the
     * visted pages in order. Used for going back to the previous page
     */
    std::vector<int> visitedPages;

    /**
     * @brief slideShowIndex the index of the current plan to view
     * on the summary page.
     */
    int slideShowIndex;

    /**
     * @brief currentStadium used to navigate stadiums in custom trip
     */
    int currentStadium = 0;
};

#endif // MAINWINDOW_H
