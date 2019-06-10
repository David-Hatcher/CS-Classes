package midterm.classes;


import java.util.Scanner;

public class P1{
  static private Scanner userInput = new Scanner(System.in);

  public static String AskName(){
    System.out.print("Please enter a name:");
    return userInput.nextLine();
  }

  public static void FindMatchingNames(String name_1, String name_2, String name_3){
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
  public static boolean DoesNameMatch(String name_1, String name_2){
    boolean nameMatches = true;
    int i = 0;    
    while(nameMatches == true && i < name_1.length() && i < name_2.length() && !name_1.substring(i,i+1).equalsIgnoreCase(" ")){
      if(!name_1.substring(i,i+1).equalsIgnoreCase(name_2.substring(i,i+1))){
        nameMatches = false;
      }      
      i++;
    }    
    return nameMatches;    
  }
  public static boolean DoesStringMatch(String subString_1, String subString_2){
    return subString_1.equalsIgnoreCase(subString_2);
  }
  
  public static void RunNameReader(){
    String name_1, name_2, name_3;
    name_1 = AskName();
    name_2 = AskName();
    name_3 = AskName();
    FindMatchingNames(name_1.trim(), name_2.trim(), name_3.trim());
  }
  public static void main(String[] args) {
    RunNameReader();
  }
}