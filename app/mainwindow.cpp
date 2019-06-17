#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    appBrowser();
    buttonsInfo();
    frameStyle();

    QTimer *dateTimer = new QTimer(this);
    connect(dateTimer, SIGNAL(timeout()), this, SLOT(showDate()));
    dateTimer->start();
    ClientInterface::client = Client::getInstance()->initHost("192.168.0.27", "9080", "MyIncibleLibrary_war_exploded");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appBrowser(){
}

void MainWindow::showDate(){
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeText = dateTime.toString();
    ui->date->setText(dateTimeText);
}

void MainWindow::uploadFiles(){
    Explorer explorer;
    explorer.setModal(true);
    explorer.exec();
}

void MainWindow::addImages(){
    AddImages AddImagesWindow;
    AddImagesWindow.setModal(true);
    AddImagesWindow.exec();
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

    QPixmap upload_icon(":/img/assets/upload_files_icon.png");

    QMenu *menu = new QMenu(this);
    QAction *uploadFiles = new QAction(upload_icon,"Upload Files", this);
    QAction *uploadFolders = new QAction(upload_icon, "Upload Folders", this);
    menu->addAction(uploadFiles);
    menu->addAction(uploadFolders);
    ui->menuButton->setMenu(menu);
//    connect(uploadFiles, &QAction::triggered, this, &MainWindow::uploadFiles);
//    connect(uploadFolders, &QAction::triggered, this, &MainWindow::uploadFiles);
    connect(uploadFiles, &QAction::triggered, this, &MainWindow::addImages);
}

void MainWindow::frameStyle(){
}

void MainWindow::on_filesView_button_clicked()
{
    QIcon icon;
    if ((view % 2) == 0){
        icon.addFile(":/img/assets/list.png");
        // List View

    } else{
        icon.addFile(":/img/assets/grid.png");
        // Grid View (DEFAULT)
    }
    ui->filesView_button->setIcon(icon);
    view ++;
}

void MainWindow::on_filesSort_button_clicked()
{
    QIcon icon;
    if ((sort % 2) == 0){
        icon.addFile(":/img/assets/downArrow.png");
        // Up to Down Sort


    } else{
        icon.addFile(":/img/assets/upArrow.png");
        // Down to Up Sort (Default)

    }
    ui->filesSort_button->setIcon(icon);
    sort++;
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

void MainWindow::on_settings_button_clicked()
{
    Settings settings;
    settings.setModal(true);
    settings.exec();
}

void MainWindow::on_addMetadata_button_clicked()
{
    MetadataManager manager;
    manager.setModal(true);
    manager.setTitle(0);
    manager.exec();
}

void MainWindow::on_consultMetada_button_clicked()
{
    MetadataManager manager;
    manager.setModal(true);
    manager.setTitle(1);
    manager.exec();
}

void MainWindow::on_removeMetadata_button_clicked()
{
    MetadataManager manager;
    manager.setModal(true);
    manager.setTitle(2);
    manager.exec();
}

void MainWindow::on_modifyMetadata_button_clicked()
{
    MetadataManager manager;
    manager.setModal(true);
    manager.setTitle(3);
    manager.exec();
}

void MainWindow::on_loggerButton_clicked()
{
    QFile file(":/util/logger.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::warning(0,"Logger Information",file.errorString());
    }
}


void MainWindow::on_refreshButton_clicked()
{
    QIcon icon;
    if ((refresh % 2) == 0) icon.addFile(":/img/assets/refresh_hover.png");
    else icon.addFile(":/img/assets/refresh.png");
    ui->refreshButton->setIcon(icon);
    refresh++;
}
