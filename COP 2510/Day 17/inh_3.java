/*
	A subclass can define extra fields and methods which are not
	available to its superclass.
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
class inh_3 {
	public static void main(String args[]) {
		student john = new student();
		undergraduate_student peter = new undergraduate_student();
		graduate_student lisa = new graduate_student();
		graduate_student eric = new graduate_student();
		
		john.setGPA(3.33);
		//john.setSAT(1123);
		//john.setGRE(162);
		
		peter.setGPA(2.95);
		peter.setSAT(1123);
		//peter.setGRE(162);
		
		//lisa.setSAT(1123);
		lisa.setGRE(162);
		eric.setGRE(199);
		eric.setScores(3.03, 179);
		
		john.print("john");
		peter.print("peter");
		lisa.print("lisa");
		eric.print("eric");
		
		System.out.println();
		
		john.hello("john");
		peter.hello("peter");
		lisa.hello("lisa");
		//lisa.hello();
		eric.hello("eric");
	}
}