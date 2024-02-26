import java.util.Scanner;
import pacote.*;

public class Main{
    public static void main(String[] args){
        Scanner line = new Scanner(System.in);
        switch(line.nextInt()){
            case 1:
                Circulo c = readCirculo(line);
                System.out.println(c.toString());
                break;
            case 2:
                Sensor s = readSensor(line);
                System.out.println("A pressão é " + s.getPressao());
                s = null;
                break;
            case 3:
                Telemovel t = new Telemovel();
                System.out.println(t.toString());
                break;
            default:
                System.err.println("Funcao nao implementada");
                break;
        }
        line.close();
    }
    public static Circulo readCirculo(Scanner line){
        System.out.print("Insira coordenada x: ");
        double x = line.nextDouble();
        System.out.print("Insira coordenada y: ");
        double y = line.nextDouble();
        System.out.print("Insira raio: ");
        double raio = line.nextDouble();
        return new Circulo(x,y,raio);
    }
    public static Sensor readSensor(Scanner line){
        System.out.print("Insira a pressao: ");
        return new Sensor(line.nextDouble());
    }
}