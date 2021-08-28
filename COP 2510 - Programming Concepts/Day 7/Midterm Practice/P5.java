package midterm.classes;

import midterm.classes.AllTogether;

public class P5{
    static private Printer po = new Printer();  
  
    private static String[] WhichWordComesFirst(String[] words){
        
       try {
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 3; j++){
                if(Double.parseDouble(words[j]) > Double.parseDouble(words[j+1])){          
                String tempHolder = words[j];
                words[j] = words[j+1];
                words[j+1] = tempHolder;
                }
            }
        }
        
        } catch (Exception e) {
        po.PrintLn("Please input numeric values for first 4 inputs and za or az for last.");      
        words[0] = "0";words[1] = "0";words[2] = "0";words[3] = "0";words[4] ="za";
        }
        return words;
    }

    
  
    private static void PrintWordsInOrderAZ(String[] words){
      for(int i = 0; i < 4; i++){
        po.PrintLn(words[i]);
      }
      PrintValues(words);
    }

    private static void PrintWordsInOrderZA(String[] words){
        for(int i = 0; i < 4; i++){
          po.PrintLn(words[3-i]);
        }
        PrintValues(words);
      }

    private static void PrintValues(String[] words){
        String Max = words[3];
        String Min = words[0];
        double Sum = FindSum(words);
        double Avg = Sum/4;
        po.Print("Max =\t" + Max + "\n" +
                 "Min =\t" + Min + "\n" + 
                 "Sum =\t" + Sum + "\n" +
                 "Avg =\t" + Avg + "\n" );
    }

    private static double FindSum(String[] words){
        double Sum = 0;
        for(int i = 0; i < 4;i++){
            Sum += Double.parseDouble(words[i]);
        }
        return Sum;
    }
  
    public static void RunWordSorter(String[] words){
      if(words[4].equalsIgnoreCase("az")){
        PrintWordsInOrderAZ(WhichWordComesFirst(words));
      }
      else if(words[4].equalsIgnoreCase("za")){
        PrintWordsInOrderZA(WhichWordComesFirst(words));
      }
      else{
        po.Print("Wrong sorting order(AZ or ZA)");
      }
    }
  
    public static void main(String[] args) {
      RunWordSorter(args);
    }
  }