class student{    
    public void print(String s){
        System.out.println(s + " student details.");
    }
    public void hello(String s){
        System.out.println(s + " says hello!");
    }
}
class undergraduate_student extends student{
    public void print(String s){
        super.print(s);
        System.out.println(s + " undergraduate_student details.");
    }
}
class graduate_student extends student{
    public void print(String s){
        System.out.println(s + " graduate_student details.");
    }
    public void hello(){
        System.out.println("Hello Hello");
    }
}

public class Day16{
    //Super Object class methods
    //.equals(Object o);
    //.toString(Object o);
    //************Encapsulation//
    //************Inheritance//
    //Assignment7
    //Parent Class > Child Class
    //Base > Derived 
    //Superclass > Subclass
    //protected means can be seen by any subclasses of this class
    //this is like private but only for subclasses of this class and subclasses of those

    //super.method()
    //This makes it refer to the parent method of the same name
    //and calls that method from the parent class.

    //************Polymorphism//
    //All because of inheritance
    //.toString is avail for every object unless you make your own.
    //it returns the class name followed by a unique hash id
    //Polymorphism is a feature of inheritance that lets you treat objects of different subclassses 
    //that are derived from the same superclass as if they had the type of the superclass
    //s is software which is child of product class
    //b is book which is child of product class
    //if I create product p variabe
    //p = s and p = b are both viable
    //so both s and b are product classes as well as software and book

    public static void main(String[] args) {
        undergraduate_student peter = new undergraduate_student();
        graduate_student lisa = new graduate_student();
        student john = new undergraduate_student();

        john.print("john");
        peter.print("peter");
        lisa.print("lisa");

        System.out.println();

        john.hello("john");
        peter.hello("peter");
        lisa.hello("lisa");
        lisa.hello();
    }
}