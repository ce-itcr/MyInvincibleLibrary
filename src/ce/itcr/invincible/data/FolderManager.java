package ce.itcr.invincible.data;

import jdk.nashorn.api.scripting.JSObject;

import java.util.List;

public class FolderManager {

    private static FolderManager instance = new FolderManager();
    private MetaDataManager metaDataManager;
    private RaidManager raidManager;

    public static FolderManager getInstance() {
        return instance;
    }

    public String getFolders(int folderId) {
        //List<String> metaData = metaDataManager;
        //List<Image> raidManager.read();
        return "";
    }

    public boolean createFolders(int folderId, String folders) {
        return false;
    }

    public String modifiedFolders(int folderId, String folders) {
        return "";
    }

    public boolean deleteFolders(int folderId) {
        return false;
    }
}