import java.util.ArrayList;

class stuOrg{
	private String name;
	private int membership;
	private double balance;
	private ArrayList<student> members;
	public stuOrg(String id, int fee, double bal){
		name = id;
		membership = fee;
		balance = bal;
		members = new ArrayList<>();
	}
	public void addMember(student newMember){
		members.add(newMember);
		this.balance += membership;
	}
	public void deleteMember(student memberToDelete){
		members.remove(memberToDelete);
		System.out.println("\n...." + memberToDelete.getU_no() + " is deleted from " + this.name);
	}
	public ArrayList<student> getAllMembers(){
		return members;
	}
	public String getName(){
		return name;
	}
	public double getBalance(){
		return balance;
	}	
}//end of stuOrg
	
class student{
	private String u_no;
	private char gender;
	private double gpa;
	public student(String id, char mf, double g){
		u_no = id;
		gender = mf;
		gpa = g;
	}
	public String getU_no(){
		return u_no;
	}	
	public char getGender(){
		return gender;
	}
	public double getGPA(){
		return gpa;
	}
	public String details(){
		return u_no + " (" + gender + ", " + gpa + ")"; 
	}
}//end of student


public class threeClassesAL{   
    public static void main(String args[]) { 
		student john = new student("U101", 'M', 3.22);
		student mary = new student("U102", 'F', 3.45);
		student pam = new student("U103", 'F', 2.81);
		student kathy = new student("U104", 'F', 4.0);
		student ben = new student("U105", 'M', 3.05);
		
		stuOrg g1 = new stuOrg("Computer Club", 15, 1200);
		stuOrg g2 = new stuOrg("Art Club", 28, 301);
		
		g1.addMember(john);
		g1.addMember(kathy);
		g1.addMember(ben);
		g2.addMember(mary);
		g2.addMember(pam);		
		g2.addMember(kathy);
		g2.addMember(ben);
		
		printAllMembers(g1);
		printAllMembers(g2);
				
		g2.deleteMember(pam);
		printAllMembers(g2);

		summary(g1);
		summary(g2);
		
		//How many and who are in both g1 and g2?
		ArrayList<student> both = compare(g1, g2);
		System.out.println("\n" + both.size() + " students who are members of " + g1.getName() +
				" and " + g2.getName() + ":");
		for (student s : both)
			System.out.println("\t" + s.details());	
    } //end of main
	
	private static void printAllMembers(stuOrg g){
		System.out.println("\n" + g.getName() + ":\n-----------------");
		for (student s : g.getAllMembers())
			System.out.println(s.details());		
	}
	
	private static void summary(stuOrg g){
		int count_M = 0, count_F = 0;
		for (student s : g.getAllMembers())
			if (s.getGender() == 'M') 
				count_M++;
			else
				count_F++;
		System.out.println("\n" + g.getName() + " summary:\n----------------------------");
		System.out.println("\tBalance = $" + g.getBalance());
		System.out.println("\tM = " + count_M);
		System.out.println("\tF = " + count_F);
		System.out.printf("\tGPA = %.3f (avg)\n", avgGPA(g));
	}
	
	private static double avgGPA(stuOrg g){
		double total = 0;
		for (student s : g.getAllMembers())
			total += s.getGPA();
		return total/g.getAllMembers().size();
	}
	
	//find and return those in both stuOrg
	private static ArrayList<student> compare(stuOrg one, stuOrg two){
		ArrayList<student> all_mem_one = one.getAllMembers();
		ArrayList<student> all_mem_two = two.getAllMembers();
		ArrayList<student> common = new ArrayList<>();		
		for (student s2 : all_mem_two)	//smaller list as the base
			for (student s1 : all_mem_one)
				if (s1.getU_no().equals(s2.getU_no()))
					common.add(s2);
		return common;		
	} // end of compare()
} //end of class threeClassesAL