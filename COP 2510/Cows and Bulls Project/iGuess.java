import java.util.*;

public class iGuess{
  static Random rand = new Random();
  public static int RandGen(int minimum, int max){
    return rand.nextInt(max-minimum+1) + minimum;
  }
  public static String[] ArrayBuilder(){
    ArrayList<String> possibles = new ArrayList<String>(Arrays.asList("v", "w" , "x", "y", "z", "5", "6", "7", "8", "9", "=", "?", "%", "$" ));
    String[] combination = new String[5];
    int randForAt = RandGen(0, 4);
    for(int i = 0; i < 5; i++){
      if(i == randForAt){
        combination[i] = "@";
      }
      else{
        String tempChar = possibles.get(RandGen(0, possibles.size()-1));
        combination[i] = tempChar;
        possibles.remove(tempChar);
      }
    }
    return combination;
  }
  public static ArrayList<ArrayList<String>> FullPossibles(){
    ArrayList<ArrayList<String>> allCombos = new ArrayList<ArrayList<String>>();
    while(allCombos.size() < 120120){
      String[] currentPossible = ArrayBuilder();            
      while(allCombos.contains(Arrays.asList(currentPossible))){
        currentPossible = ArrayBuilder();
      }
      ArrayList<String> currentToAdd = new ArrayList<String>();
      for (String str : currentPossible) {
        currentToAdd.add(str);
      }
      allCombos.add(currentToAdd);
      System.out.println(allCombos.size());
    }
    return allCombos;
  }
  public static void main(String[] args) {
    ArrayList<ArrayList<String>> allCombos = FullPossibles();
    System.out.println(allCombos);
    System.out.println(allCombos.size());
  }
  
}
