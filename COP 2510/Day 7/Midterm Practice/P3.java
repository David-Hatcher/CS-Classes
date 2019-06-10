package midterm.classes;


import java.util.Random;

public class P3{

	static private Random rand = new Random();
	static private int vCount = 0;
	
	public static void Print(String input){
		System.out.print(input);
	}
	
  public static int ChooseRange(){
		return randomNum(3,1);
	}

	public static int MakeRandomNumber(int range){	
		int randomNumber = 999;
		switch(range){
			case 1:{randomNumber = randomNum(19,-15); break;}
			case 2:{randomNumber = randomNum(36,20);  break;}
			case 3:{randomNumber = randomNum(11,101); break;}
			default:{Print("Error no range for that value"); break;}
		}
		return randomNumber;
	}

	public static int randomNum(int aVal, int bVal){
		int randomNumber = rand.nextInt(aVal) + bVal	;
		return randomNumber;
	}

	public static boolean IsNumberDivisibleByThree(int randomNumber){		
		if(randomNumber % 3 == 0){			
			vCount++;
			return true;
		}
		return false;
	}

	public static void PrintNumber(int cycle, int randomNumber){
		String numberStringEnding = IsNumberDivisibleByThree(randomNumber) ? " v\n" : "\n";
		String numberString = "(" + cycle + ")\t" + randomNumber + numberStringEnding;
		Print(numberString);

	}

	public static String HowManyDivisibleBy3(){
		return "Total Number of Random Numbers Divisible By 3 = " + vCount + "\n";
	}

	public static String barSeparatorString(){
		return "------------------\n";
	}

	public static void RunRandomNumberMaker(){
		for(int i = 1; i <= 20; i++){
			PrintNumber(i,MakeRandomNumber(ChooseRange()));
		}
		Print(barSeparatorString());
		Print(HowManyDivisibleBy3());
	}

  public static void main(String[] args) {
      RunRandomNumberMaker();
  }
}