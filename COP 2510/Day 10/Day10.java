import java.util.ArrayList;

/*Notes from day 10
How to work with collections, generics and lambdas*/
//collections, resizeable, dynamic.
// List -> ArrayList, LinkedList
// Set -> HashSet
//List, set,collection, and map are interface.......ArrayList, LinkedList, Hashset, HashMap, TreeMap are classes
//generics
//ArrayList Methods
//clear(), contains(object),indexOf(object), isEmpty(), remove(index), remove(object), set(index,object), toArray()

public class Day10{
    public static void main(String[] args) {
        ArrayList<String> codes = new ArrayList<String>();
        //ArrayList.add(index,object);
        codes.add("jsp");
        codes.add("mysql");
        codes.add(0,"java");
        String codeRemoved = codes.remove(2);
        codes.set(1,"android");
        for (String code : codes) {
            System.out.println(code);
        }
        System.out.println(codes);
    }
}