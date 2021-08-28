import java.util.ArrayList;


class Quiz7_2 {
	public static ArrayList<Integer> loadData(String[] data){
		ArrayList<Integer> numbers = new ArrayList<Integer>();
		for(int i = 0; i < data.length; i++){
			numbers.add(Integer.parseInt(data[i]));
		}
		return numbers;
	}
	public static int sumPositive(ArrayList<Integer> data){
		int total = 0;
		for (int number : data) {
			if(number > 0){
				total += number;
			}
		}
		return total;
	}
    public static void main(String args[]) {
		try {
			ArrayList<Integer> inputData = loadData(args); 
			int allPositive = sumPositive(inputData);
			System.out.println("\nSum of all positive input = " + allPositive);
		}
		catch (NumberFormatException e){
			System.out.println("ERROR: invalid data found in input");
		} 
		System.out.println("\nBye!");
		
	} // end of main
	
} // end of class
