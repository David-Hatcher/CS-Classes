import java.util.Scanner;

// File name: A6.java
// This program uses A5.java and modifies it to include the following functions:
// (1) It keeps all A5 functions until both arrays are printed.
// (2) It implements a new method, swap(), which needs two double type arrays as its two input
//       parameters but returns nothing. It swaps element by element of the two input arrays until 
//     the shorter one has all of its elements swapped. 
// (3) It calls swap to exchange contents of the two arrays. For example, if the first array arr1
//     contains { 1.1 2.2 3.3 } and the second one arr2 contains { 4.4 5.5 6.6 7.7 8.8 }, after 
//     calling swap(arr1, arr2), arr1 = { 4.4 5.5 6.6 } and arr2 = { 1.1 2.2 3.3 7.7 8.8 }.
// (4) It uses either printArray_1() or printArray_2() to print both arrays after they are swapped.

public class A6{
  static Scanner ri = new Scanner(System.in);
  static double[] numbersString_1;
  static double[] numbersString_2;

  
  public static String ReadString(String message){
    System.out.print(message);
    return ri.nextLine();
  }
  public static double[] convertFromStringArray(String[] numbers){
    double[] doubles = new double[numbers.length];
    for (int i = 0; i < numbers.length; i++){
      doubles[i] = Double.parseDouble(numbers[i]);
    }
    return doubles;
  }
  public static void printArray_2(double[] numbers){
    for (double number : numbers) {
      System.out.print(number + " ");
    }
    System.out.println();
  }
  public static void swap(double[] numbers1, double[] numbers2){
    int i = 0;
    while(true){
      try {
        double temp = numbers1[i];
        numbers1[i] = numbers2[i];
        numbers2[i++] = temp;
        
      } catch (Exception e) {
        break;
      }
    }
  }
  public static void main(String[] args) {
    String message_1 = "Enter comma-separated double-type values of array 1:";
    String message_2 = "Enter comma-separated double-type values of array 2:";
    numbersString_1 = convertFromStringArray(ReadString(message_1).split(","));
    numbersString_2 = convertFromStringArray(ReadString(message_2).split(","));
    swap(numbersString_1, numbersString_2);
    printArray_2(numbersString_1);
    printArray_2(numbersString_2);
  }
}