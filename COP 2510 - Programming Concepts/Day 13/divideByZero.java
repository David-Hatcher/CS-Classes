
import java.util.ArrayList;

class divideByZero { 
	private static void divide(double n1, double n2){	
		try {
			if (n2 == 0){
				throw new ArithmeticException("You cannot divide by zero!");//you can throw your own errors if you want
			}
			double ans = n1/n2;
			System.out.println(ans);
		} catch (Exception e) {//This will then catch the error that was thrown
			System.out.println(e.getMessage());
		}			
	}
    public static void main(String args[]) { 		
		divide(100.5, 0.0);
	} // end of main
} //end of class