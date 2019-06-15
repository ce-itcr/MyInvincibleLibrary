#ifndef ADDIMAGES_H
#define ADDIMAGES_H

#include <QDialog>
#include <QtWidgets>

namespace Ui {
class AddImages;
}

class AddImages : public QDialog
{
    Q_OBJECT

public:
    explicit AddImages(QWidget *parent = 0);
    ~AddImages();

private:
    Ui::AddImages *ui;

    QLineEdit* txt_imgDate;
    QLineEdit* txt_imgSize;
    QLineEdit* txt_imgAuthor;
    QLineEdit* txt_imgName;
    QLineEdit* txt_imgBrief;

    void uploadImages();
    void ok_btn_sender();

public slots:
    void configureWindow();

};

#endif // ADDIMAGES_H
