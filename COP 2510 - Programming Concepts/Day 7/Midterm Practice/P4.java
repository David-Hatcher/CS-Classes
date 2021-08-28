package midterm.classes;

public class P4 {
  static private Printer po = new Printer();  

  private static String[] WhichWordComesFirstAZ(String[] words){
    
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 3; j++){
        if(words[j].length() < words[j+1].length()){          
          String tempHolder = words[j];
          words[j] = words[j+1];
          words[j+1] = tempHolder;
        }
      }
    }
    return words;
  }

  private static String[] WhichWordComesFirstZA(String[] words){
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 3; j++){
        if(words[j].length() > words[j+1].length()){
        String tempHolder = words[j];
        words[j] = words[j+1];
        words[j+1] = tempHolder;
        }
      }
    }
    return words;
  }

  private static void PrintWordsInOrder(String[] words){
    for(int i = 0; i < 4; i++){
      po.PrintLn(words[i]);
    }
  }

  public static void RunWordSorter(String[] words){
    if(words[4].equalsIgnoreCase("az")){
      PrintWordsInOrder(WhichWordComesFirstAZ(words));
    }
    else if(words[4].equalsIgnoreCase("za")){
      PrintWordsInOrder(WhichWordComesFirstZA(words));
    }
    else{
      po.Print("Wrong sorting order(AZ or ZA)");
    }
  }

  public static void main(String[] args) {
    RunWordSorter(args);
  }
}