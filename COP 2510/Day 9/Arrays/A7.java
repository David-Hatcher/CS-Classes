import java.util.Arrays;
import java.util.Scanner;

// File name: A7.java
// It is true that, once an array is defined or initialized with a size, Java doesn't allow it to
// be re-sized at any time. If re-sizing an array is needed, instead of using anarray, other data 
// structures like Vector or ArrayList or Map is recommended, which will be learned in C++, your 
// 3rd programming course COP3331.
// Rather than re-sizing an existing array, this program first lets user enter two lines of comma-
// separated double-type values and convert them to build two double type arraysexactly like in A6.
// Then, it calls a new method, merge(), to merge the two input double type arrays and return the
// "merged" array to the caller, i.e., main(), where the merged array is printedto verify the merge
// effect.

public class A7{
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
  public static double[] merge(double[] numbers1, double[] numbers2){
    int totalLength = numbers1.length + numbers2.length;
    double[] merged = Arrays.copyOf(numbers1, totalLength);
    for(int j = 0 , i = numbers1.length; i < totalLength; i++,j++){
      merged[i] = numbers2[j];
    }
    return merged;
  }
  public static void main(String[] args) {
    String message_1 = "Enter comma-separated double-type values of array 1:";
    String message_2 = "Enter comma-separated double-type values of array 2:";
    double[] numbersString_1 = convertFromStringArray(ReadString(message_1).split(","));
    double[] numbersString_2 = convertFromStringArray(ReadString(message_2).split(","));
    double[] merged = merge(numbersString_1, numbersString_2);
    printArray_2(merged);
  }
}