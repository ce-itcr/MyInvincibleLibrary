package ce.itcr.invincible.data;

public class RaidManager {

    private static RaidManager instance = new RaidManager();

    public static RaidManager getInstance() {
        return instance;
    }

    public String read() {
        return "";
    }

    public boolean write() {
        return false;
    }

    public boolean seek() {
        return false;
    }
}
