public class Strings{	
	public static void main(String[] args){
		String s1 = "Tampa Florida";
		int x = 55555;
		String s2 = s1 + " " + x;
		String s3 = s1.substring(2); // from index 2 to 8
		String s4 = s1.substring(2,8); // from index 2 to 8, exclusive
		String s5 = s1.substring(s1.length()-1-4);
		String s6 = s2 + s4;
		String s7 = s1.replace('a', 'x');
		String s8 = s1.toUpperCase();
		String s9 = "    " + s1 + "  ";
		String s10 = s9.trim();
		String s11 = "";
		String s12 = null;
		String s13 = "tampa Florida";
		int i = s1.indexOf('a');
		int j = s1.indexOf('a', 2);
		int k = s1.indexOf("pa F");
		int m = s1.indexOf("pa f");
		int n = s1.indexOf("pa F", 4);
		
		System.out.println("s1: " + s1);
		System.out.println("s2: " + s2);
		System.out.println("s3: " + s3);
		System.out.println("s4: " + s4);
		System.out.println("s5: " + s5);
		System.out.println("s6: " + s6);
		System.out.println("s7: " + s7);
		System.out.println("s8: " + s8);
		System.out.println("s9+s1: " + s9 + s1);
		System.out.println("s10+s1: " + s10 + s1);
		System.out.println("i: " + i);
		System.out.println("j: " + j);
		System.out.println("k: " + k);
		System.out.println("m: " + m);	
		System.out.println("n: " + n);	
		System.out.println("s1.contains(\"rida\") --> " + s1.contains("rida"));
		System.out.println("s1.contains(\" \") --> " + s1.contains(" "));
		System.out.println("s1.contains(\"ridx\") --> " + s1.contains("ridx"));
		System.out.println("s1.isEmpty() --> " + s1.isEmpty());
		System.out.println("s1 != null --> " + (s1 != null));
		System.out.println("s11.isEmpty() --> " + s11.isEmpty());
		System.out.println("s11 == null --> " + (s11 == null));
		System.out.println("s12 == null --> " + (s12 == null));
		//System.out.println("s12.isEmpty() --> " + s12.isEmpty());			//ERROR
		//System.out.println("s12.equals(null) --> " + s12.equals(null));	//ERROR
		System.out.println("s1.equals(s13) --> " + s1.equals(s13));
		System.out.println("s1.equalsIgnoreCase(s13) --> " + s1.equalsIgnoreCase(s13));
		
		//showing effect of precedence
		
		x = 33;
		int y = 55;
		String g1 = x + y + "total";
		String g2 = "total " + x + y;
		String g3 = " " + x + y + "total";
		System.out.println();
		System.out.println("g1: " + g1);
		System.out.println("g2: " + g2);
		System.out.println("g3: " + g3);
	}
}