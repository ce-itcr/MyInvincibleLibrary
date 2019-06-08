package ce.itcr.invincible.data;

import java.io.File;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class RaidManager {

    private static RaidManager instance = new RaidManager();
    private int raidSize = 4;
    private String raidName = "Raid5";

    public static RaidManager getInstance() {
        return instance;
    }

    public String read() {
        verifiedDrives();
        return "";
    }

    public boolean write(String data) {
        verifiedDrives();
        return false;
    }

    public boolean seek() {
        verifiedDrives();
        return false;
    }

    private RaidManager() {

    }

    private void initDrives() {
        System.out.print("Creating " + raidName + "...");
        try {
            new File(raidName).mkdir();
            for (int i = 0; i  < raidSize; i++) {
                String path = raidName + "/drive" + "i";
                new File(path).mkdir();
            }
            System.out.print(raidName + " created");
        }
        catch (Exception e) {
            System.out.print(e);
        }
    }

    private void verifiedDrives() {

        // Checks if RAID5 is missing
        if (Files.exists(Paths.get(raidName))) {

            // Checks if any drive is missing
            String missingDrive = "";
            int missingCount = 0;
            for (int i = 0; i < raidSize; i++) {
                String drivePath = raidName + "/drive" + i;
                Path path = Paths.get(drivePath);
                if (Files.notExists(path)) {
                    missingDrive = drivePath;
                    missingCount++;
                }
            }
            // If more that one drive is missing
            if (missingCount == 1) recoverDrive(missingDrive);
            else if (missingCount > 1) {
                System.out.print("Error : missing more than one drive");
                initDrives();
            }
        }
        else {
            System.out.print("Error : missing " + raidName);
            initDrives();
        }
    }

    private void recoverDrive(String drivePath) {

    }
}
