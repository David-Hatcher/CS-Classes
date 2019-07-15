class Day18{
    public static void main(String[] args) {
    A a = new B();
    // B b = new B();
    // a = b;
    System.out.println(a.toString());        
    }

}
class A{
    public String toString(){return "";}
}
class B extends A{
    public String toString(){return "new";}
}