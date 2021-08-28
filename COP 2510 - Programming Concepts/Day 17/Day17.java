public class Day17{
    //UML is universal modeling language
    //used to model a program and it's classes
    

    //Inheritance
    //class B extends A{}
    //B is a child of A
    //class Pet{} has play() and feed()
    //class Cat extends Pet{} has chaseMouse()
    //class Dog extends Pet{} has chaseCat()
    //if class Pet has private String mood
    //it still cannot be accessed through cat.mood, it is still private from the pet
    
//             │ Class │ Package │ Subclass │ Subclass │ World
//             │       │         │(same pkg)│(diff pkg)│ 
// ────────────┼───────┼─────────┼──────────┼──────────┼────────
// public      │   +   │    +    │    +     │     +    │   +     
// ────────────┼───────┼─────────┼──────────┼──────────┼────────
// protected   │   +   │    +    │    +     │     +    │         
// ────────────┼───────┼─────────┼──────────┼──────────┼────────
// no modifier │   +   │    +    │    +     │          │    
// ────────────┼───────┼─────────┼──────────┼──────────┼────────
// private     │   +   │         │          │          │    

// + : accessible         blank : not accessible


//***********FINAL**********//
//Same format as midterm
//different number of questions
//test will be done in class
//next wednesday
//chapters: 1,9,10,11,14,16,17
//17 file I/O
//16 try and catch
//14 ArrayList, skip lambda
//11 Inheritance
//10 Arrays
//9 String and StringBuilder
//"What is JRE, what it does, why we need it","How does a java program compile, how to make it run",

//Child class can only have one Parent class
//C++ can do multi-Inheritance
//C# and Java cannot
//Interface can implement the mutli-Inheritance


//You can have the same variables in the child class
//@Override, on top of a method which duplicates a parent, makes it replace the parent classes method with the
//same name
//class Parent{
//private String sid;
//}
//class Child extends Parent{
//private int sid;                     This is okay because they're different data types and different classes as well as    
//}                                    Being private makes them invisible to child

//You can cast a subclass to a superclass but not a superclass to a subclass
//Cannot access a method from the subclass, unless it is overriding the superclass method
    public static void main(String[] args) {
        
    }
}