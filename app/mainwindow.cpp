#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    appBrowser();
    buttonsInfo();

    QTimer *dateTimer = new QTimer(this);
    connect(dateTimer, SIGNAL(timeout()), this, SLOT(showDate()));
    dateTimer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appBrowser(){
//    QFile file(":/util/tests");
//    if(!file.open(QIODevice::ReadOnly)){
//        QMessageBox::information(0,"Info",file.errorString());
//    }
//    QTextStream in(&file);
//    ui->textBrowser->setText(in.readAll());
}

void MainWindow::showDate(){
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeText = dateTime.toString();
    ui->date->setText(dateTimeText);
}

void MainWindow::buttonsInfo(){
    ui->filesSort_button->setToolTip("<h4>Reverse Sort</h4>");
    ui->filesView_button->setToolTip("<h4>List & Grid View</h4>");
    ui->settings_button->setToolTip("<h4>Settings</h4>");
    ui->info_button->setToolTip("<h4>Info</h4>");
    ui->menuButton->setToolTip("<h4>Upload Files</h4>");

    ui->addMetadata_button->setToolTip("<h4>Add Metadata</h4>");
    ui->consultMetada_button->setToolTip("<h4>Consult Metadata</h4>");
    ui->removeMetadata_button->setToolTip("<h4>Remove Metadata</h4>");
    ui->modifyMetadata_button->setToolTip("<h4>Modify Metadata</h4>");

    ui->loggerButton->setToolTip("<h4>LogBack</h4>");

    QMenu *menu = new QMenu(this);
    menu->addAction("Upload Files");
    menu->addAction("Upload Folders");
    ui->menuButton->setMenu(menu);
}

void MainWindow::on_filesView_button_clicked()
{
    bool view = true;
    QIcon icon;
    if (view) icon.addFile(":/img/list.png");
    else icon.addFile(":/img/grid.png");
    ui->filesView_button->setIcon(icon);
}

void MainWindow::on_info_button_clicked()
{
    QMessageBox::about(this, "About MyInvincibleLibrary", "\n MyInvincibleLibrary corresponde al Proyecto III para el curso de Algoritmos y Estructuras de Datos II (CE2103), "
                                                                "el mismo consiste en la implementación de una aplicación para almacenamiento de galerías de imágenes en bases de datos no relacionales con redundancia. "
                                                                "El presente es un sistema cliente/servidor que permite el almacenamiento de galerías de imágenes con posibilidad de reponerse a fallos.\n\n"
                                                                "El sistema desarrollado cuenta con: \n"
                                                                "a. ServerLibrary: Permite a múltiples clientes acceder a la información de MyInvincibleLibrary. \n"
                                                                "b. RAID Library: permite el almacenamiento de las galerías y brinda redundancia al sistema. \n"
                                                                "c. Metadata DB: base de datos NoSQL para el almacenamiento de la metadata de las imágenes. \n"
                                                                "d. MyIDE: permite a los múltiples clientes gestionar la metadata de las galerías de imágenes. \n");
}
