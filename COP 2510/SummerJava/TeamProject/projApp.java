package COP2510.project.UI;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

import COP2510.project.business.iGuess;

public class projApp{
    private static Scanner read = new Scanner(System.in);

    private static ArrayList<String> choicesSet = new ArrayList<String>(
        Arrays.asList("v", "w", "x", "y", "z", "5", "6", "7", "8", "9", "=", "?", "%", "@", "$"));
    private static String winString = "5A0B";

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
    private static void runPlayerCode(){
        iGuess.createLists();        
        println("You will make a code and the computer will guess it");
        println("Please write down your 5 digit code with one @ symbol and four\n" +
                "other unique characters fom the following list:\n" +choicesSet);
        String score = "";
        int guessCount = 0;
        while(!score.equalsIgnoreCase(winString)){
            score = runPlayerCodeLoop(++guessCount);
        }
        println("I figured it out in only " + guessCount + " guesses!");
    }
    private static String runPlayerCodeLoop(int guessCount){
        String score = "";
        ArrayList<String> currentGuess = iGuess.generateRandomGuess();
        print("Guess #" + guessCount + "\t" + iGuess.convertArrayListToString(currentGuess) +"\tEnter Score:");
        score = readString("");
        if(!score.equalsIgnoreCase(winString)){
            iGuess.pruneList(currentGuess, score);
        }
        return score;
    }
    public static void main(String[] args) {
        runPlayerCode();
    }
}