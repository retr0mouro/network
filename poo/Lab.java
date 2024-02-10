import java.util.Scanner;

public class Lab {
    public static void main(String[] args){
        Scanne line = new Scanner(System.in);
        String string = line.nextString();
        string.replaceAll("[^0-9]", " ");
        
    }
}