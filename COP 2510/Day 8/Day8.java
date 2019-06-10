import java.util.*;

public class Day8{
    int x = 0; //field
    public static void main(String[] args) {
        int x1 = 0; //local variable, any statement in this block can see this
        //this is the scope
        while(true){
            int x2 = 0;//scope is only in this while loop, nothing outside of this loop can see x2
            x1++;//the scope here is not within this while loop, can be used outside of loop
        }
        //System.out.println(x2);//This will not work
    }
}

class Student{
    private double GPA; //field
    private String y = "!!!!!";//Any method in this class can use this value    "Global Variable"
    
    public double getGPA(){
        String y = ".....";//Scope limited to this method
        return GPA;
    }
}

class Loops{
    
    private boolean quit = true;
    private void DoSomething(){}
    public void LoopingWhile(){
        while(true){
            if(quit){break;} //this will stop entire loop
            else{continue;}  //this will stop current iteration and start next
        }
    }
    public void LoopingFor(){
        int someValue = 100;
        for(int i = 0; i < someValue; i++, someValue--){//(a value; a stop condition; an iteration statement){some statements}
            DoSomething();
        }
    }
    public void LoopingDoWhile(){
        do{
            DoSomething();
        }while(true);//This checks for conditions a the end of the loop, therefor this will always run at least once
    }
}

class Conditionals{
    int condition = 0;
    private void DoSomething(){}
    private void DoSomethingElse(){}
    public void ifElse(){
        if(condition ==0){//this is basically the same thing as the switch case below...
            DoSomething();
        }
        else if(condition == 1){
            DoSomething();
        }
        else{
            DoSomethingElse();
        }
    }
    public void SwitchCases(){
        switch(condition){//tells the switch what do check the cases against, switch does not allow boolean statements
            case 0:{//If the condition is == 0 then run this one
                DoSomething();
                break;//must have a break or it'll run everything else too
            }
            case 1:{//if the condition is == 1 then run this one
                DoSomething();
                break;//break needed to stop switch
            }
            default :{//if the conditon matches none of the cases then this will run, effectively an else statement
                DoSomethingElse();
                break;//must have break here too
            }
        }
    }
    
}
public class String{
    String s = "This is the state of florida";
    //indexOf goes first to last
    //lastIndexOf goes last to first
    int value = s.indexOf("is",1);// value = 2, starts from value 1
    int value_2 = s.lastIndexOf("is",8);//value_2 = 5, starts from index value 8 of the string
    //these can both be done without a second parameter
    String s2 = s.substring(value); //"is is the state of florida"
    String s3 = s.substring(value, value_2);//"is " the second value is excluding while the first is including

}