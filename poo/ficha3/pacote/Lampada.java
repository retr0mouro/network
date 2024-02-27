package pacote;

public class Lampada{
    private int mode;
    private int comsuption;
    private int duration;
    private int creation;


    public Lampada(int mode, int comsuption) {
        this.mode = mode;
        this.comsuption = comsuption;
    }

    public Lampada(){
        this.mode = 0;
        this.comsuption = 0;
    }
    
    
    public int getMode() {
        return mode;
    }


    public int getComsuption() {
        return comsuption;
    }
    public void setComsuption(int comsuption) {
        this.comsuption = comsuption;
    }
    
    
    @Override
    public String toString() {
        return "Lampada [mode=" + mode + ", comsuption=" + comsuption + "]";
    }

    
    public void lampOn(){
        this.mode = 1;
    }

    public void lampOff(){
        this.mode = 0;
    }  

    public void lampEco(){
        this.mode = 2;
    }

    public double totalConsumo(int now){
        double total = this.comsuption * (now - this.creation);
        return total;
    }

    public double periodoConsumo(){
        double total = this.comsuption * this.duration;
        return total;
    }
}