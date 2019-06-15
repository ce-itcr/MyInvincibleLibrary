#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <QMenu>
#include <QFileDialog>

#include "settings.h"
#include "explorer.h"
#include "src/metadatamanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void appBrowser();
    void buttonsInfo();
    void uploadFiles();
    void uploadFilesAux();
    int view = 0;
    int sort = 0;
    int refresh = 0;

private:
    Ui::MainWindow *ui;

private slots:
    void showDate();
    void on_filesView_button_clicked();
    void on_info_button_clicked();
    void on_addMetadata_button_clicked();
    void on_consultMetada_button_clicked();
    void on_removeMetadata_button_clicked();
    void on_modifyMetadata_button_clicked();
    void on_loggerButton_clicked();
    void on_settings_button_clicked();
    void on_filesSort_button_clicked();
    void on_refreshButton_clicked();
};

#endif // MAINWINDOW_H
