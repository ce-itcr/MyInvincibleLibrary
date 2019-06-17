#ifndef ADDIMAGES_H
#define ADDIMAGES_H

#include <QDialog>
#include <QtWidgets>

#include "Huffman/huffmancompression.h"
#include "Huffman/binarytree.h"
#include "Huffman/list.h"
#include "gallery/image.h"

namespace Ui {
class AddImages;
}

class AddImages : public QDialog
{
    Q_OBJECT

public:
    explicit AddImages(QWidget *parent = 0);
    ~AddImages();
    Image *imageManager;

private:
    Ui::AddImages *ui;

    QString fileName;
    QString tmpList;
    List tmpQList;

    QLineEdit* txt_imgDate;
    QLineEdit* txt_imgSize;
    QLineEdit* txt_imgAuthor;
    QLineEdit* txt_imgName;
    QLineEdit* txt_imgBrief;

    QLabel *path;

    void uploadImages();
    void ok_btn_sender();
    void compress();
    void setImageData();

public slots:
    void configureWindow();

};

#endif // ADDIMAGES_H
