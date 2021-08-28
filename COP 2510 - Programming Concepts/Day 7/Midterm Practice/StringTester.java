package midterm.classes;

public class StringTester{
    public static void main(String[] args) {
        Printer po = new Printer();
        String bullshit = "This string is mutable.";
        bullshit += "!";
        po.Print(bullshit);
    }
}