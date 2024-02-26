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
        if(index >= this.datas.length){
            this.datas[index] = LocalDate.from(data);
            index++;
            return;
        }
        System.out.println("The array is full! Do not insert anymore.");
    }
    public LocalDate dataMaisProxima(LocalDate data){
        int maxDiff = 0;
        int index = 0;
        for(int i = 0;i < this.datas.length;i++){
            int yearDiff = absolute(datas[i].getYear(),data.getYear());
            int daysDiff = absolute(datas[i].getDayOfYear(),data.getDayOfYear());
            if(yearDiff > 1){
                daysDiff += 365 * yearDiff;
            }else{
                
            }
        }
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