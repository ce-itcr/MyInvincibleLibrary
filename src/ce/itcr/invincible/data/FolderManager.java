package ce.itcr.invincible.data;

public class FolderManager {

    private static FolderManager instance = new FolderManager();
    private MetaDataManager metaDataManager = MetaDataManager.getInstance();
    private RaidManager raidManager = RaidManager.getInstance();

    public static FolderManager getInstance() {
        return instance;
    }

    public String getFolders(String folderId) {

        /// ****Cambiar a parseo**** ///
        //metaDataManager.SELECT();

        raidManager.seek(folderId);
        raidManager.read();
        return "";
    }

    public boolean createFolders(int folderId, String folders) {
        return false;
    }

    public String modifiedFolders(String folderId, String folders) {
        return "";
    }

    public boolean deleteFolders(String folderId) {
        return false;
    }
}
