import java.util.ArrayList;

abstract class FindMinMaxArray{
  public String findMinMax(int[] data){
    int max = data[0];
    int min = data[0];
    for (int number : data) {
      max = number > max ? number : max;
      min = number < min ? number : min;
    }
    return ("Max = " + max + "\nMin = " + min);
  }
}
final class FindMinMaxArrayList extends FindMinMaxArray{
  final public String findMinMax(ArrayList<Integer> data){
    int[] dataArray = new int[data.size()];
    for(int i = 0; i < dataArray.length; i++){
      dataArray[i] = data.get(i);
    }
    return super.findMinMax(dataArray);
  }
  final public String findMinMax(int[] data){
    return super.findMinMax(data);
  }
}
// class whatever extends FindMinMaxArrayList{
//   public String findMinMax(ArrayList<Integer> data){
//     super.findMinMax(data);
//   }
// }
class FinalPracticeAll{
  public static void println(Object message){
    System.out.println(message);
  }
  public static int[] checkForViablility(String[] data)throws Exception{
    int[] dataArray = new int[data.length];
    try {
      for(int i = 0; i < 3; i++){
        dataArray[i] = Integer.parseInt(data[i]);
      }
    } catch (NumberFormatException e) {
      throw new Exception("<ERROR> Incorrect type of one or more input data. Please re-run the program.");      
    } catch (IndexOutOfBoundsException e){
      throw new Exception("<ERROR> Insufficient input data. Please re-run the program.");
    }
    return dataArray;
  }
  public static ArrayList<Integer> convertToArrayList(int[] data){
    ArrayList<Integer> dataArrayList = new ArrayList<Integer>();
    for (int number : data) {
      dataArrayList.add(number);
    }
    return dataArrayList;
  }
  public static void RunProgram(String[] data){
    FindMinMaxArrayList fmmal = new FindMinMaxArrayList();
    try {
      int[] dataArray = checkForViablility(data);
      println("Min/Max from array:\n" + fmmal.findMinMax(dataArray));
      ArrayList<Integer> dataArrayList = convertToArrayList(dataArray);
      println("Min/Max from arraylist:\n" + fmmal.findMinMax(dataArrayList));
    } catch (Exception e) {
      println(e.getMessage());
    }
  }

  public static void main(String[] args) {
    RunProgram(args);
  }
}

class polyPractice {
public static void toString() {


}



}