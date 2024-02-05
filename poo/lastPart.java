import java.util.Scanner;


public class lastPart{
    public static void main(String[] args){
        Implementations f = new Implementations();
        Scanner line = new Scanner(System.in);
        switch(args[0]){
            case "1":
                double graus = line.nextDouble();
                System.out.println("Em graus Farenheit : " + f.celsiusParaFarenheit(graus));
                break;
            case "2":
                int a = line.nextInt();
                int b = line.nextInt();
                System.out.println("O máximo dos números é " + f.maximoNumeros(a,b));
                break;
            case "3":
                String name = line.nextLine();
                double saldo = line.nextDouble();
                System.out.println(f.criaDescricaoConta(name,saldo));
                break;
            case "4":
                double value = line.nextDouble();
                double rate = line.nextDouble();
                System.out.println("A bolla wata costs " + f.eurosParaLibras(value,rate) + "£");
                break;
            case "5":
                a = line.nextInt();
                b = line.nextInt();
                double average = f.media(a,b);
                if(a == f.maximoNumeros(a,b)) System.out.println(a + " > " + b + "\nMédia : " + average);
                else  System.out.println(b + " > " + a + "\nMédia : " + average);
                break;
            case "6":
                a = line.nextInt();
                System.out.println(a + "! = " +f.factorial(a));
                break;
            default:
                System.out.println("Nada válido foi inserido!");
                break;
        }
        line.close();
    }
    public static class Implementations{
        public double celsiusParaFarenheit(double graus){
            return (graus * 1.8) + 32;
        }
        public int maximoNumeros(int a, int b){
            if(a > b) return a;
            else return b;
        }
        public String criaDescricaoConta(String nome, double saldo){
            String info = "Nome: " + nome + "\nSaldo:" + saldo;
            return info;
        }

        public double eurosParaLibras(double valor, double taxaConversao){
            return valor * taxaConversao;
        }
        public double media(int a,int b){
            return (a + b) / 2;
        }
        public long factorial(int num){
            long f = num;

            for(int i = num - 1;i > 1;i--){
                f *= i;
            }
            return f;
        }
    }
}