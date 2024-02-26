import java.util.Scanner;
import pacote.Implementacao;   
import pacote.Datas; 
import java.time.LocalDate;

public class Main{
    public static void main(String[] args){
        Scanner line = new Scanner(System.in);
        switch(line.nextInt()){
            case 1:
                Implementacao f = new Implementacao();
                switch(line.nextInt()){
                    case 1:
                        int[] array1 = readInts(line);
                        System.out.println("O minimo do array é : " + f.findMin(array1));
                        break;
                    case 2:
                        //Definir o array
                        array1 = readInts(line);

                        // Definir os indices do array
                        int index1 = line.nextInt();
                        int index2 = line.nextInt();

                        //Chamar o método para retornar o novo array
                        int[] novo = f.window(array1,index1,index2);
                        
                        // Print do array
                        f.printArray(novo,novo.length);
                        break;
                    case 3:
                        array1 = readInts(line);
                        novo = readInts(line);
                        //int[] comuns = 
                        int[] comuns = f.common(array1,novo);
                        array1 = null;
                        novo = null;
                        f.printArray(comuns,comuns.length);
                        break;
                    default:
                        System.out.println("Não existem mais funções!");
                        break;
                }
                break;
            case 2:
                System.out.print("Insira o tamanho do array: ");
                Datas d = new Datas(line.nextInt());
                switch(line.nextInt()){
                    case 1:
                        System.out.print("Insira o ano: ");
                        int year = line.nextInt();
                        System.out.print("Insira o mes: ");
                        int month = line.nextInt();
                        System.out.print("Insira o dia: ");
                        int day = line.nextInt();
                        LocalDate data = LocalDate.of(year,day,month);
                        d.insereData(data);
                        break;
                    case 2:
                }
                break;
            default:
                System.out.println("Função não implementada!");
                break;
        }

        line.close();
    }   
    private static int[] readInts(Scanner line){
        Implementacao f = new Implementacao();
        System.out.print("Insira o tamanho do array: ");
        int size = line.nextInt();
        int[] array = new int[size];
        for(int i = 0;i < size;i++){
            System.out.print("Index: " + i + " : ");
            int num = line.nextInt();
            array[i] = num;
        }
        System.out.println("Array inserido:");
        f.printArray(array,size);
        return array;
    }
}