package ce.itcr.invincible.data;

import java.util.List;

public class MetaDataManager {

    private static MetaDataManager instance = new MetaDataManager();

    public static MetaDataManager getInstance() {
        return instance;
    }

    public boolean INSERT(List<Image> images) {
        return false;
    }

    public List<Image> SELECT(List<String> imagesId) {
        return null;
    }

    public boolean DELETE(List<String> imagesId) {
        return false;
    }

    public boolean UPDATE(List<Image> images) {
        return false;
    }

    //(INSERT, SELECT, DELETE y UPDATE)
}
