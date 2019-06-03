#include "metadatamanager.h"
#include "ui_metadatamanager.h"

MetadataManager::MetadataManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MetadataManager)
{
    ui->setupUi(this);
}

MetadataManager::~MetadataManager()
{
    delete ui;
}

void MetadataManager::setTitle(int action){
    // 0, Add Metadata
    // 1, Consult Metadata
    // 2, Remove Metadata
    // 3, Modify Metadata

    switch (action) {
    case 0:
        this->setWindowTitle("Add Metadata | MyInvincibleLibrary");
        ui->title->setStyleSheet("image: url(:/img/titles/add_metadata_title.png);");
        break;
    case 1:
        this->setWindowTitle("Consult Metadata | MyInvincibleLibrary");
        ui->title->setStyleSheet("image: url(:/img/titles/consult_metadata_title.png);");
        break;
    case 2:
        this->setWindowTitle("Remove Metadata | MyInvincibleLibrary");
        ui->title->setStyleSheet("image: url(:/img/titles/remove_metadata_title.png);");
        break;
    case 3:
        this->setWindowTitle("Modify Metadata | MyInvincibleLibrary");
        ui->title->setStyleSheet("image: url(:/img/titles/modify_metadata_title.png);");
        break;
    default:
        this->setWindowTitle("MyInvinvibleLibrary");
        break;
    }


}
