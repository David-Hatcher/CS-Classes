import java.util.*;

public class M1{
    private static Random rand = new Random();
    private static Scanner read = new Scanner(System.in);
    private static int RandomNumGen(){
        return (rand.nextInt(4) + 1);
    }

    public static void main(String[] args) {
        System.out.print("How many digits?");
        int max = Integer.parseInt(read.nextLine());
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
            System.out.println(total);}
        else{
            System.out.println("Minimum of 2 digits is required!");
        }
    }
}