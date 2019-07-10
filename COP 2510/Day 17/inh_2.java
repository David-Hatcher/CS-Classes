class student {
	protected String sid; //This can be accessed by any of the child classes
	public void setSID(String id){
		sid = id;
	}
	public void print(String s){
		System.out.println(s + "....student details.... " + sid);
	}
	public void hello(String s){
		System.out.println(s + " says hello");
	}
}

class undergraduate_student extends student {
	private int sid;	//The compiler allows this 
	public void setSID(int id){
		sid = id;
	}	
	public void print(String s){
		super.print(s);
		System.out.println(s + "....undergraduate_student details.... " + sid + 
								" (" + super.sid + ")");
	}
}

class graduate_student extends student {
	private double sid;	
	public void setSID(double id){
		sid = id;
	}	
	public void print(String s){
		System.out.println(s + "....graduate_student details.... " + sid + 
								" (" + super.sid + ")");
	}
	public void hello(String a){
		System.out.println(a + a + a + "hello hello");
	}
}
class inh_2 {
	public static void main(String args[]) {
		student john = new student();
		undergraduate_student peter = new undergraduate_student();
		graduate_student lisa = new graduate_student();
		
		john.setSID("sid_JOHN");
		peter.setSID(11111);
		lisa.setSID(2.2222);
		
		john.print("john");
		peter.print("peter");
		lisa.print("lisa");
		
		System.out.println();
		
		john.hello("john");
		peter.hello("peter");
		lisa.hello("lisa");
		//lisa.hello();
	}
}