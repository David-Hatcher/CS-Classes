/*	
		final method
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

class undergraduate_student extends student {
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


class inh_11 {
	public static void main(String args[]) {
		
		student frank = new student();  
		System.out.println();
		frank.setGPA(2.5);
		frank.print("frank");	// calling a final method is OK
		System.out.println();
		
		undergraduate_student jenny = new undergraduate_student();	
		System.out.println();
		jenny.setGPA(2.8);
		jenny.setSAT(880);
		
		System.out.println("\n--> jenny.print(\"jenny\")");
		jenny.print("jenny"); 	// calling a superclass final method is OK
		
		System.out.println("\n--> jenny.print()");
		jenny.print();			// calling a local method
		
		System.out.println();		
	}
}