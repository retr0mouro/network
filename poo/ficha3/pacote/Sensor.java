package pacote;

public class Sensor{
    private double p;


    public Sensor(){
        this.p = 0;
    }
    
    public Sensor(double d){
        if(checkP(d) == true) {
            this.p = d;
        }
        else{
            System.out.println("Valor não válido!\nVariável inicializada a 0");
            this.p = 0;
        }
    }

    private boolean checkP(double p){
        return p >= 0;
    }

    public boolean setPressao(double p) {
        if(checkP(p)){
            this.p = p;
            return true;
        } 
        return false;
    }

    public double getPressao() {
        return p;
    }

}