import java.util.Scanner;

public class P2{

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
    System.out.println("Matching last names are:");
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
      System.out.print("No matching last names...");
    }

  }
  private static boolean DoesNameMatch(String name_1, String name_2){
    boolean nameMatches = true;
    int i = 1;    
    int length_1 = name_1.length(), length_2 = name_2.length();

    while(nameMatches == true && i < length_1 && i < length_2 && 
    !name_1.substring(length_1 - (i+1),length_1-i).equalsIgnoreCase(" ") && 
    !name_2.substring(length_2 - (i+1),length_2-i).equalsIgnoreCase(" ")){
      nameMatches = DoesStringMatch(name_1.substring(length_1 - i, length_1), name_2.substring(length_2 - i, length_2));
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