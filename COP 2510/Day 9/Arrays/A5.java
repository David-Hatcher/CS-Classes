import java.util.Scanner;

// File name: A5.java
// This program is different from A1~A4.java. 
// A5 prompts the following message to user to enter data of two arrays of any size, each contains 
// same or different numbers of double-type values. 
//          Enter comma-separated double-type values of array 1:
//          Enter comma-separated double-type values of array 2:
// Each value entered must be separated by ",". 
// This program then process both lines of input and store every number into a double-type array,
// one per input line.
// Because every keyboard input (up to the press of Enter key) is treated as a string, A5 makes
// use of the split() method of String class to automatically extract every value (still as a 
// string) from the input line and store it in a given String array. To use thissplit() method, 
// a string (e.g., "," in our case here) that is used to separate items in the input line must 
// be given as the method's input parameter. For instance, if the input line is saved in a string
// variable called data, then data.split(",") will return a String array containing all extracted
// items.
// Once the two String arrays are built, A5 calls its another new method, convertFromStringArray(),
// to convert every string of an array to double type. The String array to convert is passed to
// this method as input parameter.
// After conversion, A5 uses one of the two methods, printArray_1() or printArray_2(), which are
// done in A2 to print contents of the two double type arrays.


public class A5{
  static Scanner ri = new Scanner(System.in);

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

  public static void main(String[] args) {
  String message_1 = "Enter comma-separated double-type values of array 1:";
  String message_2 = "Enter comma-separated double-type values of array 2:";
  String[] numbersString_1 = ReadString(message_1).split(",");
  String[] numbersString_2 = ReadString(message_2).split(",");
  printArray_2(convertFromStringArray(numbersString_1));
  printArray_2(convertFromStringArray(numbersString_2));  
  }
}