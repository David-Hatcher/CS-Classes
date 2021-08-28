package midterm.classes;




public class P6{
    private static RandomGen rand = new RandomGen();
    private static Printer po = new Printer();
    private static Reader ro = new Reader();
    private static int randomNumber;
    private static String currentGuess = "";
    private static int guessCountCurrent = 0;
    private static int guessCountLowest = 1000000;

    private static void CreateRandomNumber(int minimum, int maximum){
        randomNumber = rand.randInt(minimum, maximum);
        po.PrintLn("Random number " + minimum + " to " + maximum + " generated!");
    }

    private static void ResetGuessCount(){
        guessCountCurrent = 0;
    }

    private static void AskGuess(){
        currentGuess = ro.ReadString("What is your current guess?\n");
        guessCountCurrent++;
    }

    private static void GuessCountLowest(){
        if(guessCountCurrent < guessCountLowest){
            guessCountLowest = guessCountCurrent;
        }
    }

    private static boolean DoesGuessMatch(){
        try {       
            if(currentGuess.equalsIgnoreCase("x")){
                return true;
            }
            else if(Integer.parseInt(currentGuess) < randomNumber){
                GuessTooLow();
            }
            else if(Integer.parseInt(currentGuess) > randomNumber){
                GuessTooHigh();
            }
            else{
                GuessMatched();
                return true;            
            }
        } catch (Exception e) {
            po.PrintLn("Please enter a number or X to quit.");
            return false;
        }
        return false;
    }

    private static void GuessMatched(){
        po.PrintLn("You got it!");
        GuessCountLowest();
        po.PrintLn("Guess count :\t" + guessCountCurrent);
    }

    private static void GuessTooLow(){
        po.PrintLn("Higher!");
    }

    private static void GuessTooHigh(){
        po.PrintLn("Lower!");
    }

    private static void RunGuessingCycle(){
        CreateRandomNumber(1, 100);
        AskGuess();
        while(!DoesGuessMatch()){
            AskGuess();
        }        
    }

    public static void RunGuessingProgram(){
        while(!currentGuess.equalsIgnoreCase("x")){
            RunGuessingCycle();
        }
        po.PrintLn("Minimum Guess:\t" + guessCountLowest);
    }
    
    public static void main(String[] args) {
        RunGuessingProgram();
    }
}