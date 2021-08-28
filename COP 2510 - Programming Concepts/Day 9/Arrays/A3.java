// File name: A3.java
// This program is based on A2.java but extends it to allow user to enter 'a' or'd' 
// at run time to sort the integer array in either ascending or descending order. The 
// message it prompts user should read as
//
//          To sort, enter 'a' for ascending or 'd' for descending: 
//
// Because the Arrays class supports only sort() method to sort an array in ascending
// order, this A3 program implements sort_d() as a new method whose input parameter is
// the array to sort.
//
// The main() then will call the sort() of Arrays or its own sort_d() to sort the array, 
// depending on the input of user.
//
// All other parts remain the same as in A2.java.
import java.util.Arrays;
import java.util.Scanner;

public class A3{
    public static void printArray_1(int[] numbers){
        for (int number : numbers) {
            System.out.print(number + " ");
          }
          System.out.println();
    }
    public static void sort_d(int[] numbers){
        int numbersEnd = numbers.length -1;
        Arrays.sort(numbers);
        int[] numberReversed = new int[numbers.length];
        for(int i = numbersEnd; i >= 0; i--){
            numberReversed[numbersEnd -i] = numbers[i];
        }
        printArray_1(numberReversed);
    }
    public static void main(String[] args) {
    int[] numbers = {11, 230, 0, -6, 8, -44, 59};

        Scanner ro = new Scanner(System.in);
        System.out.print("To sort, enter 'a' for ascending or 'd' for descending: ");
        String order = ro.nextLine();
        if(order.equalsIgnoreCase("a")){
            Arrays.sort(numbers);
            printArray_1(numbers);
        }
        else{
            sort_d(numbers);
        }
        ro.close();
    }
}