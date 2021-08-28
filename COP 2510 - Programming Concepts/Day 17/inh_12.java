/*	
		final class - such a class is used to prevent it from being inherited
		
		all methods in the final class are automatically final
*/

class student {
	protected double GPA = -1;
	public void setGPA(double gpa){
		GPA = gpa;
	}	
	
	// final method means suclasses of student can never override it
	
	public final void print(String s){
		System.out.println(s + "....student details.... GPA = " + GPA);
	}
	public void hello(String s){
		System.out.println(s + " says hello");
	}
}

// this is a final class, which can never be inherited, i.e., it won't have subclasses

final class undergraduate_student extends student {
	private int SAT;
	public void setSAT(int sat){
		SAT = sat;
	}
	/* the following print() makes COMPILE ERROR: overridden method is final
	public void print(String s){	
		super.print(s);
		System.out.println(s + "....undergraduate_student details.... GPA = " + 
			GPA + " SAT = " + SAT);
	}
	*/
	public void print(){	
		super.print("somebody");
		super.hello("somebody");
		System.out.println("....undergraduate_student details.... GPA = " + 
			GPA + " SAT = " + SAT);
	}	
	
}

// COMPILE ERROR: cannot inherit a final class
class scholarship_undergraduate_student extends undergraduate_student {
	private double scholarship = 2500;
}

class inh_12 {
	public static void main(String args[]) {
		
		student paul = new scholarship_undergraduate_student();  
		
		System.out.println();		
	}
}