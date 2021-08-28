import java.util.ArrayList;
import java.util.Arrays;

public class Quiz7Practice {
  private static void revArrayList(ArrayList<Integer> data){
    for(int i = 0; i < data.size();i++){
      data.add(i,data.remove(data.size()-1));
    }
  }
  private static void revArrayList2(ArrayList<Integer> data){
    ArrayList<Integer> temp = new ArrayList<Integer>();
    int iterateEnd = data.size();
    for(int i = 0; i < iterateEnd; i++){
      temp.add(data.remove(data.size()-1));
    }
    data.addAll(temp);
  }
  private static void revArrayList3(ArrayList<Integer> data){
    ArrayList<Integer> temp = new ArrayList<Integer>();
    for (int number : data) {
      temp.add(0,number);
    }
    data.clear();
    data.addAll(temp);
  }
  private static void cleanArrayList(ArrayList<Integer> data){
    ArrayList<Integer> temp = new ArrayList<Integer>();
    for (int number : data) {
      if(number < 1 || number > 4){
        temp.add(number);        
      }
    }
    data.removeAll(temp);
  }
  public static void main(String[] args) {
    ArrayList<Integer> numbers1 = new ArrayList<Integer>(Arrays.asList(0,1,2,3,4,5));
    ArrayList<Integer> numbers2 = new ArrayList<Integer>(Arrays.asList(0,1,2,3,4,5));
    ArrayList<Integer> numbers4 = new ArrayList<Integer>(Arrays.asList(0,1,2,3,4,5));
    ArrayList<Integer> numbers3 = new ArrayList<Integer>(Arrays.asList(0,1,2,3,4,5));
    System.out.println("Before reverse 1" + numbers1);
    revArrayList(numbers1);
    System.out.println("After reverse 1" + numbers1);
    System.out.println("Before reverse 2" + numbers2);
    revArrayList2(numbers2);
    System.out.println("After reverse 2" + numbers2);
    System.out.println("Before Reverse 3" + numbers4);
    revArrayList3(numbers4);
    System.out.println("After reverse 3" + numbers4);
    System.out.println("Before Cleaning" + numbers3);
    cleanArrayList(numbers3);
    System.out.println("After Cleaning" + numbers3);
  }
}