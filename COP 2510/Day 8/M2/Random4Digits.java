package Summer2019.Midterm;

import java.util.*;

public class Random4Digits{
    private Random rand = new Random();
    private int RandomNumGen(){
        return (rand.nextInt(4) + 1);
    }
    public String go(int max){
        int i = 1;
        String total = "";
        int temp = 0;
        while(i <= max){
            int current = RandomNumGen();
            while(current == temp){
                current = RandomNumGen();
            }
            total = total + Integer.toString(current);
            temp = current;
            i++;
        }
        if(max > 1){
        return total;
        }
        else{
            return "Minimum of 2 digits is required!";
        }
    }
}