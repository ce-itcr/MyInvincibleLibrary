#ifndef EXPLORER_H
#define EXPLORER_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>

namespace Ui {
class Explorer;
}

class Explorer : public QDialog
{
    Q_OBJECT

public:
    explicit Explorer(QWidget *parent = 0);
    ~Explorer();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::Explorer *ui;
    QFileSystemModel *directory;
    QFileSystemModel *archive;

};

#endif // EXPLORER_H
