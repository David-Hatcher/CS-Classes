import java.util.*;
import java.io.*;

public class iGuess {
  static Random rand = new Random();

  public static int RandGen(int minimum, int max) {
    return rand.nextInt(max - minimum + 1) + minimum;
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
    while (allCombos.size() < 10) {
      String[] currentPossible = ArrayBuilder();
      while (allCombos.contains(Arrays.asList(currentPossible))) {
        currentPossible = ArrayBuilder();
      }
      ArrayList<String> currentToAdd = new ArrayList<String>();
      for (String str : currentPossible) {
        currentToAdd.add(str);
      }
      allCombos.add(currentToAdd);
      //System.out.println(allCombos.size());
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
  public static ArrayList<ArrayList<String>> readFile(String filePath) throws IOException {
    BufferedReader in = new BufferedReader(
                        new FileReader("Possibles.txt"));
    ArrayList<ArrayList<String>> readCombos = new ArrayList<ArrayList<String>>(10);
    String line;
    while((line = in.readLine()) != null){      
      String[] lineArray = line.split(",");
      ArrayList<String> currentCombo = new ArrayList<String>();
      for (String str : lineArray) {
        currentCombo.add(str);
      }
      readCombos.add(currentCombo);
      System.out.println(readCombos.size());
    }
    return readCombos;
  }

  public static void main(String[] args){
    ArrayList<ArrayList<String>> allCombos = FullPossibles();
    String filePath = "Possibles.txt";
    ArrayList<ArrayList<String>> readCombos = new ArrayList<ArrayList<String>>();
    try {
      writeFile(allCombos, filePath);
      readCombos = readFile(filePath);
    } catch (Exception e) {
      System.out.println("ERROR");
    }    
    System.out.println(readCombos);
    System.out.println(readCombos.size());
  }
  
}
