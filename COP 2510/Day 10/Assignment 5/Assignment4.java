public class Assignment4 {  
	//the main() is completed, so please do not change any part of it
    public static void main(String args[]) { 
		int totalLines = Integer.parseInt(args[0]);
		
		triangle_0(totalLines);
		
		triangle_1(totalLines, args[1]);
		triangle_2(totalLines);
		triangle_3(totalLines);
		triangle_4(totalLines, args[1]);
		triangle_5(totalLines);
		triangle_6(totalLines);
    } 
	
	//-triangle_0() below is the one already presented in class
	//-you may use it to modify to implement the other 6 methods
	private static void triangle_0(int max){
		int lineCount = 0, widthCount = max;
		
		System.out.println("\ntriangle_0\n");
		while (lineCount <= max){
			while (widthCount >= 1){
				if (widthCount == 1)
					System.out.println("*");//move to new line after print, if it is the last "*" of the line
				else
					System.out.print("*");
				widthCount = widthCount - 1;
			}
			lineCount = lineCount + 1;
			widthCount = max - lineCount;
		}
	}

	// implement each method here, including triangle_1, triangle_2, ...., triangle_6


	private static void triangle_1(int max, String character){
		int lineCount = 0, widthCount = max;
		
		System.out.println("\ntriangle_1\n");
		while (lineCount <= max){
			while (widthCount >= 1){
				if (widthCount == 1)
					System.out.println(character);
				else
					System.out.print(character);
				widthCount = widthCount - 1;
			}
			lineCount = lineCount + 1;
			widthCount = max - lineCount;
		}
	}
	private static void triangle_2(int max){
		int lineCount = 0, widthCount = max;
		
		System.out.println("\ntriangle_2\n");
		int currentPrint = max;
		while (lineCount <= max){			
			while (widthCount >= 1){
				if (widthCount == 1)
					System.out.println(currentPrint);
				else
					System.out.print(currentPrint);
				widthCount = widthCount - 1;
			}
			currentPrint--;
			lineCount = lineCount + 1;
			widthCount = max - lineCount;
		}
	}
	private static void triangle_3(int max){
		int lineCount = 0, widthCount = max;
		
		System.out.println("\ntriangle_3\n");
		while (lineCount <= max){
			while (widthCount >= 1){
				if (widthCount == 1)
					System.out.println("1");
				else
					System.out.print(widthCount);
				widthCount = widthCount - 1;
			}
			lineCount = lineCount + 1;
			widthCount = max - lineCount;
		}
	}
	private static void triangle_4(int max, String character){
		int widthCount = 0;

		System.out.println("\ntriangle_4\n");
		for(int i = widthCount; i < max; i++){
			for(int j = 0; j <= i; j++){
				System.out.print(character);
			}
			System.out.println();
		}		
	}
	private static void triangle_5(int max){
		int widthCount = 1;

		System.out.println("\ntriangle_5\n");
		for(int i = widthCount; i <= max; i++){
			for(int j = 0; j < i; j++){
				System.out.print(i);
			}
			System.out.println();
		}
	}
	private static void triangle_6(int max){
		int widthCount = 1;

		System.out.println("\ntriangle_6\n");
		for(int i = widthCount; i <= max; i++){
			for(int j = 1; j <= i; j++){
				System.out.print(j);
			}
			System.out.println();
		}
	}
	
		
} 