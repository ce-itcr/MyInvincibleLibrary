#include "foldermanager.h"

FolderManager *FolderManager::instance = new FolderManager();

FolderManager *FolderManager::getInstance()
{
    return instance;
}

Folder FolderManager::getRoot() const
{
    return root;
}

void FolderManager::setRoot(const Folder &value)
{
    root = value;
}

FolderManager::FolderManager()
{

}
