#ifndef METADATAMANAGER_H
#define METADATAMANAGER_H

#include <QDialog>
#include <QtWidgets>

namespace Ui {
class MetadataManager;
}

class MetadataManager : public QDialog
{
    Q_OBJECT

public:
    explicit MetadataManager(QWidget *parent = 0);
    ~MetadataManager();
    void setTitle(int action);

private:
    Ui::MetadataManager *ui;

    QLabel* editableB;

    void add_metadata_grid();
    void consult_metadata_grid();
    void remove_metadata_grid();
    void modify_metadata_grid();
};

#endif // METADATAMANAGER_H
