package ce.itcr.invincible.data.diskManager;

public class ArrayDisk extends Disk {

    private Integer[] array;

    public ArrayDisk(int size){
        array = new Integer[size];
        for(int i=0; i<size; i++){
            array[i] = 0;
        }
    }

    @Override
    public int write(int data, int position) {
        if(position >= 0 && position < array.length){
            array[position] = data;
            return 0;
        } else{
            throw new ArrayIndexOutOfBoundsException();
        }
    }

    @Override
    public int read(int position) {
        if(position >= 0 && position < array.length){
            return array[position];
        } else{
            throw new ArrayIndexOutOfBoundsException();
        }
    }
}
