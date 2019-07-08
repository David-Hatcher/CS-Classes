import java.util.*;
import java.io.*;
import java.nio.file.*;

public class Testing{
    public static void main(String[] args) {
        Path thisPath = Paths.get("");
        String s = thisPath.toAbsolutePath().toString();
        System.out.println("Path is: " + s);

        Scanner sc = new Scanner(System.in);

        String input = sc.nextLine();
        String[] s2 = input.split(" ");
        System.out.println("Words in args = " + s2.length);
    }
}