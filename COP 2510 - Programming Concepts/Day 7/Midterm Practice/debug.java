import java.util.Scanner; //fixed

class debug  { 
    public static void main(String args[]) {  //fixed
        Scanner keyboard = new Scanner(System.in);  //fixed
        String ans = "y"; //fixed
        while (ans.equalsIgnoreCase("y")){  //fixed
            System.out.print("Enter an integer: ");
            int aNumber = Integer.parseInt(keyboard.nextLine()); //fixed
            int result = aNumber * aNumber; 
            System.out.println(aNumber + " * " + aNumber + " = " + result);
            System.out.print("Run again? (y/n) ");
            ans = keyboard.nextLine();
        } 
    } 
}