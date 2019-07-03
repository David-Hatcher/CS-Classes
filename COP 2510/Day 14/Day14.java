public class Day14{
    public static void revArray(int[] data){
        for(int i = 0; i < (data.length/2) ; i++){
            int temp = data[i];
            data[i] = data[data.length-(i+1)];
            data[data.length-(i+1)] = temp;
        }
    }
    public static void printArray(int[] data){
        for (int num : data) {
            System.out.print(num);
        }
        System.out.println();
    }
    public static void rev3(int[] data){
        for(int i = 0; i < data.length-1; i++){
            for(int j = 0; j < data.length-1-i; j++){
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
        }
    }
    public static void main(String[] args) {
        int[] arr = {1,2,3,4};
        System.out.println("Before reverse.");
        printArray(arr);
        rev3(arr);
        System.out.println("After reverse.");
        printArray(arr);
    }
}