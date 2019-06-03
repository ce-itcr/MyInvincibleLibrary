#ifndef METADATAMANAGER_H
#define METADATAMANAGER_H

#include <QDialog>

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
};

#endif // METADATAMANAGER_H
