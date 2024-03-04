package pacote;
import java.lang.Math;


import org.junit.jupiter.api.Test;



public class Circulo{
    private double x;
    private double y;
    private double raio;


    public Circulo(){
        this.x = 0;
        this.y = 0;
        this.raio = 0;
    }

    public Circulo(double x,double y){
        this.x = x;
        this.y = y;
        this.raio = 0;
    }

    public Circulo(double raio){
        this.x = 0;
        this.y = 0;
        this.raio = raio;
    }

    public Circulo(double x, double y, double raio){
        this.x = x;
        this.y = y;
        this.raio = raio;
    }


    public double getX(){
        return this.x;
    }
    public void setX(double x){
        this.x = x;
    }


    public double getY(){
        return this.y;
    }
    public void setY(double y){
        this.y = y;
    }


    public double getRaio(){
        return this.raio;
    }
    public void setRaio(double r){
        this.raio = r;
    }




    public void alteraCentro(double x,double y){
        this.x = x;
        this.y = y;
    }


    public double calculaArea(){
        return Math.PI * (raio * raio);
    }

    public double calculaPerimetro(){
        return Math.PI * raio * 2;
    }

    public boolean equals(Circulo o){
        return 
            this.x == o.getX() &&
            this.y == o.getY() && 
            this.raio == o.getRaio();
    }
    
    public String toString(){
        return "(" + this.x + "," + this.y + "," + this.raio + ")";
    }

    public Circulo clone(){
        return new Circulo(this.x, this.y,this.raio);
    }

}