#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <QMenu>

#include "settings.h"
#include "explorer.h"

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
};

#endif // MAINWINDOW_H
