package ce.itcr.invincible.ws.res;

import ce.itcr.invincible.data.FolderManager;
import ce.itcr.invincible.data.Image;

import java.util.List;

class FoldersService {

    private static FoldersService instance = new FoldersService();
    private FolderManager manager = FolderManager.getInstance();

    static FoldersService getInstance() {
        return instance;
    }

    List<Image> getFolders(String folderId) {
        return manager.getImages(folderId);
    }

    boolean putFolders(String folderId, List<Image> images) {
        return manager.createImages(folderId, images);
    }

    List<Image>  postFolders(String folderId, List<Image> images) {
        return manager.modifiedImages(folderId, images);
    }

    boolean deleteFolders(String folderId) {
        return manager.deleteImages(folderId);
    }

    public long createSubFolder(String parentId) {
        return manager.createSubFolder(parentId);
    }

    public void deleteSubFolders(String folderId) {
        manager.deleteSubFolder(folderId);
    }

    public long countSubFolders(String folderId) {
        return manager.countSubFolders(folderId);
    }

    private FoldersService() {
    }
}
