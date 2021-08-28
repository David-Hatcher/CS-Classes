import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

class GPAException extends Exception {
	public GPAException(String message) { 
		super(message);
	}
}

class GPA_Analysis {
	private double[] allGPA;
	public GPA_Analysis(ArrayList<Double> input) throws GPAException {	
		allGPA = new double[input.size()];
		for(int i = 0; i < input.size(); i++){
			if(input.get(i) <= 4.0 && input.get(i) >= 0.0){
				allGPA[i] = input.get(i);
			}
			else{
				throw new GPAException("<GPA_Analysis ERROR>: Invalid GPA data found!");
			}
		}
	}

	public void top3() {
		Arrays.sort(allGPA);
		try {
			String gpaString = "";
			for(int i = allGPA.length-1; i > allGPA.length-1-(3); i--){
				gpaString += (" " + allGPA[i]);
			}
			System.out.print("\nTop 3 GPA (out of " + allGPA.length + " total GPA):" + gpaString + "\n");
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.print("\nAll GPA data:");
			for(int i = allGPA.length-1; i >= 0; i--){
				System.out.print(" " + allGPA[i]);
			}
			System.out.println();
		}
	}

	public void bottom3() {
		Arrays.sort(allGPA);
		try {
			String gpaString = "";
			for(int i = 0; i < 3; i++){
				gpaString += (" " + allGPA[i]);
			}
			System.out.print("\nBottom 3 GPA (out of " + allGPA.length + " total GPA):" + gpaString + "\n");
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.print("\nAll GPA data:");
			for (Double gpa : allGPA) {
				System.out.print(" " + gpa);
			}
			System.out.println();
		}
	}	

	public void average() {
		double avg;
		double gpaTotal = 0;
		for (Double gpa : allGPA) {
			gpaTotal += gpa;
		}
		avg = gpaTotal/(double) allGPA.length;
		System.out.printf("\nAverage GPA: %05.3f", avg);
	}	
} //end of GPA_Analysis class


class Assignment6 {  
    public static void main(String args[]) { 
		ArrayList<Double> myData = makeSureThereAreInputData(args);
		while (true) {
			try {
				GPA_Analysis gpaa = new GPA_Analysis(myData);
				gpaa.top3();
				gpaa.bottom3();
				gpaa.average();
				break;
			}
			catch (GPAException e) {
				System.out.println();
				System.out.println(e.getMessage());
				cleanseData(myData);
			}
		}
		
		System.out.println("\n\n-------END-------");			
	} // end of main
	
	private static ArrayList<Double> makeSureThereAreInputData(String[] data){
		ArrayList<Double> newData = new ArrayList<Double>();
		Scanner sc = new Scanner(System.in);
		int total = data.length;
		if (total == 0)
			while (total == 0){
				System.out.print("\nNo GPA found, please enter GPA data now: ");
				String line = sc.nextLine();
				if (line.length() > 0){
					String[] columns = line.split(" ");
					for (String s : columns){
						try {
							newData.add(Double.parseDouble(s));
						}
						catch (NumberFormatException e){
							System.out.println("Non-numeric GPA found is found and discarded");
						}		
					}
					total = newData.size();
				}
			}
		else
			for (String s : data){
				try {
					newData.add(Double.parseDouble(s));
				}
				catch (NumberFormatException e){
					System.out.println("Non-numeric GPA found is found and discarded");
				}
			}
				
		return newData;
	} //end of makeSureThereAreInputData()
	
	private static void cleanseData(ArrayList<Double> data){
		ArrayList<Double> badData = new ArrayList<Double>();
		for (Double number : data) {
			if(number > 4.0 || number < 0.0){
				System.out.println(number + " is removed");
				badData.add(number);
			}
		}
		data.removeAll(badData);
		System.out.println("Data cleanse done!");
	} //end of cleanseData()
} //end of class