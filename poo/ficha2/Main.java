import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner line = new Scanner(System.in);

        int[] array1 = readInts(line);

        line.close();
    }   
    private static int[] readInts(Scanner line){
        System.out.print("Insira o tamanho do array: ");
        int size = line.nextInt();
        int[] array = new int[size];
        for(int i = 0;i < size;i++){
            System.out.print("Index: " + i + " :");
            int num = line.nextInt();
            array[i] = num;
        }
        System.out.println("Array inserido:");
        System.out.print("[ " + array[0]);
        for(int i = 1;i < size;i++){
            System.out.print(" -> " + array[i]);
        }
        System.out.print(" ]");
        return array;
    }
}