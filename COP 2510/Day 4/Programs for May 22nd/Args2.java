//import java.text.NumberFormat;

public class Args2 //ScannerAndKeyboard
{
	public static void main(String[] args)
	{	
		//Assuming three command line arguments are decimal numbers,
		//e.g., 1.1 2.22 5.5555:
		double n1 = Double.parseDouble(args[0]);
		double n2 = Double.parseDouble(args[1]);
		double n3 = Double.parseDouble(args[2]);
		System.out.println(args[0] + " + " + args[1] + " + " + args[2] + " = " + (n1+n2+n3));
	
		/*
		NumberFormat answer = NumberFormat.getNumberInstance();
        answer.setMaximumFractionDigits(2);
		System.out.println(args[0] + " + " + args[1] + " + " + args[2] + 
			" = " + answer.format(n1+n2+n3));	
		*/
	}
}