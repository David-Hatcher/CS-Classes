package A1.B2.C3;

import java.util.Random;

public class Quiz5 {
    public static void main(String args[]) {
        Random r = new Random();
        int numberToFind = Integer.parseInt(args[0]);
        int randomNumber = 10000000;
        int count = 1;
        int positive = 0;
        int negative = 0;
        int zero = 0;
        while(randomNumber != numberToFind){
            if(numberToFind > 5 || numberToFind < -5){
                System.out.println("Number not between -5 and 5");
                break;
            }
            randomNumber = r.nextInt(11) - 5;
            System.out.println("(" + count + ")\t" + randomNumber);
            count++;
            if(randomNumber > 0){positive++;}
            else if(randomNumber < 0){negative++;}
            else{zero++;}
        }
        System.out.println("--------------------------");

        System.out.println("positive = " + positive);
        System.out.println("negative = " + negative);
        System.out.println("zero = " + zero);
    }
}
