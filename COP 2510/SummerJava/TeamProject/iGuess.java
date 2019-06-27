package COP2510.project.business;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

public class iGuess {
    public static Random rand = new Random();
    public static ArrayList<ArrayList<String>> combos = new ArrayList<ArrayList<String>>();
    private static String[] possibles = {"v", "w", "x", "y", "z", "5", "6", "7", "8", "9", "=", "?", "%", "$"};
    public static String convertArrayListToString(ArrayList<String> code){
        String codeString = "";
        for (String character : code) {
          codeString += character.toLowerCase();
        }
        return codeString;
    }
    public static void createLists(){
        combos.clear();
        for (int i = 0; i < possibles.length; i++) {
            ArrayList<String> setStrings = new ArrayList<String>(Arrays.asList(possibles));
            ArrayList<String> combo = new ArrayList<String>();
            combo.add(setStrings.remove(i));
            createListsRec(setStrings, combo, 5);
        }
    }
    
    private static void createListsRec(ArrayList<String> set, ArrayList<String> combo, int length) {
        ArrayList<String> currentSet = new ArrayList<String>(set);
        for (int i = 0; i < currentSet.size(); i++) {
            ArrayList<String> currentCombo = new ArrayList<String>(combo);
            if (combo.size() == length - 1) {
                addAtsTolist(combo);
                break;
            } else if (!currentCombo.contains(currentSet.get(i))) {
                currentCombo.add(currentSet.get(i));
                createListsRec(currentSet, currentCombo, length);
            }
        }
    }
    
    private static void addAtsTolist(ArrayList<String> combo) {
        for (int i = 0; i < combo.size() + 1; i++) {
            ArrayList<String> comboCurrent = new ArrayList<String>(combo);
            comboCurrent.add(i, "@");
            combos.add(comboCurrent);            
        }
    }
    public static ArrayList<String> generateRandomGuess(){    
        return combos.get(rand.nextInt(combos.size()));
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
        ArrayList<ArrayList<String>> tempList = new ArrayList<ArrayList<String>>();
        for (ArrayList<String> combination : combos) {
          if(score.equalsIgnoreCase(compareScores(guess,combination))){
            tempList.add(combination);
          }
        }
        combos = tempList;
      }
}