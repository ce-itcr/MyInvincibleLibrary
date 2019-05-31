package ce.itcr.invincible.ws.res;

class FoldersService {

    private static FoldersService instance = new FoldersService();

    static FoldersService getInstance() {
        return instance;
    }

    String getFolders(int folderId) {
        return "";
    }

    boolean putFolders(int folderId, String folders) {
        return false;
    }

    String postFolders(int folderId, String folders) {
        return "";
    }

    boolean deleteFolders(int folderId) {
        return false;
    }

    private FoldersService() {
    }
}
