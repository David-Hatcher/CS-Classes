import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

public class ArrayListBubbleSort {
  public static void swap(ArrayList<Integer> data, int index1, int index2){
    int num1 = data.get(index1);
    int num2 = data.get(index2);
    data.remove(index1);
    data.add(index1, num2);
    data.remove(index2);
    data.add(index2, num1);
  }
  public static void arrayListBubbleSort(ArrayList<Integer> data){
    for(int i = 0; i < data.size(); i++){
      for(int j = 0; j < data.size(); j++){
        if(data.get(i) > data.get(j)){
          swap(data,i,j);
        }
      }
    }
  } 
  public static int randomGenerator(int min, int max){
    Random rand = new Random();
    return rand.nextInt(max-min+1)+min;    
  }
  public static void randomArrayList(ArrayList<Integer> data,int min, int max,int length){
    for(int i = 0; i < length; i++){
      int numbToAdd = randomGenerator(min, max);
      while(data.contains(numbToAdd)){
        numbToAdd = randomGenerator(min, max);
      }
      data.add(numbToAdd);
    }
  }
  public static void main(String[] args) {
    ArrayList<Integer> numbers = new ArrayList<Integer>();
    randomArrayList(numbers, -12, 12, randomGenerator(1, 15));
    System.out.println(numbers);
    arrayListBubbleSort(numbers);
    System.out.println(numbers);
  }
}