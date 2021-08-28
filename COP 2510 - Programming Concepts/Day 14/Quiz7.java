class Quiz7 {  
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
