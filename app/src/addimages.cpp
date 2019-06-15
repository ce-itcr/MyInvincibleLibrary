#include "addimages.h"
#include "ui_addimages.h"

AddImages::AddImages(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddImages)
{
    ui->setupUi(this);
    configureWindow();
}

AddImages::~AddImages()
{
    delete ui;
}

void AddImages::configureWindow(){

    QPushButton *uploadImage = new QPushButton("UPLOAD IMAGE");
    ui->gridLayout_2->addWidget(uploadImage,0,0,1,3);
    connect(uploadImage, &QPushButton::clicked, this, &AddImages::uploadImages);

    QLabel *imgPath = new QLabel("Image Path: ");
    ui->gridLayout_2->addWidget(imgPath,1,0);

    QPushButton *compressImage = new QPushButton("Compress Image");
    ui->gridLayout_2->addWidget(compressImage,1,2);

    QLabel *imgName = new QLabel("Name:");
    QLineEdit *txt_imgName = new QLineEdit;
    ui->gridLayout->addWidget(imgName,0,0);
    ui->gridLayout->addWidget(txt_imgName,0,1);

    QLabel* imgAuthor = new QLabel("Author:");
    QLineEdit* txt_imgAuthor = new QLineEdit;
    ui->gridLayout->addWidget(imgAuthor,1,0);
    ui->gridLayout->addWidget(txt_imgAuthor,1,1);

    QLabel* imgDate = new QLabel("Date:");
    QLineEdit* txt_imgDate = new QLineEdit;
    ui->gridLayout->addWidget(imgDate,2,0);
    ui->gridLayout->addWidget(txt_imgDate,2,1);

    QLabel* imgSize = new QLabel("Size:");
    QLineEdit* txt_imgSize = new QLineEdit;
    ui->gridLayout->addWidget(imgSize,3,0);
    ui->gridLayout->addWidget(txt_imgSize,3,1);

    QLabel* imgBrief = new QLabel("Description:");
    QLineEdit* txt_imgBrief = new QLineEdit;
    ui->gridLayout->addWidget(imgBrief,4,0);
    ui->gridLayout->addWidget(txt_imgBrief,4,1);

    QPushButton* ok_btn = new QPushButton("OK");
    ui->gridLayout->addWidget(ok_btn, 5, 0, 1, 2);
}

void AddImages::uploadImages(){
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Images"), "/home/rpi/Desktop/Picture/Sample Pictures", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!fileName.isEmpty()){
        QImage image(fileName);
        ui->img_preview->setPixmap(QPixmap::fromImage(image));
        QLabel *path = new QLabel(fileName);
        ui->gridLayout_2->addWidget(path,1,1);

    }
}
