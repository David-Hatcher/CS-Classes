package summer.COP2510;

import java.util.Scanner;

public class WhileExample2 {

    public static void main(String[] args) {
		System.out.println("This program calculate 1+2+3+4+.....+N");

        // create the Scanner object
        Scanner keyboard = new Scanner(System.in);

        // perform conversions until choice isn't equal to "y" or "Y"
        String choice = "y";
        while (choice.equalsIgnoreCase("y")) {
			int sum = 0, num = 1;
            // prompt to enter upper bound of sum
			System.out.print("\nPlease enter the upper bound of " +
				"the sum, which must be 1 or bigger: ");
            int max_sum = Integer.parseInt(keyboard.nextLine());

            // start adding num into sum 
            while (sum <= max_sum){
				if ((sum + num) <= max_sum) {
					sum = sum + num;
					num = num + 1;
				}
				else
					break;
			}
			System.out.println("sum = " + sum);
			System.out.println("last number added is: " + (num - 1));
            
            // see if the user wants to continue
            System.out.println("\nContinue? (y/n): ");
            choice = keyboard.nextLine();
        }
		System.out.println("\nBye!!!");
    }
}
