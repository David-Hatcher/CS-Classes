package midterm.classes;

public class AllTogether{

    private static Reader ro = new Reader();
    private static Printer po = new Printer();
    private static boolean quit = false;

    private static void RunP1(){
        P1.RunNameReader();
    }

    private static void P1Description(){
        po.PrintLn("\n******    P1    ******\nA program that tells you which first names match.\n");
    }    
    /*******************************************/
    private static void RunP2(){
        P2.RunNameReader();
    }
    private static void P2Description(){
        po.PrintLn("******    P2    ******\nA program that tells you which last names match.\n");
    }
    /*******************************************/
    private static void RunP3(){
        P3.RunRandomNumberMaker();
    }
    private static void P3Description(){
        po.PrintLn("******    P3    ******\nA program that generates 20 random numbers between different ranges\nand finds which are divisible by 3.\n");
    }
    /*******************************************/
    private static void RunP4(){
        String[] args = P4_5Array();
        P4.RunWordSorter(args);
    }
    public static String[] P4_5Array(){
        String[] args = new String[5];
        for(int i = 0; i < 5; i++){
            if(i == 4){
                args[i] = ro.ReadString("Enter a sorting type(AZ = ascending, ZA = descending).\n");
            }
            else{
            args[i] = ro.ReadString("Enter a value.\n");
            }
        }
        return args;
    }
    private static void P4Description(){
        po.PrintLn("******    P4    ******\nA program that sorts four words by length.\nThis requires 4 word inputs and one sorting type input.\nAZ for ascending, ZA for descending.\n");
    }
    /*******************************************/
    private static void RunP5(){
        String[] args = P4_5Array();
        P5.RunWordSorter(args);
    }
    private static void P5Description(){
        po.PrintLn("******    P5    ******\nA program that sorts four numeric inputs by size.\nThis requires 4 numeric imputs and one sorting type input.\nAZ for ascending, ZA for descending.\n");
    }
    /*******************************************/
    private static void RunP6(){
        P6.RunGuessingProgram();
    }    
    private static void P6Description(){
        po.PrintLn("******    P6    ******\nA program that lets you guess at a random number between 1 and 100.\n");
    }
    /*******************************************/
    public static void PrintDescriptions(){
        P1Description();
        P2Description();
        P3Description();
        P4Description();
        P5Description();
        P6Description();
    }
    public static String AskForChoice(){
        return ro.ReadString("Please type your choice(P1,P2,P3,P4,P5,P6, \"desc\" for a list of descriptions, or \"quit\" to quit).\n");
    }
    public static void ChooseYourFate(){
        PrintDescriptions();
        String choice = AskForChoice();
        switch(choice.toLowerCase()){
            case "p1":{RunP1(); break;  }
            case "p2":{RunP2(); break;  }
            case "p3":{RunP3(); break;  }
            case "p4":{RunP4(); break;  }
            case "p5":{RunP5(); break;  }
            case "p6":{RunP6(); break;  }
            case "des":{PrintDescriptions(); break; }
            case "quit":{quit = true; break;}
            default:{break;}
        }
        String wait = ro.ReadString("Press any key to continue...");
    }
    public static void GreetUser(){
        po.PrintLn("**********************************************");
        po.PrintLn("\n   Welcome to Midterm Practice Program\n");
        po.PrintLn("**********************************************");

    }
    public static void RunAllTogether(){
        GreetUser();
        while(!quit){
            ChooseYourFate();
        }
    }
    public static void main(String[] args) {
        RunAllTogether();
    }
}