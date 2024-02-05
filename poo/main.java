import java.util.Scanner;
public class main{
    public static void max(int a,int b){
        if(a>b) System.out.println("Max : " + a);
        else System.out.println("Max : " + b);
    }
    public static void main(String[] args){
        Scanner line = new Scanner(System.in);
        System.out.println("Indique os números: ");
        int b = line.nextInt();
        int a = line.nextInt();
        max(a,b);
        line.close();
    }
}

/*public class main {
    public static void main(String[] args){
        if(args.length > 0) {
            for(int i = 0;i < args.length;i++)
            System.out.println(args[i]);
        }
        else System.out.println("Não existe argumentos");
    }
}*/