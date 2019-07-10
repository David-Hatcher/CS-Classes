/*	
		abstract class
*/

abstract class student {
	protected double GPA = -1;
	public void setGPA(double gpa){
		GPA = gpa;
	}	
	public double getGPA(){
		return GPA;
	}	
	public void print(String s){
		System.out.println(s + "....student details.... GPA = " + GPA);
	}
	public void hello(String s){
		System.out.println(s + " says hello");
	}
} // end of student

class undergraduate_student extends student {		// an abstract class can be extended
	private int SAT;
	public void setSAT(int sat){
		SAT = sat;
	}
	public void print(String s){
		super.print(s);
		System.out.println(s + "....undergraduate_student details.... GPA = " + 
			GPA + " SAT = " + SAT);
	}
} // end of undergraduate_student

class inh_9 {
	public static void main(String args[]) {
		
		//student E = new student();  // COMPILE ERROR: objects cannot be instantiated from an
									  // abstract class

		undergraduate_student crist = new undergraduate_student();
		
		System.out.println();
		crist.setGPA(4);
		crist.setSAT(1200);
		crist.print("crist");
		System.out.println();		
	}
}