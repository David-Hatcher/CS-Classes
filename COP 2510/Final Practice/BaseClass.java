import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

class LengthException extends Exception{
    public LengthException(String message){
        super(message);
    }
}
abstract class ProcessData{
    public int addAll(int[] data){
        int total = 0;
        for (int number : data) {
            total +=number;
        }
        return total;
    }
    public double findAvg(int[] data){
        return (double)(addAll(data)/data.length);
    }
    public int[] sortLowToHigh(int[] data){
        Arrays.sort(data);
        return data;
    }
    public int[] reverseArray(int[] data){
        int[] dataReversed = new int[data.length];
        for(int i = 0; i < data.length; i++){
            dataReversed[i] = data[data.length-(i+1)];
        }
        return dataReversed;
    }
    public int[] sortHighToLow(int[] data){
        int[] dataSorted = sortLowToHigh(data);
        return reverseArray(dataSorted);
    }
    public int findHighest(int[] data){
        int max = data[0];
        for (int number : data) {
            max = number > max ? number : max;
        }
        return max;
    }
    public int findLowest(int[] data){
        int min = data[0];
        for (int number : data) {
            min = number < min ? number : min;
        }
        return min;
    }
}
class ProcessDataChild extends ProcessData{
    public int[] convertArray(String[] data)throws IOException, LengthException{
        int[] converted = new int[data.length];
        try {
            if(!isArrayLengthThree(data)){throw new LengthException("<ERROR> Insufficient input data. Please re-run the program.");}
            for(int i = 0; i < data.length; i++) {
                converted[i] = Integer.parseInt(data[i]);
            }
        } catch (IndexOutOfBoundsException e) {
            throw new IOException("<ERROR> Incorrect type of one or more input data. Please re-run the program.");
        }
        return converted;
    }
    public boolean isArrayLengthThree(String[] data){
        if(data.length != 5){
            return false;
        }
        return true;
    }
    public String[] convertArrayListToStrings(ArrayList<String> data){
        String[] dataString = new String[data.size()];
        for(int i = 0; i < data.size(); i++){
            dataString[i] = data.get(i);
        }
        return dataString;
    }
    public ArrayList<Integer> convertToArrayList(int[] data){
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int number : data) {
            list.add(number);
        }
        return list;
    }
    public int findLowest(String[] data)throws IOException, LengthException{
        int[] dataInts = convertArray(data);
        return super.findLowest(dataInts);
    }
    public int findLowest(ArrayList<String> data)throws IOException, LengthException{
        String[] dataStrings = convertArrayListToStrings(data);
        return findLowest(dataStrings);
    }
    public int findHighest(String[] data)throws IOException, LengthException{
        int[] dataInts = convertArray(data);
        return super.findHighest(dataInts);
    }
    public int findHighest(ArrayList<String> data)throws IOException, LengthException{
        String[] dataStrings = convertArrayListToStrings(data);
        return findHighest(dataStrings);
    }
    public int addAll(String[] data)throws IOException, LengthException{
        int[] dataInts = convertArray(data);
        return super.addAll(dataInts);
    }
    public int addAll(ArrayList<String> data)throws IOException, LengthException{
        String[] dataString = convertArrayListToStrings(data);
        return addAll(dataString);
    }
    public int[] sortLowToHigh(String[] data)throws IOException, LengthException{
        int[] dataInts = convertArray(data);
        return super.sortLowToHigh(dataInts);
    }
    public ArrayList<Integer> sortLowToHigh(ArrayList<String> data)throws IOException, LengthException{
        return convertToArrayList(sortLowToHigh(convertArrayListToStrings(data)));
    }
    public int[] sortHighToLow(String[] data)throws IOException, LengthException{
        int[] dataLowToHigh = convertArray(data);
        return super.sortHighToLow(dataLowToHigh);
    }
    public ArrayList<Integer> sortHighToLow(ArrayList<String> data)throws IOException, LengthException{
        return convertToArrayList(sortHighToLow(convertArrayListToStrings(data)));
    }
    public double findAvg(String[] data)throws IOException, LengthException{
        int total = addAll(data);
        return (double)(total/data.length);
    }
    public double findAvg(ArrayList<String> data)throws IOException, LengthException{
        int total = addAll(data);
        return (double)(total/data.size());
    }

} 
public class BaseClass { // This one will have all the methods in the main method.
    public static void println(Object message){System.out.println(message);}
    public static String convertToString(int[] data){
        String value = "";
        for (int number : data) {
            value += number + " ";
        }
        return value;
    }
    public static String convertToString(String[] data){
        String value = "";
        for (String number : data) {
            value += number + " ";
        }
        return value;
    }
    
    public static void RunProgram(String[] data){
        try {
            ProcessDataChild pd = new ProcessDataChild();
            ArrayList<String> dataArrayList = new ArrayList<String>(Arrays.asList(data));
            String highestFromArray = "Highest from Array = " + pd.findHighest(data);
            String highestFromArrayList = "Highest from ArrayList = " + pd.findHighest(dataArrayList);
            String lowestFromArray = "Lowest from Array = " + pd.findLowest(data);
            String lowestFromArrayList = "Lowest from ArrayList = " + pd.findLowest(dataArrayList);
            String sortedLowtoHighArray = "Sorted Low to High Array = " + convertToString(pd.sortLowToHigh(data));
            String sortedLowToHighArrayList = "Sorted Low to High ArrayList = " + pd.sortLowToHigh(dataArrayList);
            String sortedHighToLowArray = "Sorted High to Low Array = " + convertToString(pd.sortHighToLow(data));
            String sortedHighToLowArrayList = "Sorted High To Low ArrayList = " + pd.sortHighToLow(dataArrayList);
            String averageArray = "Average from Array = " + pd.findAvg(data);
            String averageArrayList = "Average from ArrayList = " + pd.findAvg(dataArrayList);
            println(convertToString(data));
            println(highestFromArray + "\n" +
                    highestFromArrayList + "\n" +
                    lowestFromArray + "\n" +
                    lowestFromArrayList + "\n" +
                    sortedLowtoHighArray + "\n" +
                    sortedLowToHighArrayList + "\n" +
                    sortedHighToLowArray + "\n" +
                    sortedHighToLowArrayList + "\n" +
                    averageArray + "\n" + 
                    averageArrayList + "\n");
        } catch (Exception e) {
            println(e.getMessage());
        }
    }
    public static void main(String args[]) {        
        RunProgram(args);
    }
}
