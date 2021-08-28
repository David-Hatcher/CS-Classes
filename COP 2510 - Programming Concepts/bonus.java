import java.io.IOException;
import java.io.*;
import java.nio.file.*;
import java.util.ArrayList;
import java.util.Random;

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
    public static ArrayList<ArrayList<Integer>> generateUniqueLists(int count){
        ArrayList<ArrayList<Integer>> uniqueRandoms = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> currentRandoms;
        for(int i = 0; i < count; i++){
            currentRandoms = generateRandoms();
            while(uniqueRandoms.contains(currentRandoms)){
                currentRandoms = generateRandoms();                
            }
            uniqueRandoms.add(currentRandoms);
        }
        return uniqueRandoms;
    }

    public static void writeFiles(String[] fileNames) {        
        File baseDir = new File("C:/javabonus");
        if(!baseDir.exists()){
            new File("C:/javabonus").mkdirs();
        }
        ArrayList<ArrayList<Integer>> randomsLists = generateUniqueLists(fileNames.length);
        for (int i = 0; i < fileNames.length; i++) {
            File filePath= new File("C:/javabonus/" + fileNames[i]);
            try (PrintWriter output = new PrintWriter(
                                      new BufferedWriter(
                                      new FileWriter(filePath)))) {
                ArrayList<Integer> randoms = randomsLists.get(i);
                for (int random : randoms) {
                    output.println(random);
                }
                System.out.println("File  "+ filePath + " is processed.");
            } catch (IOException e) {
                System.out.println("<ERROR> there is a file I/O problem" + e.getMessage());
            }
        }
    }

    public static void main(String[] args) {
        
        String[] names = {"f1.txt","f2.txt","f3.txt","f4.txt","f5.txt"};
        writeFiles(names);
    }
}