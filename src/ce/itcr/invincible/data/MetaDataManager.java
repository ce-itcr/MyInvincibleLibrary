package ce.itcr.invincible.data;

import java.util.List;

public class MetaDataManager {

    private static MetaDataManager instance = new MetaDataManager();

    public static MetaDataManager getInstance() {
        return instance;
    }

    public boolean INSERT() {
        return false;
    }

    public List<String> SELECT() {
        return null;
    }

    public boolean DELETE() {
        return false;
    }

    public boolean UPDATE() {
        return false;
    }

    //(INSERT, SELECT, DELETE y UPDATE)
}
