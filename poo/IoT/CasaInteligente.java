package IoT;

import java.util.Comparator;
import java.util.HashMap;
import java.util.Set;

public class CasaInteligente {
    private String id;
    private HashMap<Integer,Lampada> lampadas;

    public HashMap<Integer, Lampada> getLampadas() {
        return lampadas;
    }

    

    public void setLampadas(HashMap<Integer, Lampada> lampadas) {
        this.lampadas = lampadas;
    }

    public CasaInteligente(String nome, HashMap<Integer, Lampada> lampadas) {
        this.id = nome;
        this.lampadas = lampadas;
    }    
    
    public CasaInteligente() {
        this.id = "";
        this.lampadas = new HashMap<Integer,Lampada>();
    }

    @Override
    public String toString() {
        return "CasaInteligente [lampadas=" + lampadas.toString() + "]";
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((lampadas == null) ? 0 : lampadas.hashCode());
        return result;
    }

    public boolean equals(CasaInteligente n){
        return this.id == n.id;
    }

    public String getId() {
        return id;
    }



    public void setId(String id) {
        this.id = id;
    }   

    
    public void addLampada(Lampada l){
        this.lampadas.put(l.hashCode(), l);
    }

    public void ligaLampadaNormal(int index){
        Lampada n = this.lampadas.get(index);
        n.lampOn();
    }

    public void ligaLampadaEco(int index){
        Lampada n = this.lampadas.get(index);
        n.lampEco();
    }
    
    public int qtEmEco(){
        int quantos = 0;
        /*for(Map.Entry<Integer,Lampada> entry : this.lampadas.entrySet()){
            Lampada value = entry.getValue();
            if(value.getMode() == Lampada.ON){
                quantos++;
            }
        }*/
        quantos = this.lampadas.
                    values().
                    stream().
                    filter(a->a.getMode() == Lampada.ECO).
                    mapToInt(a-> 1).
                    sum();
        return quantos;
    }
    public void removeLampada(int index){
        this.lampadas.remove(index);
    }
    public void ligaTodasEco(){
        this.lampadas.forEach((key,value) -> value.lampEco());
    } 
    public void ligaTodasMax(){
        this.lampadas.forEach((key,value) -> value.lampOn());
    } 

    public double consumoTotal(){
        return  this.lampadas.
                values().
                stream().
                mapToDouble(a->a.getComsuption()).
                sum();
    }           

    public Lampada maisGastadora(){
        return this.lampadas.
                values().
                stream().
                max(Comparator.comparingDouble(Lampada::getComsuption)).
                get();
    }

    public Set<Lampada> lampadasEmModoEco(){
        return this.lampadas.values().stream().filter((key,value) -> value.getComsuption() == Lampada.ECO).;
    }

}