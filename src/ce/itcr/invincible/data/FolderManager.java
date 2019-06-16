package ce.itcr.invincible.data;

import java.util.List;

public class FolderManager {

    private static FolderManager instance = new FolderManager();
    private MetaDataManager metaDataManager = MetaDataManager.getInstance();
    private RaidManager raidManager = RaidManager.getInstance();

    public static FolderManager getInstance() {
        return instance;
    }

    public List<Image> getFolders(String folderId) {
        List<Image> images;
        List<Image> imagesMD;
        List<Image> imagesR5;

        images = metaDataManager.SELECT(folderId);
        //raidManager.seek(folderId);
        //raidManager.read();

        return images;
    }

    public boolean createFolders(String folderId, List<Image> images) {
        return metaDataManager.INSERT(folderId, images);
    }

    public List<Image>  modifiedFolders(String folderId, List<Image> images) {
        return metaDataManager.UPDATE(folderId, images);
    }

    public boolean deleteFolders(String folderId) {
        return metaDataManager.DELETE(folderId);
    }
}
