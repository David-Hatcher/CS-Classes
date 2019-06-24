package COP2510.project.UI;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

import COP2510.project.business.iGuess;

public class projApp{
    private static String winString = "5A0B";
    private static Scanner read = new Scanner(System.in);
    private static ArrayList<String> choicesSet = new ArrayList<String>(
        Arrays.asList("v", "w", "x", "y", "z", "5", "6", "7", "8", "9", "=", "?", "%", "@", "$"));
    
    private static void print(String message){
        System.out.print(message);
    }
    private static void println(String message){
        System.out.println(message);
    }
    
    private static String readString(String message){
        print(message);
        return read.nextLine();
    }
    private static void printBar(){
        println("*************************************************");
    }

    private static String convertArrayListToString(ArrayList<String> code){
        String codeString = "";
        for (String character : code) {
          codeString += character.toLowerCase();
        }
        return codeString;
    }

    private static ArrayList<String> convertStringToArrayList(String code){
        ArrayList<String> codeArrayList = new ArrayList<String>();
        for(int i = 0; i < code.length(); i++){
            codeArrayList.add(Character.toString(code.charAt(i)).toLowerCase());
        }
        return codeArrayList;
    }

    private static void RunProgram(){
        String message = ("Welcome to bull and cows:\n" +
                          "To play please select from the following options.\n" +
                          "1. To have the computer create a secret code and you guess it.(Enter 1)\n" +
                          "2. To select a secret code yourself and the computer guesses it.(Enter 2)\n" +
                          "3. To have the computer select a secret code then guess another computers secret code.(Enter 3)");
        String choice = readString(message);
        selectOption(choice);
    }
    private static void selectOption(String choice){
        if(choice.equalsIgnoreCase("1")){
            runComputerCode();
        }
        else if(choice.equalsIgnoreCase("2")){
            runPlayerCode();
        }
        else if (choice.equalsIgnoreCase("3")){
            //runComputerCodeAndGuess();
        }
        else if (choice.equalsIgnoreCase("4")){
            runComputerAgainstItself();
        }
        else{
            println("Incorrect Input!!!!");
            RunProgram();
        }
    }

    private static void runComputerCode(){
        println("The Computer will randomly generate a code and you must guess it!");
        println("Please type for guess of 5 digits, one digit must be @, the other 4 must be any"+
                "\ncombination of the following, without repetion:\n"+
                choicesSet+ 
                "\n or type ***** to give up and have the secret code displayed.\n");        
        String playerGuessString = askForGuess();
        ArrayList<String> playerGuessArrayList = convertStringToArrayList(playerGuessString);
        ArrayList<String> secretCodeComputerArrayList = iGuess.generateSecretCode();
        // String secretCodeComputerString = convertArrayListToString(secretCodeComputerArrayList);
        String score = "";
        int guessCount = 0;
        while(!score.equalsIgnoreCase(winString)){
            if(doesPlayerGiveUp(playerGuessString)){
                print("Good try!\nThe Secret Code is: " + iGuess.getSecretCode());
                break;
            }
            else if(!ensureGuessCorrect(playerGuessString, playerGuessArrayList)){
                println("ERROR, please ensure correct formatting per instructions.");
            }
            else{
                score = iGuess.compareScores(playerGuessArrayList, secretCodeComputerArrayList);
                println("Guess = " + playerGuessString + "\nScore = " + score + "\nGuess Count = " + ++guessCount);
            }
            if(!score.equalsIgnoreCase(winString)){
                playerGuessString = askForGuess();
                playerGuessArrayList = convertStringToArrayList(playerGuessString);
            }
        }
        didPlayerGuessCorrectly(score);
    }


    private static void didPlayerGuessCorrectly(String score){
        if(score.equalsIgnoreCase(winString)){
            println("Great job, you win!");
        }
    }
    private static String askForGuess(){
        printBar();
        String guess = readString("Please enter your next guess.");
        return guess; 
    }
    private static boolean ensureGuessCorrect(String guess, ArrayList<String> guessArrayList){
        for(int i = 0; i < guess.length(); i++){
            if(guess.equalsIgnoreCase("*****")){
                return true;
            }
            else if(guess.length() != 5){
                return false;
            }
            else if(doesStringContainOnlyChoices(guessArrayList)){
                return false;
            }
            else if(areCharactersUnique(guessArrayList)){
                return false;
            }
            else if(isGuessMissingAt(guessArrayList)){
                return false;
            }
        }
        return true;
    }
    private static boolean doesStringContainOnlyChoices(ArrayList<String> guess){
        for (String character : guess) {
            if(!choicesSet.contains(guess)){
                return false;
            }
        }
        return true;
    }
    private static boolean areCharactersUnique(ArrayList<String> guess){
        boolean condition = false;
        for(int i = 0; i < guess.size(); i++){
            for(int j = 0; j < guess.size(); j++){
                if(guess.get(i).equalsIgnoreCase(guess.get(j)) && i != j){
                    condition = true;
                }
            }
        }
        return condition;
    }
    private static boolean isGuessMissingAt(ArrayList<String> guessArrayList){
        if(!guessArrayList.contains("@")){
            return true;
        }
        return false;
    }
    private static boolean doesPlayerGiveUp(String guess){
        if(guess.equalsIgnoreCase("*****")){
            return true;
        }
        return false;
    }

    private static void runPlayerCode(){
        iGuess.createLists();        
        println("You will make a code and the computer will guess it");
        println("Please write down your 5 digit code with one @ symbol and four\n" +
                "other unique characters fom the following list:\n" +choicesSet);
        String score = "";
        int guessCount = 0;
        while(!score.equalsIgnoreCase(winString)){
            ArrayList<String> currentGuess = iGuess.generateRandomGuess();
            print("Guess #" + ++guessCount + "\t" + convertArrayListToString(currentGuess) +"\tEnter Score:");
            score = readString("");
            if(!score.equalsIgnoreCase(winString)){
                iGuess.pruneList(currentGuess, score);
            }            
        }
    }
    // private static void runComputerCodeAndGuess(){
    //     iGuess.createLists();
    //     println("The computer will make a code and find a computer opponents code.");
    //     ArrayList<String> computerSecretCode = iGuess.generateSecretCode();
    //     String myScore = "";
    //     String yourScore = "";
    //     int myGuessCount = 0;
    //     int yourGuessCount = 0;
    //     while(!myScore.equalsIgnoreCase(winString) && !yourScore.equalsIgnoreCase(winString)){
    //         if(!myScore.equalsIgnoreCase(winString)){

    //         }
    //         if(!yourScore.equalsIgnoreCase(winString)){

    //         }
    //     }
    //}
    private static void runComputerAgainstItself(){
        iGuess.createLists();
        ArrayList<String> computerSecretCode = iGuess.generateSecretCode();
        println("The Computer will make a code and find a computer opponents code.");
        String score = "";
        int guessCount = 0;
        while(!score.equalsIgnoreCase(winString)){
            ArrayList<String> currentGuess = iGuess.generateRandomGuess();
            score = iGuess.compareScores(currentGuess, computerSecretCode);
            println("Guess #" + ++guessCount + "\t" + convertArrayListToString(currentGuess) +"\tEnter Score:" + score);
            if(!score.equalsIgnoreCase(winString)){
                iGuess.pruneList(currentGuess, score);
            }
        }
    }

    public static void main(String[] args) {
        for(int i = 0;i < 5; i++){
            RunProgram();
        }
        // ArrayList<String> guess = convertStringToArrayList(askForGuess());
        // ArrayList<String> secretCodeNew = new ArrayList<String>(Arrays.asList("v"))
        // println(iGuess.compareScores(, combination))
    }
}