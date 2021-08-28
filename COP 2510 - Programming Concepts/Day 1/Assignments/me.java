/* me.java*/
import java.text.NumberFormat;
import java.util.Scanner;

class me
{
	public static long factorial(long inputValue){
		long factorialValue = inputValue;
		while (inputValue > 1){
			inputValue -= 1;
			factorialValue = factorialValue*inputValue;
		}
		return factorialValue;
	}
	
	public static void askForInt(){			
		System.out.println("Please enter an integer 0-20:");		
		isNumberBetween();
	}
	
	public static void isNumberBetween(){	
		Scanner sc = new Scanner(System.in);		
		try
		{
			int inputValue = Integer.parseInt(sc.nextLine());
			System.out.println(factorial(inputValue));
		}
		catch (NumberFormatException e)
		{
			System.out.println("Incorrect input...try again");
			askForInt();
		}
	}
	
	public static String wouldUserContinue(){
		Scanner sc = new Scanner(System.in);
		System.out.println("Would you like to go again? (y/n)");
		String answer = sc.nextLine();
		return answer;
	}
	
	public static void main(String args[])
	{
		String name = "David Hatcher";
		int uId = 74842093;
		String favoriteLanguage = "C#";
		int creditHours = 101;
		String gradeExpected = "A";
		
		System.out.println("Name: " + name+ "\n" + "U id: " + uId + "\n" + "Favorite Programming Lanuage: " + favoriteLanguage + "\n" + "Credit Hours: " + creditHours + "\n" + "Expected Grade: " + gradeExpected );
		
		String choice = "y";
		
		while (choice.equalsIgnoreCase("y")){
			System.out.println("Welcome to the Factorial Calculator");
			askForInt();			
			choice = wouldUserContinue();
		}
		
		System.out.println("Bye!");
	}
}