import java.util.Arrays;
import java.util.Random;
import java.util.ArrayList;
class Day18 {
    public static void main(String[] args) {
        int[] dataSource = { 2, 3, 6, 5, 2, 12, 22, 23 };
        ArrayFunct.sortArrayHighLowBubbleSort(dataSource);
        //ArrayFunct.unsort(dataSource);
        //ArrayFunct.sortArrayRobWay(dataSource);
    }
}

class ArrayFunct {
    public static void sortArrayHighLowBubbleSort(int[] data) {
        for (int i = 0; i < data.length; i++) {
            for (int j = i; j < data.length; j++) {
                if (data[i] < data[j]) {
                    int temp = data[j];
                    data[j] = data[i];
                    data[i] = temp;
                }
            }
            printArray(data);
        }
        printArray(data);
    }
    public static void reverseArray(int[] data){
        for(int i = 0; i < (int)(data.length/2); i++){
            int temp = data[data.length-(i+1)];
            data[data.length-(i+1)] = data[i];
            data[i] = temp;
        }
    }

    public static void printArray(int[] data) {
        for (int value : data) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

    public static void negativeArray(int[] data) {
        for(int i = 0; i < data.length; i++){
            data[i] *= (-1);
        }
    }

    public static void sortArrayRobWay(int data[]) {
        negativeArray(data);
        Arrays.sort(data);
        negativeArray(data);
        printArray(data);
    }
    public static int randomGen(int max){
        Random r = new Random();
        return r.nextInt(max);
    }

    public static void unsort(int data[]) {
        ArrayList<Integer> dataRandomNumbers = new ArrayList<Integer>();
        int[] temp = new int[data.length];
        for (int i = 0; i < data.length; i++) {
            int rand = randomGen(data.length);
            while(dataRandomNumbers.contains(rand)){
                rand = randomGen(data.length);
            }
            temp[i] = data[rand];
            dataRandomNumbers.add(rand);
        }
        for (int x = 0; x < data.length; x++) {
            data[x] = temp[x];
        }
        printArray(data);
    }
    public static void sortReverse(int[] data){
        Arrays.sort(data);
        reverseArray(data);
    }
}