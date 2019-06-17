import java.util.Arrays;

// File name: A2.java
// This program does exactly the same function as A1.java except it defines two
// additional methods: printArray_1() and printArray_2(), to print an integer array
// on screen. Both methods have one input parameter, which must be an integer array,
// and return no data. printArray_1() must use a standard for-loop to print the array
// and printArray_2() must use an enhanced for-loop to print.
// 
// The main() of A2 then calls both printArray_1() and printArray_2() before and after
// the array is sorted to print its contents.

public class A2{
  public static void printArray_1(int[] numbers){
    for(int i = 0; i < numbers.length; i++){
      System.out.print(numbers[i] + " ");
    }
    System.out.println();
  }
  public static void printArray_2(int[] numbers){
    for (int number : numbers) {
      System.out.print(number + " ");
    }
    System.out.println();
  }
  public static void main(String[] args) {
    int[] numbers = {11, 230, 0, -6, 8, -44, 59};
    printArray_1(numbers);
    printArray_2(numbers);
    Arrays.sort(numbers);
    printArray_1(numbers);
    printArray_2(numbers);
  }
}