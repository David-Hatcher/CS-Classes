import java.text.NumberFormat;

class compute{
	private double n1, n2, result;
	private char operation;
	public compute(double num1, double num2, char op){
		n1 = num1;
		n2 = num2;
		operation = op;
	}
	public boolean doOperation(){
		boolean success = true;
		if (operation == '+')
			result = n1 + n2;
		else if (operation == '-')
			result = n1 - n2;
		else if (operation == '*')
			result = n1 * n2;
		else if (operation == '/' && n2 != 0)
			result = n1 / n2;
		else if (operation == '/' && n2 == 0)
			success = false;
			
		return success;
	}
	public void print(){
		NumberFormat number = NumberFormat.getNumberInstance(); 
		number.setMaximumFractionDigits(4); 
		String resultFormatted = number.format(result);
		System.out.println(n1 + " " + operation + " " + n2 + " = " + resultFormatted);
	}
}
	
public class calculation{   
    public static void main(String args[]) { 
		compute c1 = new compute(Double.parseDouble(args[0]), 
								 Double.parseDouble(args[1]), args[2].charAt(0));	
        System.out.println();
		if (c1.doOperation())
			c1.print();
		else
			System.out.println("\nCANNOT DEVIDE BY ZERO!");
    } 
} 