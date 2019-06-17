// File name: A1.java
// This program uses only its main() to sort and print in ascending order for 
// 7 integers in the following steps:
// (1) It has 7 integers hard coded in an array with no particular order. 
//These integers are 11, 230, 0, -6, 8, -44, and 59.
// (2) It uses two different for-loop statements to print the array contents twice
//before they are sorted. Each printed integer is separated from the next number
//by a space. The first print should be a standard for-loop that needs a counter 
//or index to control its loops, and the other print uses an enhanced for-loop 
//that uses ":" without counter or index.
// (3) It uses the sort() static method of Arrays class to sort the 7 integers of
//the array in ascending order.
// (4) It repeats the above step (2) after the array is sorted.

import java.util.Arrays;


public class A1{

  public static void main(String[] args) {
    int[] arrInts = {11, 230, 0, -6, 8, -44, 59};

    for(int i = 0; i < arrInts.length; i++){
      System.out.print(arrInts[i] + " ");
    }
    System.out.println();

    for (int number : arrInts) {
      System.out.print(number + " ");
    }
    System.out.println();
    Arrays.sort(arrInts);
    for(int i = 0; i < arrInts.length; i++){
      System.out.print(arrInts[i] + " ");
    }
    System.out.println();

    for (int number : arrInts) {
      System.out.print(number + " ");
    }
    System.out.println();
  }

}