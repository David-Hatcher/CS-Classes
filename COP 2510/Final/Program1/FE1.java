package COP2510.finalexam;

import COP2510.library.USF_exp;
/*It defines a package of COP2510.finalexam.
It defines only one method, which is main().
In main(), it uses the two input integers from command line (i.e., its input parameter of String array) to 
calculate the result of raising a number (base) to a given power (exponent), including negative or zero bases 
and/or exponents.
The order of two input integers is insignificant, i.e., main() automatically selects the greater integer to be 
the base and the little one to be the power. For example, for input of 5  2 or 2  5, it raises 5 to the power of 
2 with a result of 25.
No java built-in method like Math.exp() is used, instead, the main() calls the exp() method of a special class, 
USF_exp, defined next to do the exponent calculation.
The result must be displayed in one line and each data item must be tab-delimited. Below are two examples of 
output of main(). 
base = 5        power = 2        result = 25

base = 5        power = -2        result = 0.04

Invalid inputs will terminate the program but must be handled by main() at run time, including
if there is no integers or only one integer is provided in the command line, then the message below is displayed:
<ERROR> You must enter TWO integers.  Please re-run this program.

any non-zero or non-integer input will cause the message below to be displayed:
<ERROR> You must enter integers only.  Please re-run this program.*/


class FE1{
    public static void main(String[] args) {
        try {
            int base = 0;
            int power = 0;
            int item1 = Integer.parseInt(args[0]);
            int item2 = Integer.parseInt(args[1]);
            if(item1 > item2){
                base = item1;
                power = item2;
            }
            else{
                base = item2;
                power = item1;
            }
            USF_exp exps = new USF_exp();
            exps.USF_exp(base, power);
            double value = exps.exp();
            System.out.println("Base = " + base + " Power = " + power + " Result = " + value);        
        } catch (IndexOutOfBoundsException e){
            System.out.println("<ERROR> You must enter TWO integers.  Please re-run this program.");
        } catch (NumberFormatException e){
            System.out.println("<ERROR> You must enter integers only.  Please re-run this program.");
        }   
    }
}