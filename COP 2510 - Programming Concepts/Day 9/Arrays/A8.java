import java.util.Scanner;

// File name: A8.java
// This program is a 2-D or rectangular array exercise.
// It lets user specify 
// (1) the number of students and tests, 
// (2) how scores are entered: by student or by test
// (3) scores (e.g., 70.25, 91, 0, etc.) of all students and tests
// This program will use a 2D array to store all scores:
//  -if scores are entered by student, each row of the array stores scores of one student.
//  -if scores are entered by test, each row of the array stores scores of one test.
// This program then print the 2D array to display all scores entered. 
// No matter how data are stored in the 2D array, this program will compute and display
// (1) average score of each test and store each average at the end of each test(row or column) 
// (2) average score of each student and store each average at the end of each student (row or column)
// (3) average score of all students of all tests, which is stored in the bottom-right cell of
//     the array and can be computed by average of the right-most column or average of the bottom row.
// All averages must be displayed up to three decimal digits.
// For example, if there are three students and two tests entered by test, then the array should
// contain 3 rows and 4 columns and would look like below:
//
//                                      student-1   student-2   student-3   avg_of_each_test
//                       test-1           77           81         100             86.0
//                       test-2           92            0          72             54.667
//                avg_of_each_student     84.5        40.5        86.0            70.333
//

// {{Student1} 
//, {Student2} 
//, {Student3}}

public class A8{
  static Scanner read = new Scanner(System.in);

  public static String ReadString(String message){
    System.out.print(message);
    return read.nextLine();
  }

    public static double[] convertFromStringArray(String[] numbers){
    double[] doubles = new double[numbers.length];
    for (int i = 0; i < numbers.length; i++){
      doubles[i] = Double.parseDouble(numbers[i]);
    }
    return doubles;
  }

  public static double[][] AskScoresTests(int numberTests, int numberStudents){
    double[][] scores = new double[numberTests + 1][numberStudents + 1];
    double totalForAvg = 0;
    for(int j = 0; j < numberStudents; j++){
      for(int i = 0; i < numberTests; i++){
        scores[i][j] = Double.parseDouble(ReadString("Enter score for test #" + (i+1) +" for student #" + (j+1)));
        totalForAvg += scores[i][j];
      }
      scores[numberTests][numberStudents] = totalForAvg/(numberTests);
    }
    return scores;
  }
  public static double[][] AskScoresStudents(int numberTests, int numberStudents){
    double[][] scores = new double[numberTests + 1][numberStudents];
    double totalForAvg = 0;
    for(int j = 0; j < numberTests; j++){
      for(int i = 0; i < numberStudents; i++){
        scores[i][j] = Double.parseDouble(ReadString("Enter score for test #" + (i+1) +" for student #" + (j+1)));
        totalForAvg += scores[i][j];
      }
      scores[numberTests][numberStudents] = totalForAvg/(numberTests);
    }
    return scores;
  }
  public static int HowManyStudents(){
    return Integer.parseInt(ReadString("How many students?"));
  }
  public static int HowManyTests(){
    return Integer.parseInt(ReadString("How many tests?"));
  }
  public static String HowToEnter(){
    return ReadString("How to enter, students or tests?");
  }

}