import java.util.Scanner;
import java.time.LocalDateTime;
import java.time.Month;
import java.time.DayOfWeek;

public class TestePrograma{
    public static void main(String[] args){
        Scanner line = new Scanner(System.in);
        Ficha1 f = new Ficha1();
        System.out.print("Insira o exercício a testar:");
        int exe = line.nextInt();
        int n = 0;
        switch(exe){
            case 1:
                int year10 = line.nextInt();
                int month10 = line.nextInt();
                int day10 = line.nextInt();
                
                LocalDateTime date = LocalDateTime.of(year10,month10,day10,0,0,0);


                int ans = (year10 - 1900) * 365;
                ans += (year10 - 1900) / 4;
                if((month10 == 1 || month10 == 2) && // condicao para somar
                 ((year10 % 4 == 0 && year10 % 100 != 0) || (year10 % 4 != 0 && year10 % 100 == 0))){ // condicao para ser bisexto
                    ans--;
                }

                ans += date.getDayOfYear();

                ans = ans % 7;

                System.out.println(DayOfWeek.of(ans));

                break;
            
            case 2:
                int year1 = line.nextInt();
                int month1 = line.nextInt();
                int day1 = line.nextInt();
                int hour1 = line.nextInt();
                int minute1 = line.nextInt();
                int second1 = line.nextInt();

                int year2 = line.nextInt();
                int month2 = line.nextInt();
                int day2 =  line.nextInt();
                int hour2 = line.nextInt();
                int minute2 = line.nextInt();
                int second2 = line.nextInt();
                LocalDateTime time1 = LocalDateTime.of(year1,month1,day1,hour1,minute1,second1);
                LocalDateTime time2 = LocalDateTime.of(year2,month2,day2,hour2,minute2,second2);
                String answer = f.e2(time1,time2);
                System.out.println(answer);
                break;
            case 3:
                n = line.nextInt();
                int[] num = new int[n];
                for(int i = 0;i < n;i++){
                    num[i] = line.nextInt();
                }
                int[] nova = f.e3(num,n);
                System.out.println("[0,5[ : " + nova[0]);
                System.out.println("[5,10[ : " + nova[1]);
                System.out.println("[10,15[ : " + nova[2]);
                System.out.println("[15,20[ : " + nova[3]);
                break;
            case 4:
                n = line.nextInt();
                int[] numbers = new int[n];
                for(int i = 0;i < n;i++){
                    numbers[i] = line.nextInt();
                }
                int[] values = f.e4(numbers,n);
                System.out.println("A média das " + n + " temperaturas foi de " + values[0]);
                System.out.println("A maior variação registou-se entre os dias " + (values[1] - 1) + " e " + values[1] + 
                ", tendo a temperatura subido/descido " + values[2]);
                break;
            case 5:
                n = 0;
                while(n == 0){
                    float height = line.nextFloat();
                    if(height == 0) {
                        n++;
                        continue;
                    }
                    float width = line.nextFloat();
                    float area = f.e5(height,width);
                    System.out.printf("\n%.5f\n",area);
                }
                break;
            case 6:
                n = line.nextInt();
                for(int i = n;i != 0;i--){
                    if(f.e6(i) == 1){
                        System.out.println(i);
                    }
                }
                System.out.println("Quer jogar outra vez?\nY/N");
                String option = line.next();
                while(option.charAt(0) != 'n' && option.charAt(0) != 'N'){
                    n = line.nextInt();
                    for(int i = n;i != 0;i--){
                        if(f.e6(i) == 1){
                            System.out.println(i);
                        }
                    }
                    System.out.println("Quer jogar outra vez?\nY/N");
                    option = line.next();
                }
                break;
            case 7:
                int year = line.nextInt();
                int month = line.nextInt();
                int day = line.nextInt();
                LocalDateTime birth = LocalDateTime.of(year,month,day,0,0,0);
                float age = f.e7(birth);
                LocalDateTime now = LocalDateTime.now();
                System.out.println("\nO utilizador tem " + age + " horas de idade, à data " + (now.getYear()) + "/" + (now.getMonth().getValue()) + "/"
                + now.getDayOfMonth() + " " + now.getHour() + ":" + now.getMinute() + ":" + now.getSecond());
                break;
        }
        line.close();
    }

    public static class Ficha1{
        private int weekDay(int day, int month,int year){
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
        private String dateSum(int d1,int m1,int y1,int d2,int m2,int y2){
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
            return answer;
        }
        public String e1(int day,int month,int year){
            int wDay = weekDay(day,month,year);
            switch(wDay){
                case 0:
                    return "Sunday";
                case 1:
                    return "Monday";
                case 2:
                    return "Tuesday";
                case 3:
                    return "Wednesday";
                case 4:
                    return "Thursday";
                case 5:
                    return "Friday";
                case 6:
                    return "Saturday";
                default:
                    return "";
            }
        }

        // Exercise 2
        private int[] timeDiff(LocalDateTime time1, LocalDateTime time2){
            int seconds = 0;
            int minutes = 0;
            int hours = 0;
            int days = 0;
            int months = 0;
            int years = 0;


            // Count seconds, with carries if needed

            if(time2.getSecond() > time1.getSecond()){
                seconds += time2.getSecond() - time1.getSecond();
            }
            if(time2.getSecond() < time1.getSecond()){
                //minutes++;
                seconds += 60 - time1.getSecond();
                seconds += time2.getSecond();                           // If it does not work, decrease/increase 1 here!
            }


            // Count minutes, with carries if needed

            if(time2.getMinute() > time1.getMinute()){
                minutes += time2.getMinute() - time1.getMinute() - 1;
            }
            if(time2.getMinute() < time1.getMinute()){
                //hours++;
                minutes += 60 - time1.getMinute();
                minutes += time2.getMinute() - 1;                           // IF IT DOES NOT WORK, DECREASE/INCREASE 1 HERE!
            }


            // Count hours, with carries if needed

            if(time2.getHour() > time1.getHour()){
                hours += time2.getHour() - time1.getHour() - 1;
            }
            if(time2.getHour() < time1.getHour()){
                days++;
                hours += 24 - time1.getHour();
                hours += time2.getHour() - 1;                               // IF IT DOES NOT WORK, DECREASE/INCREASE 1 HERE!
            }


            // Count days, with carries if needed

            if(time2.getDayOfYear() > time1.getDayOfYear()){
                days += time2.getDayOfYear() - time1.getDayOfYear() - 1;
            }
            if(time2.getDayOfYear() < time1.getDayOfYear()){
                years++;
                days += 365 - time1.getDayOfYear();
                days += time2.getDayOfYear() - 1;                           // IF IT DOES NOT WORK, DECREASE/INCREASE 1 HERE!
            }

            // Count months, translating to days, adding carry to years, if needed
            if(time2.getMonth().getValue() > time1.getMonth().getValue()){
                months += time2.getMonth().getValue() - time1.getMonth().getValue();
                days += months * 30;
            }
            if(time2.getMonth().getValue() < time1.getMonth().getValue()){
                years++;
                months += 11 - time1.getMonth().getValue();
                months += time2.getMonth().getValue() - 1;                  // IF IT DOES NOT WORK, DECREASE/INCREASE 1 HERE!
                days += months * 30;
            }

            // Count years, translate to days and add carry, if needed

            if(time2.getYear() > time1.getYear()){
                years += time2.getYear() - time1.getYear();
                days += 365 * years;
            }

            //LocalDateTime answer = LocalDateTime.of(0,0,days,hours,minutes,seconds);
            int[] numbers = new int[4];
            numbers[0] = days;
            numbers[1] = hours;
            numbers[2] = minutes;
            numbers[3] = seconds;
            return numbers;
        }
        public String e2(LocalDateTime time1,LocalDateTime time2){
            int[] time = timeDiff(time1,time2);
            return time[0] + "DD " + time[1] + "H " + time[2] + "M " + time[3] + "S";
        }


        //Exercise 3
        private int[] calculateGrades(int[] args, int size){
            int[] grades = new int[4];
            grades[0] = 0;
            grades[1] = 0;
            grades[2] = 0;
            grades[3] = 0;
            for(int i = 0;i < size;i++){
                if(args[i] < 5){
                    grades[0]++;
                    continue;
                }
                if(args[i] < 10){
                    grades[1]++;
                    continue;
                }
                if(args[i] < 15){
                    grades[2]++;
                    continue;
                }
                if(args[i] <= 20){
                    grades[3]++;
                    continue;
                }
            }
            return grades;
        }
        public int[] e3(int[] args,int size){
            int[] grades = calculateGrades(args,size);
            return grades;
        }

        // Exercise 4
        private int[] calculateTemperatures(int[] args, int size){
            int sum = 0;
            sum += args[0];
            int maxVariation = 0;
            int dayMaxVariation = 0;
            for(int i = 1;i < size;i++){
                sum += args[i];
                int variation = Math.abs(args[i] - args[i - 1]);
                if(variation > maxVariation){
                    maxVariation = variation;
                    dayMaxVariation = i;
                }
            }
            int average = sum / size;
            int[] answer = new int[3];
            answer[0] = average;
            answer[1] = dayMaxVariation;
            answer[2] = maxVariation;
            return answer;
        }
        public int[] e4(int[] args,int size){
            int[] answer = calculateTemperatures(args,size);
            return answer;
        }

        // Exercise 5
        public float e5(float height,float width){
            return (height * width) / 2;
        }

        private int isPrime(int n){
            if(n == 2 || n == 3 || n == 5 || n == 7) return 1;
            if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) return 0;
            return 1;
        }
        // Exercise 6
        public int e6(int n){
            return isPrime(n);
        }

        // Exercise 7
        public float e7(LocalDateTime birth){
            LocalDateTime present = LocalDateTime.now();
            float seconds = present.getSecond() / 3600;
            float minutes = present.getMinute() / 60;
            float hours = present.getHour();
            float days = (present.getDayOfYear() - birth.getDayOfYear()) * 24;
            float months = (present.getMonth().getValue() - birth.getMonth().getValue()) * (24 * present.getMonth().maxLength());
            float years = (present.getYear() - birth.getYear()) * 8760;
            return seconds + minutes + hours + days + months + years;
        }
    }
}
