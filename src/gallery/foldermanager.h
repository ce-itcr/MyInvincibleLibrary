#ifndef FOLDERMANAGER_H
#define FOLDERMANAGER_H

#include "folder.h"


class FolderManager
{
public:
    static FolderManager *getInstance();

    Folder getRoot() const;
    void setRoot(const Folder &value);

private:
    static FolderManager *instance;
    Folder root;

    FolderManager();
};

#endif // FOLDERMANAGER_H
