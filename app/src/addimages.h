#ifndef ADDIMAGES_H
#define ADDIMAGES_H

#include <QDialog>
#include <QtWidgets>

#include "Huffman/HuffmanCompression.h"
#include "Huffman/BinaryTree.h"
#include "Huffman/ListBT.h"

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

    QString fileName;
    QString tmpList;

    QLineEdit* txt_imgDate;
    QLineEdit* txt_imgSize;
    QLineEdit* txt_imgAuthor;
    QLineEdit* txt_imgName;
    QLineEdit* txt_imgBrief;

    void uploadImages();
    void ok_btn_sender();
    void compress();

public slots:
    void configureWindow();

};

#endif // ADDIMAGES_H
