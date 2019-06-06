import java.util.Scanner;

public class P1{

  private static String AskName(){
    Scanner userInput = new Scanner(System.in);
    System.out.print("Please ender a name:");
    String name = userInput.nextLine();
    return name;
  }

  private static void FindMatchingNames(String name_1, String name_2, String name_3){
    boolean matchingNames1_2 = DoesNameMatch(name_1, name_2);
    boolean matchingNames2_3 = DoesNameMatch(name_2, name_3);
    boolean matchingNames3_1 = DoesNameMatch(name_3, name_1);
    System.out.println("Matching first names are:");
    if(matchingNames1_2 == true && matchingNames2_3 == true){
      System.out.print(name_1 + "\n" + name_2 + "\n" + name_3);
    }
    else if(matchingNames1_2 == true){
      System.out.print(name_1 + "\n" + name_2);
    }
    else if(matchingNames3_1 == true){
      System.out.print(name_1 + "\n" + name_3);
    }
    else{
      System.out.print("No matching first names...");
    }

  }
  private static boolean DoesNameMatch(String name_1, String name_2){
    boolean nameMatches = true;
    int i = 0;    
    while(nameMatches == true && i < name_1.length() && i < name_2.length() && !name_1.substring(i,i+1).equalsIgnoreCase(" ")&& !name_2.substring(i,i+1).equalsIgnoreCase(" ")){
      nameMatches = DoesStringMatch(name_1.substring(0, i+1), name_2.substring(0, i+1));
      i++;
    }    
    return nameMatches;    
  }
  private static boolean DoesStringMatch(String subString_1, String subString_2){
    return subString_1.equalsIgnoreCase(subString_2);
  }
  public static void main(String[] args) {
    String name_1 = AskName();
    String name_2 = AskName();
    String name_3 = AskName();
    FindMatchingNames(name_1.trim(), name_2.trim(), name_3.trim());
  }
}