import java.util.Arrays;;

public class Day9{
  /*chapter 10: Arrays
  array - multivalue variable
  type[] arrayName;
  arrayName = new type[length];
  ********Single Line *********
  type[] arrayName = new type[length]
  type arrayName[] = new type[length]
  double[] prices = new double[4];
  Can create an array of objects as well
  must import object first.
  Product[] products = new Product[5];

  ******USING CONSTANTS*******
  final int TITLE_COUNT = 100;
  String[] titles = new String[TITLE_COUNT];
  
  ******USING VARIABLES*******
  int val = input.nextInt();
  String titles = new String[val];

  ******INDEXING**********  
  double[] prices = new double[4];
  prices[0] =14.95;
  prices[1] = 12.95;....

  double[] prices = {14.95,12.95,...,...};
  if you add a comma at the end there will be an extra
  index with no value

  ********looping*********
  using mostly for loops

  ##Foreach##

  does this for each item in the collection

  *******Two-Dimensional Arrays******
  type[][] arrayName = new type[rowCount][columnCount];
  
  +++++++A 3x2 Array++++++++
  int[][] numbersTable = new int[3][2];
  */
 public static void main(String[] args) {
   /******Array******/
  double[] prices = new double[4];
  prices[0] = 14.95;
  prices[1] = 12.95;
  prices[2] = 11.95;
  prices[3] = 9.95;
  /*******Looping*******/
  int[] values = new int[10];
  for(int i = 0; i < values.length; i++){//obj.length is a field in that array
    values[i] = i;
  }
  for(int i = 0; i < prices.length;i++){
    System.out.println(prices[i]);
  }
  double sum = 0.0;
  for(int i = 0; i < prices.length; i++){
    sum += prices[i];
  }
  double average = sum/prices.length;
  System.out.println("Average" + average);
  for (double price : prices) {//same as for loop
    System.out.println(price);
  }
  sum = 0;
  for (double price : prices) {
    sum += price;
  }

  /*****2D Arrays*****/
  int[][] numbersTable = new int[3][2];
  numbersTable[0][0] = 1;
  numbersTable[0][1] = 2;
  numbersTable[1][0] = 3;
  numbersTable[1][1] = 4;
  numbersTable[2][0] = 5;
  numbersTable[2][1] = 6;

  //Can also use 
  int[][] numbersTable2 = { {1,2,3,4}, {5,6,7,8,9,10}, {11,12,13} };
  //can have different number of elements, this create a jagged array.

  for (int[] row : numbersTable2) {
    for (int column : row) {
      System.out.print(column + " ");
    }
    System.out.print("\n");
  }
  //1 2 3 4
  //5 6 7 8 9 10
  //11 12 13

  //Can use methods on arrays
  //fill(array,value)
  //sort(array)
  //binarysearch
  int[] quantities = new int[5];  //all set to 0 automatically
  Arrays.fill(quantities,1);      //all set to 1 automatically **static method**

  int[] numbers = {2,6,4,1,8,5,9,3,7,0};
  Arrays.sort(numbers);           //sorts by value smallest -> largest
  for (int number : numbers) {
    System.out.print(number + " ");  // 0 1 2 3 4 5 6 7 8 9
  }
  String[] productCodes = {"mysql", "jsp", "java"};
  Arrays.sort(productCodes);
  int index = Arrays.brinarySearch(productCodes, "mysql");  //sets index to 2

  //copyOf(array, length)
  //equals(array1, array2)
  double[] grades = {92.3, 88.0, 95.2, 90.5};
  double[] percentages = grades; //this does not make a copy, this instead allows them both refer to the same array.
  percentages[1] = 70.2;         //changes grades[1] as well
  System.out.println(grades[1]); //70.2 

  //Instead you must use double[] percentages = Arrays.copyOf(grades, grades.length)
  //if(grades == percentage){} //this will check if these arrays refer to same array NOT if they have the same values
  //if (Arrays.equal(grades,percentages)) // checks if both arrays refer to the same data values
 }
}