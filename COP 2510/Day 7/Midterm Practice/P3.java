import java.util.Random;

public class P3{

	static Random r = new Random();
	static int vCount = 0;
	
	public static void Print(String input){
		System.out.print(input);
	}
	
  public static int ChooseRange(){
		return r.nextInt(4);
	}

	public static int MakeRandomNumber(int range){
		int randomNumber = 0;
		switch(range){
			case 1:{randomNumber = r.nextInt(19) - 15	;	break; }
			case 2:{randomNumber = r.nextInt(36) + 20	; break; }
			case 3:{randomNumber = r.nextInt(11) + 101; break; }
		}
		return randomNumber;
	}

	public static boolean IsNumberDivisibleByThree(int randomNumber){
		boolean numberIsDivisibleByThree = false;
		if(randomNumber%3 == 0){
			numberIsDivisibleByThree = true;
			vCount++;
		}
		return numberIsDivisibleByThree;
	}

	public static void PrintNumber(int cycle, int randomNumber){
		Print("(" + cycle +")\t" + randomNumber);
		if(IsNumberDivisibleByThree(randomNumber)==true){	Print(" v\n");	}
		else{	Print("\n");	}
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