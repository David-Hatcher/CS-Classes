import java.util.Scanner;

public class M3{
    private static Scanner read = new Scanner(System.in);
    private static int totalSightings = 0;
    private static String GreetUser(){
        System.out.println("Enter any number of comma-separated numbers, integer or floating-point:");
        return read.nextLine();
    }
    private static String AskUserSearch(){
        System.out.print("Enter the number to search: ");
        return read.nextLine();
    }
    private static void PrintIndex(String number, int index){
        System.out.println(number + " found at index " + index);
    }
    private static void FindSearchInput(String numbers, String searchValue,int StartValue){
        int totalLength = numbers.length();
        int searchLength = searchValue.length();
        String searchString1 = "," + searchValue + ",";
        String searchString2 = searchValue + ",";
        String searchString3 = "," + searchValue;
        int i=0;
        int lastComma = numbers.lastIndexOf(',');        
        int firstComma = numbers.indexOf(',',StartValue);
        String valueBeforeComma = numbers.substring(StartValue,firstComma+1);
        String valueAfterComma = numbers.substring(lastComma);
        if(valueBeforeComma.equals(searchString2)){
            PrintIndex(searchValue, 0+StartValue);
            totalSightings++;
        }
        if(valueAfterComma.equals(searchString3)){
            PrintIndex(searchValue, lastComma+1);
            totalSightings++;
        }

        try {
            numbers = numbers.substring(firstComma+1, lastComma);
            if (numbers.length() > searchValue.length()){
                FindSearchInput(numbers, searchValue, firstComma+1);
            }
        } catch (Exception e) {
            System.out.println("-----------------\n" + searchValue + " appears "+ totalSightings + " times");
        }
    }
    public static void main(String[] args) {
        String numbers = GreetUser();
        String searchValue = AskUserSearch();
        FindSearchInput(numbers, searchValue,0);

    }
}