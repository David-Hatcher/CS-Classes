import java.util.ArrayList;
import java.util.Arrays;

public class Recursive{
    public static ArrayList<ArrayList<String>> combos = new ArrayList<ArrayList<String>>();
    public static void addAtsTolist(ArrayList<String> combo){
        for(int i = 0; i < combo.size()+1; i++){
            ArrayList<String> comboCurrent = new ArrayList<String>(combo);
            comboCurrent.add(i,"@");
            if(!combos.contains(comboCurrent)){
                System.out.println(comboCurrent);
                combos.add(comboCurrent);                
            }
        }
    }
    public static void createLists(String[] set, int length){
        for(int i = 0; i < set.length; i++){
            ArrayList<String> setStrings = new ArrayList<String>(Arrays.asList(set));
            ArrayList<String> combo = new ArrayList<String>();
            combo.add(setStrings.remove(i));
            createListsRec(setStrings,combo,length);
        }
    }
    public static void createListsRec(ArrayList<String> set, ArrayList<String> combo,int length){
        ArrayList<String> currentSet = new ArrayList<String>(set);
        for(int i = 0; i < currentSet.size();i++){
            ArrayList<String> currentCombo = new ArrayList<String>(combo);
            if(combo.size() == length-1){                
                //System.out.println(combo);
                addAtsTolist(combo);
                break;
            }
            else if(!currentCombo.contains(currentSet.get(i))){                
                currentCombo.add(currentSet.get(i));                
                createListsRec(currentSet,currentCombo,length);
            }
        }
    }
    public static void main(String[] args) {
        long start = System.nanoTime();
        String[] letters = {"v", "w", "x", "y", "z", "5", "6", "7", "8", "9", "=", "?", "%", "$"};
        createLists(letters,5);
        //System.out.println(combos.size());
        long end = System.nanoTime();
        double runTime = (double) (end-start)/(1000000000.0);
        System.out.println("Total run time " + runTime + " seconds.");
    }
}