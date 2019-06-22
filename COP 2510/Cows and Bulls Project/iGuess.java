import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;


public class iGuess {
  static ArrayList<ArrayList<String>> listOfCombinations = new ArrayList<ArrayList<String>>();
  static Random rand = new Random();

  public static int RandGen(int minimum, int max) {
    return rand.nextInt(max - minimum + 1) + minimum;
  }

  public static String compareScores(ArrayList<String> guess, ArrayList<String> combination){
    int bulls = 0;
    int cows = 0;
    for(int i = 0; i < guess.size(); i++){
      for(int j = 0; j < combination.size(); j++){
        if(guess.get(i).equalsIgnoreCase(combination.get(j)) && i == j){
          bulls++;       
        }
        else if(guess.get(i).equalsIgnoreCase(combination.get(j))){
          cows++;
        }
      }
    }
    return bulls + "A" + cows + "B";
  }
  
  public static void pruneList(ArrayList<String> guess, String score){
    for (ArrayList<String> combination : listOfCombinations) {
      if(!score.equalsIgnoreCase(compareScores(guess,combination))){
        listOfCombinations.remove(combination);
      }
    }
  }

  public static String[] ArrayBuilder() {
    ArrayList<String> possibles = new ArrayList<String>(
        Arrays.asList("v", "w", "x", "y", "z", "5", "6", "7", "8", "9", "=", "?", "%", "$"));
    String[] combination = new String[5];
    int randForAt = RandGen(0, 4);
    for (int i = 0; i < 5; i++) {
      if (i == randForAt) {
        combination[i] = "@";
      } else {
        String tempChar = possibles.get(RandGen(0, possibles.size() - 1));
        combination[i] = tempChar;
        possibles.remove(tempChar);
      }
    }
    return combination;
  }

  public static ArrayList<ArrayList<String>> FullPossibles() {
    ArrayList<ArrayList<String>> allCombos = new ArrayList<ArrayList<String>>();
    while (allCombos.size() < 120121) {
      String[] currentPossible = ArrayBuilder();
      while (allCombos.contains(Arrays.asList(currentPossible))) {
        currentPossible = ArrayBuilder();
      }
      ArrayList<String> currentToAdd = new ArrayList<String>();
      for (String str : currentPossible) {
        currentToAdd.add(str);
      }
      allCombos.add(currentToAdd);
<<<<<<< HEAD
=======
      System.out.println(allCombos.size());
>>>>>>> master
    }
    return allCombos;
  }
  public static void writeFile(ArrayList<ArrayList<String>> allCombos ,String filePath) throws IOException {
    PrintWriter out = new PrintWriter(
                      new BufferedWriter(
                      new FileWriter(filePath,true)));
      for (ArrayList<String> combo : allCombos) {
        int i = 0;
        for (String character : combo) {        
        if(i == 4){
          out.println(character);
        }
        else{
          out.print(character + ",");
        }
        i++;
      }      
    }
    out.close();
  }
  public static void  readFile(String filePath) throws IOException {
    BufferedReader in = new BufferedReader(
                        new FileReader(filePath));
    ArrayList<ArrayList<String>> readCombos = new ArrayList<ArrayList<String>>(10);
    String line;
    while((line = in.readLine()) != null){      
      String[] lineArray = line.split(",");
      ArrayList<String> currentCombo = new ArrayList<String>();
      for (String str : lineArray) {
        currentCombo.add(str);
      }
      readCombos.add(currentCombo);      
    }
    in.close();
    listOfCombinations = readCombos;    
  }

  public static void main(String[] args){
    ArrayList<ArrayList<String>> allCombos = FullPossibles();
    String filePath = "Possibles.txt";
  }
  
}
