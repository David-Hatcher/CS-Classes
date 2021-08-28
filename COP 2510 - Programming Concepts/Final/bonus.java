import java.io.IOException;
import java.io.*;
import java.nio.file.*;
import java.util.ArrayList;
import java.util.Random;
/*This is a bonus/optional program. It shows 0 points in Canvas but will be graded for a possible of 
10 extra points only if you pass Program 1 or 2 with 70% or higher, i.e., 42 (or 60 x 70%) points. 

This program must be saved and submitted in one file called bonus.java.

To develop this program with one or multiple methods in one or multiple classes is up to your design decision. 
However, it should not include any package statements.

This program will first create a file directory 'C:\javabonus' in your computer, if it doesn't exist.

Then, it creates five text files in the above directory if they do not exist, including f1.txt, f2.txt, f3.txt, 
f4.txt, and f5.txt. If they already exist, it overwrites their contents.

Lastly, this program generates 10 random integers between -5 and 5 in each of the five text files, 
one per line, with no files containing same set of 10 integers. When a file is done, it also displays the 
following message to confirm.

File  C:/javabonus/fx.txt is processed

where fx is the filename like f1, f2, ..., f5.

Exceptions regarding file I/O must be handled by displaying "<ERROR> there is a file I/O problem" before 
showing the specific built-in error message. */
public class bonus {
    public static int randomGen(int min, int max) {
        Random r = new Random();
        return (r.nextInt((max - min) + 1) + min);
    }

    public static ArrayList<Integer> generateRandoms() {
        ArrayList<Integer> randomList = new ArrayList<Integer>();
        for (int i = 0; i < 10; i++) {
            int nextNum = randomGen(-5, 5);
            while (randomList.contains(nextNum)) {
                nextNum = randomGen(-5, 5);
            }
            randomList.add(nextNum);
        }
        return randomList;
    }

    public static void writeFile(String fileName) {        
        File baseDir = new File("C:/javabonus");
        if(!baseDir.exists()){
            new File("C:/javabonus").mkdirs();
        }
        File filePath= new File("C:/javabonus/" + fileName);
        try (PrintWriter output = new PrintWriter
                                 (new BufferedWriter
                                 (new FileWriter(filePath)))) {
        ArrayList<Integer> randoms = generateRandoms();
        for (int random : randoms) {
            output.println(random);
        }

        System.out.println("File  "+ filePath + " is processed.");
        } catch (IOException e) {
            System.out.println("<ERROR> there is a file I/O problem" + e.getMessage());
        }
    }

    public static void main(String[] args) {
        String[] names = {"f1.txt","f2.txt","f3.txt","f4.txt","f5.txt"};
        for (String name : names) {
            writeFile(name);
        }
    }
}