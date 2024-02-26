package pacote;
import java.time.LocalDate;

public class Datas{
    private LocalDate[] datas;
    private int index;
    public Datas(int size){
        this.datas = new LocalDate[size];
        this.index = 0;
    }
    public Datas(){
        this.datas = new LocalDate[25];
        this.index = 0;
    }
    public void insereData(LocalDate data){
        System.out.println("Index anterior: " + this.index);
        if(index >= this.datas.length){
            this.datas[index] = LocalDate.from(data);
            index++;
            System.out.println("Data inserida com sucesso!\nIndex atual: " + this.index);
            return;
        }
        System.out.println("The array is full! Do not insert anymore.");
    }
    public LocalDate dataMaisProxima(LocalDate data){
        int minDiff = 0;
        int index = 0;
        for(int i = 0;i < this.datas.length;i++){

            // Anos de diferença
            int yearDiff = absolute(datas[i].getYear(),data.getYear());

            // Dias de diferença dentro do ano
            int daysDiff = absolute(datas[i].getDayOfYear(),data.getDayOfYear());


            // Casos em que a diferença causada pelo ano é superior a 365 dias
            if(yearDiff > 1){

                daysDiff += 365 * yearDiff;

            }

            // Somar o resto dos dias do ano ao ano em que se está
            if(datas[i].getDayOfYear() > data.getDayOfYear()){
                daysDiff += (365 - datas[i].getDayOfYear()) + data.getDayOfYear();

            }else{

                daysDiff += (365 - data.getDayOfYear()) + datas[i].getDayOfYear();
            }
            
            if(daysDiff <= minDiff){
                index = i;
            }
        }
        return datas[index];
    }
    public String toString(LocalDate data){
        return data.getYear()+"/"+data.getMonthValue()+"/"+data.getDayOfMonth();
    }
    public int absolute(int a,int b){
        int diff = a - b;
        if(diff < 0){
            return -diff;
        }else{
            return diff;
        }
    }
}