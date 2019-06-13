package ce.itcr.invincible.data.diskManager;

public interface InputOutput {

    int write(int data, int position);
    int read(int position);

}
