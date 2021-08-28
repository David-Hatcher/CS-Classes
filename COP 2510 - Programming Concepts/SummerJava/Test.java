import java.util.*;

public class Test{
  public static ArrayList<ArrayList<Character>> permute(char[] possChars) {
    ArrayList<ArrayList<Character>> result = new ArrayList<ArrayList<Character>>();    
    result.add(new ArrayList<Character>());                                             
    for (int i = 0; i < possChars.length; i++) {
      ArrayList<ArrayList<Character>> current = new ArrayList<ArrayList<Character>>();
      for(int k = 0; k < 5; k++){                     
        for (ArrayList<Character> tempList : result) {                                    
          for (int j = 0; j < tempList.size()+1; j++) {                                   
            tempList.add(j, possChars[i]);                                                
            ArrayList<Character> temp = new ArrayList<Character>(tempList);           
            current.add(temp);                                                           
            tempList.remove(j);                                                           
          }
        }
      }
      result = new ArrayList<ArrayList<Character>>(current);                            
    }
    return result;
  }

  public static void main(String[] args) {
    char[] possCharss = { 'v', 'w' , 'x', 'y', 'z', '5', '6', '7', '8', '9', '=', '?', '%', '$', '@' };
    ArrayList<ArrayList<Character>> result = permute(possCharss);
    System.out.println(result);
  }
}