import java.util.ArrayList;

public class ArrayListExercises1 {
  public static void arrayListSwapper(ArrayList<String> data, String obj1, String obj2){
    System.out.println("Swapping!!!!");
    int index1 = data.indexOf(obj1);
    int index2 = data.indexOf(obj2);
    data.remove(obj1);
    data.remove(obj2);
    data.add(index1,obj2);
    data.add(index2,obj1);
  }

  public static void main(String[] args) {
    ArrayList<String> colors = new ArrayList<String>();
    colors.add("Blue");
    colors.add("Orange");
    colors.add("Purple");
    int index = colors.indexOf("Orange");
    colors.remove(index);
    colors.add(index,"Green");
    colors.add("Red");
    colors.add("White");    
    System.out.println(colors);
    arrayListSwapper(colors, "Green", "Red");
    System.out.println(colors);
  }
}