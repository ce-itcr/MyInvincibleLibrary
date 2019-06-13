package ce.itcr.invincible.data.diskManager;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;

public class FileDisk  extends Disk{

    static private int num = 0;
    private File file;

    public FileDisk(int size){
        this.file = new File(num++ + ".txt");
        createFileIfNoExist();
    }

    private void createFileIfNoExist(){
        try{
            file.createNewFile();
        } catch (IOException e){
            e.printStackTrace();
        }
    }

    @Override
    public int write(int data, int position) {
        String in = String.valueOf(data);
        try(RandomAccessFile raf = new RandomAccessFile(file, "rw")){
            raf.seek(position);
            raf.write(in.getBytes());
            return 0;
        } catch (IOException e){
            throw new RuntimeException();
        }
    }

    @Override
    public int read(int position) {
        byte buffer[] = new byte[1];
        try(RandomAccessFile raf = new RandomAccessFile(file, "r")){
            raf.seek(position);
            raf.read(buffer);
            return (char) buffer[0] - 48;
        } catch(IOException e){
            throw new RuntimeException();
        }
    }
}
