#include "addimages.h"
#include "ui_addimages.h"

AddImages::AddImages(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddImages)
{
    ui->setupUi(this);
    configureWindow();
    imageManager = new Image();
}

AddImages::~AddImages()
{
    delete ui;
}

void AddImages::configureWindow(){

    QPushButton *uploadImage = new QPushButton("UPLOAD IMAGE");
    ui->gridLayout_2->addWidget(uploadImage,0,0,1,4);
    connect(uploadImage, &QPushButton::clicked, this, &AddImages::uploadImages);

    QLabel *imgPath = new QLabel("Image Path: ");
    ui->gridLayout_2->addWidget(imgPath,1,0);

    QLabel *imgName = new QLabel("Name:");
    txt_imgName = new QLineEdit;
    ui->gridLayout->addWidget(imgName,0,0);
    ui->gridLayout->addWidget(txt_imgName,0,1);

    QLabel* imgAuthor = new QLabel("Author:");
    txt_imgAuthor = new QLineEdit;
    ui->gridLayout->addWidget(imgAuthor,1,0);
    ui->gridLayout->addWidget(txt_imgAuthor,1,1);

    QLabel* imgDate = new QLabel("Date:");
    txt_imgDate = new QLineEdit;
    ui->gridLayout->addWidget(imgDate,2,0);
    ui->gridLayout->addWidget(txt_imgDate,2,1);

    QLabel* imgSize = new QLabel("Size:");
    txt_imgSize = new QLineEdit;
    ui->gridLayout->addWidget(imgSize,3,0);
    ui->gridLayout->addWidget(txt_imgSize,3,1);

    QLabel* imgBrief = new QLabel("Description:");
    txt_imgBrief = new QLineEdit;
    ui->gridLayout->addWidget(imgBrief,4,0);
    ui->gridLayout->addWidget(txt_imgBrief,4,1);

    QPushButton* ok_btn = new QPushButton("OK");
    ui->gridLayout->addWidget(ok_btn, 5, 0, 1, 2);
    connect(ok_btn, &QPushButton::clicked, this, &AddImages::ok_btn_sender);
}

void AddImages::uploadImages(){
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    fileName = QFileDialog::getOpenFileName(this, tr("Open Images"), "/home/rpi/Desktop/Picture/Sample Pictures", tr("Image Files (*.png *.jpg *.bmp)"));
    int size = 0;
    QFileInfo imgFile(fileName);
    if (!fileName.isEmpty()){
        QImage image(fileName);
        ui->img_preview->setPixmap(QPixmap::fromImage(image));

        txt_imgName->setText(imgFile.fileName());
        txt_imgAuthor->setText(imgFile.owner());

        path = new QLabel(fileName);
        ui->gridLayout_2->addWidget(path,1,1);

        QDateTime dateTime = QDateTime::currentDateTime();
        QString dateTimeText = dateTime.toString();
        txt_imgDate->setText(dateTimeText);
        ui->gridLayout->addWidget(txt_imgDate,2,1);

        size = imgFile.size();
        txt_imgSize->setText(QString::number(size) + " bytes");

        txt_imgBrief->setText(imgFile.absoluteFilePath());

    }
}

void AddImages::ok_btn_sender(){
    if(txt_imgName->cursorPosition() > 0 && txt_imgAuthor->cursorPosition() > 0 && txt_imgDate->cursorPosition() > 0 &&
            txt_imgSize->cursorPosition() > 0 && txt_imgBrief->cursorPosition() > 0){

        tmpList.append(txt_imgName->text() + ";");
        tmpList.append(txt_imgAuthor->text() + ";");
        tmpList.append(txt_imgDate->text() + ";");
        tmpList.append(txt_imgSize->text() + ";");
        tmpList.append(txt_imgBrief->text());
        path->clear();

        setImageData();

        QImage initial_image(fileName);
        QByteArray ba;
        QBuffer buffer(&ba);
        buffer.open(QIODevice::WriteOnly);
        initial_image.save(&buffer, "PNG");

        ba = ba.toBase64();

        QByteArray by = QByteArray::fromBase64(ba);
        QImage final_image = QImage::fromData(by, "");

        imageManager->setData(ba);

        compress();


        tmpList.clear();

    } else{
        QMessageBox::warning(this, "Warning", "You must fill all the spaces.");
    }
}

void AddImages::compress(){

    HuffmanCompression *hc = new HuffmanCompression();
    List *list = hc->compress(tmpList.toUtf8().toStdString());
    list->sort();
    list->print();
    BinaryTree* bt = hc->order(list);
    QJsonDocument doc(JsonSerializer::serialize(*bt));
    QString data = doc.toJson(QJsonDocument::Compact);
    imageManager->setMetadata(data);

//    imageManager->setMetadata(JsonSerializer::serialize(*bt));
//    qDebug() << QString::fromStdString(hc->decompress(bt,hc->compressedWord));
}

void AddImages::setImageData(){
    imageManager->setName(txt_imgName->text());
    imageManager->setAuthor(txt_imgAuthor->text());
    imageManager->setDate(txt_imgDate->text());
    imageManager->setSize(txt_imgSize->text());
    imageManager->setDescription(txt_imgBrief->text());
}
