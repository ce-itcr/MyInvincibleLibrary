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
        return manager.getFolders(folderId);
    }

    boolean putFolders(int folderId, List<Image> images) {
        return manager.createFolders(folderId, images);
    }

    List<Image>  postFolders(String folderId, List<Image> images) {
        return manager.modifiedFolders(folderId, images);
    }

    boolean deleteFolders(String folderId) {
        return manager.deleteFolders(folderId);
    }

    private FoldersService() {
    }
}
