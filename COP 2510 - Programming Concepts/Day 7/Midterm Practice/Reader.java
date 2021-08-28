package midterm.classes;

import java.util.Scanner;


public class Reader{
    private Scanner reader = new Scanner(System.in);
    private Printer po = new Printer();

    public String ReadString(String message){
        po.Print(message);
        return reader.nextLine();
    }

}