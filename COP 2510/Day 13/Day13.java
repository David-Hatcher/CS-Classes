import java.io.IOException;
import java.nio.file.*;
import java.nio.file.Paths;

public class Day13 {
    // File I/O allows you to read data from a file
    // files can be stored in binary files as well, in a base two.

    public static void main(String[] args) {
        // try_catch make sure you think about the order of your catch blocks, you can
        // have multiple
        // catch blocks for different types of errors

        try {
            // some code
            // throw new stuffexception("") this is for if you have something that isnt good
            // but not technically an exeception
        } catch (IndexOutOfBoundsException e) {
            // some other code to signify the out of bounds error
        } catch (NumberFormatException e) {
            // more code to signify the numberformat exception
        } catch (Exception e) {
            // fall through code basically if it's not covered by the last two
        }

        // File I/O//
        String dirString = "c:/users/salla/desktop/cs-classes/COP 2510/Day 13";
        String fileName = "Day 13";
        Path dirPath = Paths.get(dirString);//Create Path object
        Path filePath = Paths.get(dirString,fileName);
        if (Files.notExists(dirPath)) {//This will create the directory if it does not exist already
            try {
                Files.createDirectories(dirPath);
            } catch (IOException e) {                
                e.printStackTrace();
            }
        }
        if (Files.notExists(filePath)){//This will create the file if it does not exist
            try {
                Files.createDirectories(filePath);
            } catch (IOException e) {                
                e.printStackTrace();
            }
        }        

    }
}