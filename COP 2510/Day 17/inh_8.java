/*	
		Let graduate_student class override the 'equals()' method of Object class
*/

class student {
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
	public int getGRE(){
		return GRE;
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
	
	@Override 
	public boolean equals(Object obj) {
		if (obj instanceof graduate_student) { 
			graduate_student gs = (graduate_student) obj; 
			if (this.getGPA() == gs.getGPA() &&
				this.getGRE() == gs.getGRE()) 
				return true; 
		}
		return false;
	}
	
	//Overloading
	public boolean equals(graduate_student g) {
		System.out.println("\n......overloading equals() is called");
		if (this.getGPA() == g.getGPA() &&
			this.getGRE() == g.getGRE()) 
				return true; 
		return false;
	}	
} // end of graduate_student


class inh_8 {
	public static void main(String args[]) {
		graduate_student X = new graduate_student();
		graduate_student Y = new graduate_student();

		if (X.equals(Y) && Y.equals(X))
			System.out.println("\nBefore set data, X and Y are the 'same' object.");
		else
			System.out.println("\nBefore set data, X and Y are NOT the 'same' object.");
		
		X.setGPA(3.333);
		Y.setGPA(3.333);
		X.setGRE(160);
		Y.setGRE(160);

		if (X.equals(Y) && Y.equals(X))
			System.out.println("\nAfter set identical data, X and Y are the 'same' object.");
		else
			System.out.println("\nAfter set identical data, X and Y are NOT the 'same' object.");
/*		
		//-----------------------------
		
		graduate_student R = new graduate_student();
		graduate_student T = new graduate_student();
		
		R.setGPA(4);
		T.setGPA(3);
		R.setGRE(180);
		T.setGRE(150);
		
		System.out.println("\nR and T are 2 objects of graduate_student with different data");
		R = T;
		
		if (R.equals(T) && T.equals(R))
			System.out.println("\nAfter 'R = T;' R and T are the 'same' object.");
		else
			System.out.println("\nAfter 'R = T;' R and T are NOT the 'same' object.");

		//-----------------------------

		student S = new student();		
		graduate_student G = new graduate_student();
	

		S.setGPA(2.99);
		G.setGPA(3);
		G.setGRE(180);

		if (S.equals(G) && G.equals(S))
			System.out.println("\nS and G are the 'same' object.");
		else
			System.out.println("\nS and G are NOT the 'same' object.");	
		
		//G = S;	//COMPILE ERROR: incompatible types	
		S = G;
		
		if (S.equals(G) && G.equals(S))
			System.out.println("\nAfter 'S = G;' S and G are the 'same' object.");
		else
			System.out.println("\nAfter 'S = G;' S and G are NOT the 'same' object.");		
*/		
		System.out.println();		
	}
}