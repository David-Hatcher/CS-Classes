package COP2510.library;
/*It defines a package of COP2510.library
It contains two private integer fields: base and power.
It uses a constructor to set value to its two fields. It always chooses the bigger one for base
 and the smaller one for power.
Besides the constructor, it provides only one method called exp() for exponent calculation.
exp() method has no input parameters and returns the calculation result as a double type value.
exp() doesn't throw any exceptions and it doesn't handle any run-time exceptions, either.
exp() always results 1 for a power of zero, and it always results 0 for a base of zero.
exp() accepts negative base or power. For example, it raises a base of -2 to a power of 
-5 for a result of -(1/32) or -0.03125.*/


public class USF_exp{
    private int base;
    private int power;
    public void USF_exp(int item1, int item2){
        if(item1 > item2){
            base = item1;
            power = item2;
        }
        else{
            base = item2;
            power = item1;
        }
    }
    public double exp(){
        double value = (double)base;
        int powerAdjusted = power;
        if(powerAdjusted < 0){powerAdjusted = power*(-1);}
        for(int i = 1; i < powerAdjusted; i++){
            value = value*base;
        }
        if(power == 0){
            value =  1;
        }
        else if(base == 0){
            value = 0;
        }
        else if(power > 0){
            value =  (double)value;
        }
        else if(power < 0 ){
           value =  (double)(1/value);
        }

        return value;
    }
}