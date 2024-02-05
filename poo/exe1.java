import java.util.Scanner;

public class exe1{
    public static int weekDay(int day, int month,int year){
        int sum = 0;
        if(year > 1900){
            sum += year - 1900;
            sum += (sum / 4);
            if((year % 4 == 0) && (month == 1 || month == 2)){
                sum--;
            }
            sum += day;
            if(month == 1){
                sum = sum % 7;
                return sum;
            }else{
                if(month == 2){
                    sum += day;
                    sum = sum % 7;
                    return sum;
                }
                sum += 28;
                for(int i = 1;i < month;i++){
                    if(i % 2 == 1){
                        sum += 31;
                    }else{
                        sum += 30;
                    }
                }
                sum += day;
            }
        }else{
            sum += 1900 - year;
            sum += (sum / 4);
            if((year % 4 == 0) && (month == 1 || month == 2)){
                sum--;
            }
            sum += day;
            if(month == 1){
                sum = sum % 7;
                return sum;
            }else{
                if(month == 2){
                    sum += day;
                    sum = sum % 7;
                    return sum;
                }
                sum += 28;
                for(int i = 1;i < month;i++){
                    if(i % 2 == 1){
                        sum += 31;
                    }else{
                        sum += 30;
                    }
                }
                sum += day;
            }

        }
        sum = sum % 7;
        return sum;
    }

    public static String dateSum(int d1,int m1,int y1,int d2,int m2,int y2){
        int sum = 0;
        sum += (y2 - y1 - 1) * 365;
        int mDiff = (m2 - m1) % 12;
        if(mDiff != 0){
            for(int i = 0; i < mDiff;i++){
                if((m1 + i) % 12 == 1){
                    sum += 28;
                    continue;
                }
                if((m1 + i) % 2 == 1){
                    sum += 31;
                    continue;
                }else{
                    sum += 30;
                }
            }
        }else{
            sum += d2 - d1;
        }
        String answer = "";
    }
    public static void main(String[] args){
        if(args[0] == "week"){
            Scanner line = new Scanner(System.in);
            System.out.printf("Insert the date in the format : \n\n\tDD/MM/YY\n\n");
            int day = line.nextInt();
            int month = line.nextInt();
            int year = line.nextInt();
            int weekDay = weekDay(day,month,year);
            switch(weekDay){
                case 0:
                    System.out.println("The date inserted is a Sunday");
                    break;
                case 1:
                    System.out.println("The date inserted is a Monday");
                    break;
                case 2:
                    System.out.println("The date inserted is a Tuesday");
                    break;
                case 3:
                    System.out.println("The date inserted is a Wednesday");
                    break;
                case 4:
                    System.out.println("The date inserted is a Thursday");
                    break;
                case 5:
                    System.out.println("The date inserted is a Friday");
                    break;
                case 6:
                    System.out.println("The date inserted is a Saturday");
                    break;
                
            }
            line.close();
        }
        if(args[0] == "sumOfDates"){
            Scanner line = new Scanner(System.in);
            System.out.println("Insert two dates, the firt must be more ancient:");
            int d1 = line.nextInt();
            int m1 = line.nextInt();
            int y1 = line.nextInt();
            int d2 = line.nextInt();
            int m2 = line.nextInt();
            int y2 = line.nextInt();
            System.out.printf("%sD 00H 00M 00S",date);

        }
    }
}
