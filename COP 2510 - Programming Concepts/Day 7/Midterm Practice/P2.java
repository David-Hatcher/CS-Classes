package midterm.classes;


import java.util.Scanner;



public class P2{
  static private Scanner userInput = new Scanner(System.in);
  static private Printer po = new Printer();

  public static String AskName(){
    po.Print("Please enter a name:");    
    return userInput.nextLine();
  }

  private static void FindMatchingNames(String name_1, String name_2, String name_3){
    boolean matchingNames1_2 = DoesNameMatch(name_1, name_2);
    boolean matchingNames2_3 = DoesNameMatch(name_2, name_3);
    boolean matchingNames3_1 = DoesNameMatch(name_3, name_1);
    po.PrintLn("Matching last names are:");
    if(matchingNames1_2 == true && matchingNames2_3 == true){
      po.Print(name_1 + "\n" + name_2 + "\n" + name_3);
    }
    else if(matchingNames1_2 == true){
      po.Print(name_1 + "\n" + name_2);
    }
    else if(matchingNames3_1 == true){
      po.Print(name_1 + "\n" + name_3);
    }
    else{
      po.Print("No matching last names...");
    }

  }
  private static boolean DoesNameMatch(String name_1, String name_2){
    boolean nameMatches = true;
    int i = 1;    
    int length_1 = name_1.length(), length_2 = name_2.length();

    while(nameMatches == true && i < length_1 && i < length_2 && !name_1.substring(length_1 - (i+1),length_1-i).equalsIgnoreCase(" ")){
      if(!name_1.substring(length_1 - (i+1),length_1-i).equalsIgnoreCase(name_2.substring(length_2 - (i+1),length_2-i))){
      nameMatches = false;
      }
      i++;
    }
    return nameMatches;    
  }
  private static boolean DoesStringMatch(String subString_1, String subString_2){
    return subString_1.equalsIgnoreCase(subString_2);
  }
  public static void RunNameReader(){
    String name_1 = AskName();
    String name_2 = AskName();
    String name_3 = AskName();
    FindMatchingNames(name_1.trim(), name_2.trim(), name_3.trim());
  }
  public static void main(String[] args) {
    RunNameReader();
  }
}