#include "explorer.h"
#include "ui_explorer.h"

Explorer::Explorer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Explorer)
{
    ui->setupUi(this);

    QString dir = "/";
    directory = new QFileSystemModel(this);
    directory->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    directory->setRootPath(dir);
    ui->treeView->setModel(directory);

    archive = new QFileSystemModel(this);
    archive->setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    archive->setRootPath(dir);
    ui->listView->setModel(archive);
}

Explorer::~Explorer()
{
    delete ui;
}

void Explorer::on_treeView_clicked(const QModelIndex &index)
{
    QString dir = directory->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(archive->setRootPath(dir));

}
