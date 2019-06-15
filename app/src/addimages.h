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
    void uploadImages();

public slots:
    void configureWindow();

};

#endif // ADDIMAGES_H
