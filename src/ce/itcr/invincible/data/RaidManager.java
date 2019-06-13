package ce.itcr.invincible.data;

import ce.itcr.invincible.data.diskManager.RaidManagerAux;

public class RaidManager {

    private static RaidManager instance = new RaidManager();

    public static RaidManager getInstance(){
        return instance;
    }

    public static void runRaid(){
        RaidManagerAux tmpRaid = new RaidManagerAux(4, 4);
        tmpRaid.write(0,5);
        tmpRaid.write(1,5);
        tmpRaid.show();
    }
}



