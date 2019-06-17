// File name: A4.java
// This program is based on A3.java and modifies it to meet the following items:
// (1) It still contains the 7 integers in an array as A1 to A3 but prints the array
//       only once.// (2) It prints the minimum and maximum of the 7 integers in the array by calling
//       its own two methods, min() and max(), both have an integer array as input
//     parameter and returns an integer. To implement these two new methods in A4,
//       consider to use the sort() method of Arrays and sort_d() method done inA3.java.

public class A4{
    public static int min(int[] numbers){
        int min = numbers[0];
        for (int number : numbers) {
            if(number < min){
                min = number;
            }
        }
        return min;
    }
    public static int max(int[] numbers){
        int max = numbers[0];
        for (int number : numbers) {
            if(number > max){
                max = number;
            }
        }
        return max;
    }
    public static void main(String[] args){
    int[] numbers = {11, 230, 0, -6, 8, -44, 59};
        System.out.println("The minimum value in numbers = " + min(numbers));
        System.out.println("The maximum value in numbers = " + max(numbers));
    }
}