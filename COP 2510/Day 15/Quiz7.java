class Quiz7 {  
	public static int[] loadData(String[] data){
		int[] numbers = new int[data.length];
		for(int i = 0; i < data.length; i++){
			numbers[i] = Integer.parseInt(data[i]);
		}
		return numbers;
	}
	public static int sumPositive(int[] data){
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
			int[] inputData = loadData(args); 
			int allPositive = sumPositive(inputData);
			System.out.println("\nSum of all positive input = " + allPositive);
		}
		catch (NumberFormatException e){
			System.out.println("ERROR: invalid data found in input");
		} 
		System.out.println("\nBye!");
		
	} // end of main
	
} // end of class
