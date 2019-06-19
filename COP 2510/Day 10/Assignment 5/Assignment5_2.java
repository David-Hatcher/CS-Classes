import java.util.ArrayList;

@SuppressWarnings("unchecked")
public class Assignment5_2 {

  private static void print(String object){
    System.out.print(object);
  }

  private static void printTriangle(ArrayList<String>[] triangle, String methNum){    
    print("\ntriangle_" + methNum + "\n\n");
    for (ArrayList<String> line : triangle) {
      for (String part : line) {
        print(part);
      }
      print("\n");
    }     
  }

  private static void triangle_0(int totalLines){
    ArrayList<String>[] triangle = new ArrayList[totalLines];
    for(int i = 0; i < totalLines; i++){
      triangle[i] = new ArrayList<String>();
      for(int j = 0; j < totalLines; j++){
        if(i <= j){
          triangle[i].add("*");
        }
      }
    }
    printTriangle(triangle,"0");
 		// int lineCount = 0, widthCount = max;
		
		// System.out.println("\ntriangle_0\n");
		// while (lineCount <= max){
		// 	while (widthCount >= 1){
		// 		if (widthCount == 1)
		// 			System.out.println("*");//move to new line after print, if it is the last "*" of the line
		// 		else
		// 			System.out.print("*");
		// 		widthCount = widthCount - 1;
		// 	}
		// 	lineCount = lineCount + 1;
		// 	widthCount = max - lineCount;
		// }
  }

  private static void triangle_1(int totalLines,String printChar){
    ArrayList<String>[] triangle = new ArrayList[totalLines];
    for(int i = 0; i < totalLines; i++){
      triangle[i] = new ArrayList<String>();
      for(int j = 0; j < totalLines; j++){
        if(i <= j){
          triangle[i].add(printChar);
        }
      }
    }
    printTriangle(triangle,"1");
    // int lineCount = 0, widthCount = max;
		
		// System.out.println("\ntriangle_1\n");
		// while (lineCount <= max){
		// 	while (widthCount >= 1){
		// 		if (widthCount == 1)
		// 			System.out.println(character);
		// 		else
		// 			System.out.print(character);
		// 		widthCount = widthCount - 1;
		// 	}
		// 	lineCount = lineCount + 1;
		// 	widthCount = max - lineCount;
		// }
  }

  private static void triangle_2(int totalLines){
    ArrayList<String>[] triangle = new ArrayList[totalLines];
    for(int i = 0; i < totalLines; i++){
      triangle[i] = new ArrayList<String>();
      for(int j = 0; j < totalLines; j++){
        if(i <= j){
          triangle[i].add(Integer.toString(totalLines-i));
        }
      }
    }
    printTriangle(triangle,"2");  
    // 		int lineCount = 0, widthCount = max;
		
		// System.out.println("\ntriangle_2\n");
		// int currentPrint = max;
		// while (lineCount <= max){			
		// 	while (widthCount >= 1){
		// 		if (widthCount == 1)
		// 			System.out.println(currentPrint);
		// 		else
		// 			System.out.print(currentPrint);
		// 		widthCount = widthCount - 1;
		// 	}
		// 	currentPrint--;
		// 	lineCount = lineCount + 1;
		// 	widthCount = max - lineCount;
		// }
  }

  private static void triangle_3(int totalLines){
    ArrayList<String>[] triangle = new ArrayList[totalLines];
    for(int i = 0; i < totalLines; i++){
      triangle[i] = new ArrayList<String>();
      for(int j = 0; j < totalLines; j++){
        if(i <= j){
          triangle[i].add(Integer.toString(totalLines-j));
        }
      }
    }
    printTriangle(triangle,"3");
    // int lineCount = 0, widthCount = max;
		
		// System.out.println("\ntriangle_3\n");
		// while (lineCount <= max){
		// 	while (widthCount >= 1){
		// 		if (widthCount == 1)
		// 			System.out.println("1");
		// 		else
		// 			System.out.print(widthCount);
		// 		widthCount = widthCount - 1;
		// 	}
		// 	lineCount = lineCount + 1;
		// 	widthCount = max - lineCount;
		// }
  }

  private static void triangle_4(int totalLines,String printChar){
    ArrayList<String>[] triangle = new ArrayList[totalLines];
    int i = 0;
    while(i < totalLines){
      int j = 0;
      triangle[i] = new ArrayList<String>();
      while(j < totalLines){
        if(i >= j){
          triangle[i].add(printChar);
        }
        j++;
      }
      i++;
    }
    printTriangle(triangle,"4");  
    // int widthCount = 0;

		// System.out.println("\ntriangle_4\n");
		// for(int i = widthCount; i < max; i++){
		// 	for(int j = 0; j <= i; j++){
		// 		System.out.print(character);
		// 	}
		// 	System.out.println();
		// }	
  }

  private static void triangle_5(int totalLines){
    ArrayList<String>[] triangle = new ArrayList[totalLines];
    int i = 0;
    while(i < totalLines){
      int j = 0;
      triangle[i] = new ArrayList<String>();
      while(j < totalLines){
        if(i >= j){
          triangle[i].add(Integer.toString(i+1));
        }
        j++;
      }
      i++;
    }
    printTriangle(triangle,"5");  
    // int widthCount = 1;

		// System.out.println("\ntriangle_5\n");
		// for(int i = widthCount; i <= max; i++){
		// 	for(int j = 0; j < i; j++){
		// 		System.out.print(i);
		// 	}
		// 	System.out.println();
		// }
  }

  private  static void triangle_6(int totalLines){
    ArrayList<String>[] triangle = new ArrayList[totalLines];
    int i = 0;
    while(i < totalLines){
      int j = 0;
      triangle[i] = new ArrayList<String>();
      while(j < totalLines){
        if(i >= j){
          triangle[i].add(Integer.toString(j+1));
        }
        j++;
      }
      i++;
    }
    printTriangle(triangle,"6");
    // int widthCount = 1;

		// System.out.println("\ntriangle_6\n");
		// for(int i = widthCount; i <= max; i++){
		// 	for(int j = 1; j <= i; j++){
		// 		System.out.print(j);
		// 	}
		// 	System.out.println();
		// }
  }
  public static void main(String args[]) { 
    int totalLines = Integer.parseInt(args[0]);
    String printChar = args[1];
    triangle_0(totalLines);
    triangle_1(totalLines, printChar);
    triangle_2(totalLines);
    triangle_3(totalLines);
    triangle_4(totalLines, printChar);
    triangle_5(totalLines);
    triangle_6(totalLines);
  } 
}