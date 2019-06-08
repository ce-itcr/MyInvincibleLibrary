package ce.itcr.invincible.ws.res;

import ce.itcr.invincible.data.FolderManager;

class FoldersService {

    private static FoldersService instance = new FoldersService();
    private FolderManager manager = FolderManager.getInstance();

    static FoldersService getInstance() {
        return instance;
    }

    String getFolders(int folderId) {
        return manager.getFolders(folderId);
    }

    boolean putFolders(int folderId, String folders) {
        return manager.createFolders(folderId, folders);
    }

    String postFolders(int folderId, String folders) {
        return manager.modifiedFolders(folderId, folders);
    }

    boolean deleteFolders(int folderId) {
        return manager.deleteFolders(folderId);
    }

    private FoldersService() {
    }
}
