/*	
		Quick review of Polymorphism and CAST
*/

class student {
	protected double GPA = -1;
	public void setGPA(double gpa){
		GPA = gpa;
	}	
	public void print(String s){
		System.out.println(s + "....student details.... GPA = " + GPA);
	}
	public void hello(String s){
		System.out.println(s + " says hello");
	}
}

class undergraduate_student extends student {
	private int SAT;
	public void setSAT(int sat){
		SAT = sat;
	}
	public void print(String s){
		super.print(s);
		System.out.println(s + "....undergraduate_student details.... GPA = " + 
			GPA + " SAT = " + SAT);
	}
}

class graduate_student extends student {
	protected int GRE;
	public void setGRE(int gre){
		GRE = gre;
	}	
	public void setScores(double gpa, int gre){
		super.setGPA(gpa);
		this.GRE = gre;
	}	
	public void print(String s){
		System.out.println(s + "....graduate_student details.... GPA = " +
			super.GPA + " GRE = " + this.GRE);
	}
	public void hello(String a){
		System.out.println(a + a + a + "hello hello");
	}
}
public class inh_6 {
	public static void main(String args[]) {
		student A = new undergraduate_student();
		
		if (A instanceof student)
			System.out.println("\nA is an instance of student");	
		else 
			System.out.println("\nA is NOT an instance of student");
		
		if (A instanceof undergraduate_student)
			System.out.println("\nA is an instance of undergraduate student");	
		else 
			System.out.println("\nA is NOT an instance of undergraduate student");
		
		System.out.println();
		
		A.setGPA(2.1);
		//A.setSAT(1000);	// setSAT() is not a method of student class
		A.print("A");		// although A is declared to have a type of student,
							// the print() of undergraduate_student is invoked
		System.out.println();
		
		
		undergraduate_student B = (undergraduate_student)A; 
		
		if (B instanceof student)
			System.out.println("\nB is an instance of student");	
		else 
			System.out.println("\nB is NOT an instance of student");
		
		if (B instanceof undergraduate_student)
			System.out.println("\nB is an instance of undergraduate student");	
		else 
			System.out.println("\nB is NOT an instance of undergraduate student");
		System.out.println();
		
		//A.setSAT(1000);		// still an error
		A.setGPA(2.99);
		B.setSAT(1000);
		A.print("A");
		B.print("B");
		System.out.println();
		
		B.setGPA(2.88);
		A.print("A");
		B.print("B");
		System.out.println();
		
		student C = new student();
		C = B;	//Added in to make program work

		//undergraduate_student D = C; 				// COMPILE ERROR: incompatible types
		//undergraduate_student D = new student();	// COMPILE ERROR: incompatible types
		undergraduate_student D = (undergraduate_student)C;  //COMPILE OK, but failed execution: ClassCastException 
		
		C.print("C");
		D.print("D");

		System.out.println();		
	}
}