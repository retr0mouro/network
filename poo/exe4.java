import java.util.Scanner;


public class exe4{
    public static void main(String[] args){
        Scanner line = new Scanner(System.in);
        int n = line.nextInt();
        int[] temp = new int[n];
        int sum = 0;
        for(int i = 0;i < n;i++){
            temp[i] = line.nextInt();
            sum += temp[i];
        }
        line.close();
        int average = sum / n;

        int maxVariation = 0;
        int dayWithMaxVariation = 0;

        for (int i = 1; i < n; i++) {
            int variation = Math.abs(temp[i] - temp[i - 1]);
            if (variation > maxVariation) {
                maxVariation = variation;
                dayWithMaxVariation = i;
            }
        }
        System.out.printf("A média das %d temperaturas foi de %d graus.\n",n,average);
        System.out.println("A maior variação registou-se entre os dias " + dayWithMaxVariation + " e " + (dayWithMaxVariation + 1) + ", tendo a temperatura subido/descido " + maxVariation + " graus");
    }
}