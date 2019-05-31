import java.util.*;

public class Assignment3 {

	static Scanner ConsoleInput = new Scanner(System.in);
	static String WordsToCount;
	static String WordsAndCharacterString = "";
	static int TotalWordCount;

	static String[] NamesList = {
					"James Mazzaro",
					"Susanna Singleton",
					"Kenroy Morgan",
					"Majed Almalki",
					"Jaron Grimes",
					"Dev Tejwani",
					"Eduardo Troche",
					"Arnaldo Barea",
					"David Morris",
					"David Hatcher",
					"Ivan Castanon",
					"Muath Juma",
					"Matteo Vescera",
					"Glenn Akens",
					"Kangwei Chang",
					"Carlos Hernandez",
					"Judy Chen",
					"Geoffroy De Blegiers",
					"Mohammad Fazle Ali",
					"Raymond Dunbar",
					"Raquel Pereda",
					"Ali Bayatpoor",
					"Henri Berisha",
					"David Debois Sousa",
					"Yi Tao",
					"Stephen Diehl",
					"Garrett Ford",
					"Jade Bruce",
					"Jose Hennessy",
					"Victor Jimenez",
					"Kevin Archie",
					"Kaylie Johnson",
					"Alan Schulwitz",
					"Xiangzhong Wei",
					"Marissa Bondoc",
					"Estevan Rivera",
					"Jia Chen Wong",
					"Robert Andion",
					"Yinet Juvier",
					"Nicola Kelly",
					"Mahmoud Ali",
					"Orestes Bringas",
					"Noah Reichert",
					"Ebin Mathew",
					"Omar Alkishawi",
					"Josue Gonzalez",
					"Bernard Orozco",
					"Evangeline Polepaka",
					"Andrey Kukushkin"
	};
	static ArrayList<String> TempNameList;

	public static String SelectRandomName(){
		Random R = new Random();
		String Name = TempNameList.get(R.nextInt(TempNameList.size()));
		TempNameList.remove(Name);
		return Name;
	}

	public static void CompileTeams(int QuantityOfTeams){
		TempNameList = new ArrayList<>(Arrays.asList(NamesList));
		String[][] Teams = new String[QuantityOfTeams][3];
		for(int i = 0; i < QuantityOfTeams; i++){
			Teams[i] = MakeTeam();
		}
		DisplayTeams(Teams);
	}
	public static String[] MakeTeam() {
		String[] Team = new String[3];
		for(int i = 0; i < 3; i++){
			Team[i] = SelectRandomName();
		}
		return Team;
	}
	public static void DisplayTeams(String[][] Teams){
		int TeamNumber = 1;
		for (String[] Team: Teams) {
			System.out.println("\nTeam " + TeamNumber +":\n");
			TeamNumber = TeamNumber + 1;
			for (String Member : Team) {
				System.out.println("\t" + Member);
			}
		}
	}

	public static void GreetUser(){
		System.out.println("Assignment-3 can perform the following two tasks:");
		System.out.println("\t1 - Making 3-member teams from class of COP2510");
		System.out.println("\t2 - Parsing and counting an input sentence by word");
	}

	public static String AskUsersInput(){
		System.out.print("\nEnter 1 or 2 to being your task or anything else to quit: ");

		String UserInput = ConsoleInput.nextLine();
		return UserInput;
	}

	public static void RunProgram(String Choice){
		if(Choice.equals("1")){
			RunTeamBuilder();
		}
		else{
			RunWordCounter();
		}
	}

	public static void RunTeamBuilder(){

		System.out.print("Enter total number of teams: ");
		try {
			int UserInput = Integer.parseInt(ConsoleInput.nextLine());
			if (UserInput >= 1 && UserInput <= NamesList.length / 3) {
				CompileTeams(UserInput);
			} else if (UserInput > NamesList.length / 3) {
				System.out.println("There are not enough team members to create " + UserInput + " full teams.");
			}
		}
		catch(Exception e){
			NumbersParty();
		}
	}

	public static void RunWordCounter(){
		System.out.print("\nEnter one or more sentences:");
		WordsToCount = ConsoleInput.nextLine().trim();
		CountWords();
	}

	public static void CountWords(){
		WordsAndCharacterString = "";
		TotalWordCount = 0;
		PrintRule();
		if(WordsToCount.length() > 0) {
			while (WordsToCount.length() > 0) {
				PullWord();
				WordsAndCharacterString = "";
			}
		}else{
			System.out.println("Nothing or only space(s) is entered.");
		}
		PrintRule();
		System.out.println("Total words = " + TotalWordCount);
	}
	public static void PullWord(){
		int i = 0;
		do{
			WordsAndCharacterString += WordsToCount.substring(i,i+1);
			i++;
		}while(i < WordsToCount.length() && !WordsToCount.substring(i,i+1).equals(" "));
		WordsAndCharacterString += " (" + (i) + ")";
		System.out.println(WordsAndCharacterString);
		WordsToCount =  WordsToCount.substring((i)).trim();
		TotalWordCount += 1;
	}

	public static void PrintRule(){
		System.out.println("----------------------------");
	}

	public static void NumbersParty(){
		System.out.println("This is a numbers party....please AB&C your way back to the start.");
	}

	public static void main(String[] args) {
		GreetUser();
		String Choice = AskUsersInput();
		while(Choice.equals("1") || Choice.equals("2")){
			RunProgram(Choice);
			Choice = AskUsersInput();
		}
		System.out.println("End of Assignment-3");
	}
}