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
        add_metadata_grid();
        break;
    case 1:
        this->setWindowTitle("Consult Metadata | MyInvincibleLibrary");
        ui->title->setStyleSheet("image: url(:/img/titles/consult_metadata_title.png);");
        consult_metadata_grid();
        break;
    case 2:
        this->setWindowTitle("Remove Metadata | MyInvincibleLibrary");
        ui->title->setStyleSheet("image: url(:/img/titles/remove_metadata_title.png);");
        remove_metadata_grid();
        break;
    case 3:
        this->setWindowTitle("Modify Metadata | MyInvincibleLibrary");
        ui->title->setStyleSheet("image: url(:/img/titles/modify_metadata_title.png);");
        modify_metadata_grid();
        break;
    default:
        this->setWindowTitle("MyInvinvibleLibrary");
        break;
    }
}

void MetadataManager::add_metadata_grid(){
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
    connect(ok_btn, &QPushButton::clicked, this, &MetadataManager::ok_btn_sender);
}

void MetadataManager::consult_metadata_grid(){
    QPixmap name_icon(":/img/assets/letter_A.png");
    QPixmap author_icon(":/img/assets/man-user.png");
    QPixmap date_icon(":/img/assets/calendar.png");

    QMenu *menu = new QMenu(this);
    QAction *searchByName = new QAction(name_icon,"Search By Name", this);
    QAction *searchByAuthor = new QAction(author_icon, "Search By Author", this);
    QAction *searchByDate = new QAction(date_icon, "Search By Date", this);
    menu->addAction(searchByName);
    menu->addAction(searchByAuthor);
    menu->addAction(searchByDate);

    QPushButton* filter_btn = new QPushButton("Filter");
    filter_btn->setMenu(menu);
    ui->gridLayout->addWidget(filter_btn,0,0,3,3);

    editableB = new QLabel("General Search");
    QLineEdit* browse = new QLineEdit;
    ui->gridLayout->addWidget(editableB,2,0);
    ui->gridLayout->addWidget(browse,2,1);

    connect(searchByName, &QAction::triggered, this,
            [=]() { editableB->setText("Search By Name"); });
    connect(searchByAuthor, &QAction::triggered, this,
            [=]() { editableB->setText("Search By Author"); });
    connect(searchByDate, &QAction::triggered, this,
            [=]() { editableB->setText("Search By Date"); });

    QPushButton* ok_btn = new QPushButton("OK");
    ui->gridLayout->addWidget(ok_btn,2,2);

    QTableWidget* tableWidget = new QTableWidget(30,5, this);
    ui->gridLayout->addWidget(tableWidget,3,0,3,3);


}

void MetadataManager::remove_metadata_grid(){
    QPixmap name_icon(":/img/assets/letter_A.png");
    QPixmap author_icon(":/img/assets/man-user.png");
    QPixmap date_icon(":/img/assets/calendar.png");

    QMenu *menu = new QMenu(this);
    QAction *searchByName = new QAction(name_icon,"Search By Name", this);
    QAction *searchByAuthor = new QAction(author_icon, "Search By Author", this);
    QAction *searchByDate = new QAction(date_icon, "Search By Date", this);
    menu->addAction(searchByName);
    menu->addAction(searchByAuthor);
    menu->addAction(searchByDate);

    QPushButton* filter_btn = new QPushButton("Filter");
    filter_btn->setMenu(menu);
    ui->gridLayout->addWidget(filter_btn,0,0,3,3);

    editableB = new QLabel("General Search");
    QLineEdit* browse = new QLineEdit;
    ui->gridLayout->addWidget(editableB,2,0);
    ui->gridLayout->addWidget(browse,2,1);

    connect(searchByName, &QAction::triggered, this,
            [=]() { editableB->setText("Search By Name"); });
    connect(searchByAuthor, &QAction::triggered, this,
            [=]() { editableB->setText("Search By Author"); });
    connect(searchByDate, &QAction::triggered, this,
            [=]() { editableB->setText("Search By Date"); });

    QPushButton* ok_btn = new QPushButton("OK");
    ui->gridLayout->addWidget(ok_btn,2,2);

    QTableWidget* tableWidget = new QTableWidget(30,6, this);
    ui->gridLayout->addWidget(tableWidget,4,0,2,3);

    QPushButton* deleteMetadata = new QPushButton("Delete");
    ui->gridLayout->addWidget(deleteMetadata,5,0,1,3);
}

void MetadataManager::modify_metadata_grid(){
    QPixmap name_icon(":/img/assets/letter_A.png");
    QPixmap author_icon(":/img/assets/man-user.png");
    QPixmap date_icon(":/img/assets/calendar.png");

    QMenu *menu = new QMenu(this);
    QAction *searchByName = new QAction(name_icon,"Search By Name", this);
    QAction *searchByAuthor = new QAction(author_icon, "Search By Author", this);
    QAction *searchByDate = new QAction(date_icon, "Search By Date", this);
    menu->addAction(searchByName);
    menu->addAction(searchByAuthor);
    menu->addAction(searchByDate);

    QPushButton* filter_btn = new QPushButton("Filter");
    filter_btn->setMenu(menu);
    ui->gridLayout->addWidget(filter_btn,0,0,3,3);

    editableB = new QLabel("General Search");
    QLineEdit* browse = new QLineEdit;
    ui->gridLayout->addWidget(editableB,2,0);
    ui->gridLayout->addWidget(browse,2,1);

    connect(searchByName, &QAction::triggered, this,
            [=]() { editableB->setText("Search By Name"); });
    connect(searchByAuthor, &QAction::triggered, this,
            [=]() { editableB->setText("Search By Author"); });
    connect(searchByDate, &QAction::triggered, this,
            [=]() { editableB->setText("Search By Date"); });

    QPushButton* ok_btn = new QPushButton("OK");
    ui->gridLayout->addWidget(ok_btn,2,2);

    QTableWidget* tableWidget = new QTableWidget(30,6, this);
    ui->gridLayout->addWidget(tableWidget,3,0,3,3);

    QPushButton* modify_btn = new QPushButton("OK");
    ui->gridLayout->addWidget(modify_btn,5,0,1,3);
}


void MetadataManager::ok_btn_sender(){
    if(txt_imgName->cursorPosition() > 0 && txt_imgAuthor->cursorPosition() > 0 && txt_imgDate->cursorPosition() > 0 &&
            txt_imgSize->cursorPosition() > 0 && txt_imgBrief->cursorPosition() > 0){
        qDebug() << "Enviar información al Server";
    } else{
        QMessageBox::warning(this, "Warning", "You must fill all the spaces.");
    }
}
