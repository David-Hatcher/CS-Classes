/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package summer.COP2510;
import java.util.Scanner;
/**
 *
 * @author David
 */
public class Ass2 {
    public static double ConvertTemp(double TempInF){        
        double TempInC = (TempInF-32)*(5.0/9.0);        
        return TempInC;
    }
    public static double AskUserForTemperature(){
        System.out.print("Enter Degrees in Fahrenheit: ");
        Scanner sc = new Scanner(System.in);
        double TempInF = Double.parseDouble(sc.nextLine());
        return TempInF;
    }
    public static String DoesUserContinue(){
        System.out.print("Continue? (y/n):");
        Scanner sc = new Scanner(System.in);
        String response = sc.nextLine();
        return response;
    }
    public static void GreetUser(){
        System.out.println("**************************************************************");
        System.out.println("*Hello and welcome to the Temperature Conversion Application!*");
        System.out.println("**************************************************************");

    }
    public static void main(String[] args){
        GreetUser();
        String Continue = "y";
        while(Continue.equalsIgnoreCase("y")){
            double TempInF = AskUserForTemperature();
            System.out.println("Degrees in Celsius: " + ConvertTemp(TempInF) + "\n\n");
            Continue = DoesUserContinue();
        }
        System.out.println("Bye!");
    }
}