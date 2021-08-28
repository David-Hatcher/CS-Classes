class A {
    public void show(){
        System.out.print("A");
    }
}

class B extends A {
    @Override
    public void show(){
        System.out.print("B");
    }
}

class Final { 
    public static void main(String args[]) {
        A a = new B();
        a.show();
        ((B)a).show();
        B b = (B)a;
        b.show();
    }
}