package ce.itcr.invincible.data.raid;

import com.sun.org.apache.xerces.internal.impl.dv.util.Base64;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

public class Raid5 {
    private int turn=0;
    private String disksPath = "/src/ce/itcr/invincible";
    private Path currentRelativePath = Paths.get("");
    private String s = currentRelativePath.toAbsolutePath().toString();

    public File Disk1 = new File(s+disksPath+"/Disk1");
    public File Disk2 = new File(s+disksPath+"/Disk2");
    public File Disk3 = new File(s+disksPath+"/Disk3");
    public File Disk4 = new File(s+disksPath+"/Disk4");
    private File[] disks = {Disk1,Disk2,Disk3,Disk4};

    public void createFile(String path,String infoToPut,String name) throws IOException {
        FileOutputStream out = new FileOutputStream(path+"/"+name+".txt");
        out.write(infoToPut.getBytes());
        out.close();
    }

    public boolean search(String id){
        for (int i=0; i<disks.length; i++) {
            File[] contents = this.disks[i].listFiles();
            for (int j = 0; j < contents.length ; j++) {
                String file=contents[j].toString();
                System.out.println(file.toString());
                boolean isFound = file.contains(id) ? true: false;
                if(isFound){
                    return true;
                }
            }
        }
        return false;
    }

    public byte[][] getDisponibleInfo(String id) throws IOException {
        byte[][] disponibleInfo = new byte[3][];
        int counter = 0;
        for(int i=0; i<disks.length; i++){
            File[] contents = this.disks[i].listFiles();
            for(int j=0; j<contents.length; j++){
                String file = contents[j].toString();
                boolean isFound = file.indexOf(id) != -1 ? true : false;
                boolean part1 = file.indexOf(id + "-1") != -1 ? true : false;
                boolean part2 = file.indexOf(id + "-2") != -1 ? true : false;
                boolean part3 = file.indexOf(id + "-3") != -1 ? true : false;
                boolean partP = file.indexOf(id + "-P") != -1 ? true : false;
                if(part1){
                    File fileAux = new File(file);
                    String path = file.toString();
                    BufferedImage data = ImageIO.read(fileAux);
                    ByteArrayOutputStream container = new ByteArrayOutputStream();
                    ImageIO.write(data, "png", container);
                    disponibleInfo[counter] = container.toByteArray();
                    counter++;
                }
                if(part2){
                    File fileAux = new File(file);
                    String path = file.toString();
                    BufferedImage data = ImageIO.read(fileAux);
                    ByteArrayOutputStream container = new ByteArrayOutputStream();
                    ImageIO.write(data, "png", container);
                    disponibleInfo[counter] = container.toByteArray();
                    counter++;
                }
                if(part3){
                    File fileAux = new File(file);
                    String path = file.toString();
                    BufferedImage data = ImageIO.read(fileAux);
                    ByteArrayOutputStream container = new ByteArrayOutputStream();
                    ImageIO.write(data, "png", container);
                    disponibleInfo[counter] = container.toByteArray();
                    counter++;
                }
                if(partP){
                    File fileAux = new File(file);
                    String path = file.toString();
                    String data = new String(Files.readAllBytes(Paths.get(path)), StandardCharsets.UTF_8);
                    disponibleInfo[counter] = Base64.decode(data);
                    counter++;
                }
            }
        }
        return disponibleInfo;
    }

    public int getArraySize(String id, int number1, int number2, int number3) throws IOException, ClassNotFoundException {
        FileInputStream fin = new FileInputStream(getFileDirection(id+"-INFO.txt"));
        ObjectInputStream ois = new ObjectInputStream(fin);
        ArrayList<Integer> sizes = (ArrayList<Integer>)ois.readObject();
        ArrayList<Integer> addedValues = new ArrayList<Integer>();
        addedValues.add(number1);
        addedValues.add(number2);
        addedValues.add(number3);
        int returnValue=0;
        for (int i = 0; i <3 ; i++) {
            if(addedValues.contains(sizes.get(i))){
            } else{
                return sizes.get(i);
            }
        }
        if(returnValue==0){
            returnValue=this.largerNumber(number1,number2,number3);
        }
        return returnValue;
    }

    public  String getFileDirection(String id){
        for (int i=0; i<disks.length ; i++) {
            File[] contents = this.disks[i].listFiles();
            for (int j=0; j<contents.length ; j++) {
                String fileAux = contents[j].toString();
                boolean isFound = fileAux.contains(id) ? true: false;
                if(isFound){
                    return fileAux;
                }
            }
        }
        return "";
    }

    public int largerNumber(int size1,int size2, int size3){
        if(size1>size2&&size1>size3){
            return size1;
        } else if(size2>size1&&size2>size3){
            return size2;
        } else{
            return size3;
        }
    }

    public ArrayList<String> getIdsToRecovery(){
        ArrayList<String> idsToRecovery = new ArrayList<String>();

        return idsToRecovery;
    }





}
