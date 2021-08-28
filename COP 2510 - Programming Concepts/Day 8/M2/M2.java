import Summer2019.Midterm.Random4Digits;
import java.util.*;

public class M2{
    private static Scanner read = new Scanner(System.in);
    private static Random rand = new Random();
    private static int RandomNumGen(){
        return (rand.nextInt(4) + 1);
    }
    private static String go(int max){
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
    public static void main(String[] args) {
        Random4Digits random = new Random4Digits();
        System.out.print("How many digits?");
        int max = Integer.parseInt(read.nextLine());
        String total = go(max);
        System.out.println(total);
        String totalRandom4Digits = random.go(max);
        System.out.println(totalRandom4Digits);
    }
}