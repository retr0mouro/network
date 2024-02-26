import java.util.Scanner;
import pacote.Implementacao;    

public class Main{
    public static void main(String[] args){
        Scanner line = new Scanner(System.in);
        Implementacao f = new Implementacao();
        switch(line.nextInt()){
            case 1:
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
                        f.printArray(comuns,comuns.length);
                    default:
                        System.out.println("Não existem mais funções!");
                        break;
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