#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include <QTimer>
#include <QDateTime>
#include <QMenu>

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

private:
    Ui::MainWindow *ui;

private slots:
    void showDate();
    void on_filesView_button_clicked();
    void on_info_button_clicked();
};

#endif // MAINWINDOW_H
