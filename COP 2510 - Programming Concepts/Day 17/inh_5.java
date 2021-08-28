/*	
	'instanceof' operator
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
class inh_5 {
	public static void main(String args[]) {
		student somebody = new student();
		undergraduate_student peter = new undergraduate_student();
		graduate_student lisa = new graduate_student();
		
		somebody.setGPA(4.0);
		somebody.print("\nsomebody");
		System.out.println();
		
		peter.setGPA(3.8);
		peter.setSAT(1080);
		peter.print("peter");

		lisa.setGPA(3.33);
		lisa.setGRE(155);
		lisa.print("lisa");	
		
		//COMPILE ERROR: "imcompatible types" 
		// peter = somebody;	
		
		/*********************************************************************
			NEVER CAST a superclass object to a subclass object
			but, CAST a subclass object to a superclass object is always OK
		**********************************************************************/		
		somebody = peter; // somebody was declared to be a student object
						  // but it "represents" an undergraduate student now.
		
		System.out.println("\n....after    somebody = peter;\n");
		if (somebody instanceof student)
			System.out.println("somebody is an instance of student");
		else 
			System.out.println("somebody is NOT an instance of student");
		if (somebody instanceof undergraduate_student)
			System.out.println("somebody is an instance of undergraduate_student");
		else 
			System.out.println("somebody is NOT an instance of undergraduate_student");
		somebody.print("somebody is peter 1");	// this does NOT invoke print() of student
										// but undergraduate_student, so it prints
										// 3.8 GPA, not 4.0, plus 1080 SAT
		
		System.out.println("\n....after    peter.setGPA(2.99);\n");
		
		peter.setGPA(2.99);
		somebody.print("somebody is peter 2");	// it prints 2.99 GPA plus SAT because somebody IS peter
		
		System.out.println("\n....after    somebody.setGPA(0);\n");
		
		somebody.setGPA(0);				// OK because setGPA() is a method of student
		somebody.print("somebody is peter 3"); 	// it still uses print() of peter for 0 GPA plus 1080 SAT
		System.out.println();
		
		// somebody.setSAT(1100);			// ERROR: "cannot find symbol" setSAT()
											//        because JRE knows somebody is still 
											//		  NOT an undergraduate_student object
		
		System.out.println("\n....after    somebody.setGPA(0);\n");
		
		peter.setSAT(1100);									
		somebody.print("somebody is peter 4");	
		System.out.println();
		
		
		somebody = lisa;  // somebody was declared to be a student object
						  // but it "represents" an graduate student now.
		
		// somebody.setGRE(175);	// same error as somebody.setSAT(1100);
									// because somebody only "represents" lisa but
									// it is still not a graduate student object.
		System.out.println("\n....after    somebody = lisa;\n");
		if (somebody instanceof student)
			System.out.println("somebody is an instance of student");
		else 
			System.out.println("somebody is NOT an instance of student");
		if (somebody instanceof undergraduate_student)
			System.out.println("somebody is an instance of undergraduate_student");
		else 
			System.out.println("somebody is NOT an instance of undergraduate_student");		
		if (somebody instanceof graduate_student)
			System.out.println("somebody is an instance of graduate_student");
		else 
			System.out.println("somebody is NOT an instance of graduate_student");

		somebody.print("somebody is lisa");						  
		//--------------------------

		System.out.println("\n======================================\n");
		student zack = new student();
		zack.setGPA(1.0);
		zack.print("zack");
		System.out.println();
		
		// the following cast can compile but cannot execute because of
		// "ClassCastException" at run time
		
		// undergraduate_student miki = (undergraduate_student)zack;  // zack is a superclass object
		
		/*******************************************************
		 NEVER CAST FROM SUPERCALSS TO SUBCLASS
		 UNLESS IT WAS FIRST CAST FROM SUBCLASS TO SUPERCALSS
		 AND CAST BACK TO SUBCLASS LIKE EXAMPLE BELOW
		 ******************************************************/
		
		graduate_student anna = (graduate_student)somebody;	// somebody is a superclass object
															// but was once cast to a subclass 
															// object lisa, so this superclass 
															// object can cast to a subclass object

		// undergraduate_student anna = (undergraduate_student)somebody;	// RUN-TIME ERROR. Why??												
		
		anna.setGRE(101);		
		anna.print("anna");
		somebody.print("somebody");
		System.out.println();
		
		somebody.setGPA(-2);
		anna.print("anna");
		somebody.print("somebody");		
		System.out.println();
		
		// somebody.setGRE(199);		// COMPILE ERROR. Why??
		
		if (somebody instanceof graduate_student)
			System.out.println("somebody is an instance of graduate_student");
		else 
			System.out.println("somebody is NOT an instance of graduate_student");
		
		if (somebody instanceof student)
			System.out.println("somebody is an instance of student");
		else 
			System.out.println("somebody is NOT an instance of student");		
		
	}
}