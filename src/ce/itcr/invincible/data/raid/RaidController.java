package ce.itcr.invincible.data.raid;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class RaidController {
    private List<String> idList = new ArrayList<String>();
    private  List<String> imageList = new ArrayList<String>();
    public Raid5 raid5 = new Raid5();

    public void recovery(String id) throws IOException {
        String Image1 = id + "-1.png";
        String Image2 = id + "-2.png";
        String Image3 = id + "-3.png";
        if(!raid5.search(Image1)){

        }
        if(!raid5.search(Image2)){

        }
        if(!raid5.search(Image3)){

        }
        else{

        }
    }

    public void totalRecovery() throws IOException {
        ArrayList<String> arrayToRecover = this.raid5.getIdsToRecovery();
        for (int i = 0; i <arrayToRecover.size() ; i++) {
            String id = arrayToRecover.get(i);
            recovery(id);
        }
    }

}
