import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

public class ArrayBuilder {
public static int RandGen(int min, int max){
  Random rand = new Random();
  return (rand.nextInt(max-min)+min+1);
}

public static String[] ArrayBuilderNOTINUSE() {
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
    while (allCombos.size() < 120120) {
      String[] currentPossible = ArrayBuilderNOTINUSE();
      while (allCombos.contains(Arrays.asList(currentPossible))) {
        currentPossible = ArrayBuilderNOTINUSE();
      }
      ArrayList<String> currentToAdd = new ArrayList<String>();
      for (String str : currentPossible) {
        currentToAdd.add(str);
      }
      allCombos.add(currentToAdd);
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
    return readCombos;    
  }
}