/*	
		abstract method must be defined in an abstract class
		but, an abstract class is not required to have abstract methods
*/

abstract class student {
	protected double GPA = -1;
	public void setGPA(double gpa){
		GPA = gpa;
	}	
	public double getGPA(){
		return GPA;
	}	
	public abstract void print(String s);	// abstract method must include NO block of statements
	public void hello(String s){
		System.out.println(s + " says hello");
	}
} // end of student

class undergraduate_student extends student {		// an abstract class can be extended
	private int SAT;
	public void setSAT(int sat){
		SAT = sat;
	}
	
	// a class that extends an abstract class MUST implement all of its abstract methods
	
	@Override
	public void print(String s){
		//super.print(s);			// cannot call an abstract method
		super.hello(s);
		System.out.println(s + "....undergraduate_student details.... GPA = " + 
			GPA + " SAT = " + SAT);
	}
} // end of undergraduate_student


class inh_10 {
	public static void main(String args[]) {
		
		//student E = new student();  // COMPILE ERROR: objects cannot be instantiated from an
									  // abstract class

		undergraduate_student daniel = new undergraduate_student();
		
		System.out.println();
		daniel.setGPA(4);
		daniel.setSAT(1200);
		daniel.print("daniel");
		System.out.println();		
	}
}