package ce.itcr.invincible.data.diskManager;

public class RaidManagerAux implements InputOutput {

    private Disk[] disks;
    private int numberOfDisks;
    private int numberOfDisksForData;
    private int sizeOfDisks;

    public RaidManagerAux(int numberOfDisks, int sizeOfDisks){
        this.numberOfDisks = numberOfDisks;
        this.sizeOfDisks = sizeOfDisks;
        numberOfDisksForData = numberOfDisks -1;
        initDrives();
    }

    private void initDrives(){
        disks = new FileDisk[numberOfDisks];
        for (int i=0; i<numberOfDisks; i++){
            disks[i] = new FileDisk(sizeOfDisks);
        }
    }

    @Override
    public int write(int data, int position){
        int chosenDisk = position % numberOfDisksForData;
        int placeOnDiskForData = position / numberOfDisks;
        int placeParity = placeOnDiskForData % numberOfDisks;

        if (chosenDisk >= placeParity){
            disks[chosenDisk + 1].write(data, placeOnDiskForData);
        } else {
            disks[chosenDisk].write(data, placeOnDiskForData);
        }

        disks[placeParity].write(parityValue(position), placeOnDiskForData);
        return 0;
    }

    private int parityValue(int position){
        int placeOnDiskForData = position / numberOfDisksForData;
        int placeParity = placeOnDiskForData % numberOfDisks;
        int sum=0;
        for (int i=0; i<numberOfDisks; i++){
            if(i == placeParity){
                continue;
            }
            sum += disks[i].read(placeOnDiskForData);
        }
        return sum%2;
    }

    @Override
    public int read(int position) {
        int chosenDisk = position % numberOfDisksForData;
        int placeOnDiskForData = position / numberOfDisksForData;
        int placeParity = placeOnDiskForData % numberOfDisks;
        if(chosenDisk >= placeParity){
            return disks[chosenDisk + 1].read(placeOnDiskForData);
        } else{
            return disks[chosenDisk].read(placeOnDiskForData);
        }
    }

    public void show() {
        for (int j = 0; j < sizeOfDisks; j++) {
            for (int i = 0; i < numberOfDisks; i++) {
                System.out.print(disks[i].read(j) + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public int[][] toArray() {
        int[][] tab = new int[sizeOfDisks][numberOfDisks];
        for (int j = 0; j < sizeOfDisks; j++) {
            for (int i = 0; i < numberOfDisks; i++) {
                tab[j][i] = disks[i].read(j);
            }
        }
        return tab;
    }
}
