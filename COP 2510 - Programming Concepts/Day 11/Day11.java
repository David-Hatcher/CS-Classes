
public class Day11{
    //Concurrency - allows multiple users access the same data at once.
    public static void rev(int[] data){
        //java calls by reference;
        //so this changes the original rather than the one put into the method
        for(int i = 0; i <(data.length-1)/2; i++){
            int temp = data[i];
            data[i] = data[data.length-1-i];
            data[data.length-1-i] = temp;
        }
        
    }
    public static void print(int[] data){
        for (int number : data) {
            System.out.println(number);
        }
    }
    public static void main(String[] args) {

    }
}