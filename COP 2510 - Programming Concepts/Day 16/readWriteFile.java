import java.util.*;
import java.io.*;
import java.nio.file.*;

class student {
	private String sid;
	private String major;
	private double gpa;
	public static int totalStudent = 0;
	public student(String id, String mj, double g){
		sid = id;
		major = mj;
		gpa = g;
		++totalStudent;
	}
	public double getGPA(){
		return gpa;
	}
	public String details(){
		return "SID: " + sid + "\tMajor: " + major + "\tGPA: " + gpa;
	}
} // end of student


class readWriteFile {
	public static void main(String args[]) {
		ArrayList<student> allStudents = openFile("students.txt");
		printStudents(allStudents);
		averageGPA(allStudents);
		if (addNewStudent("students.txt", allStudents, "U501", "EE", 4.0)) {
			printStudents(allStudents);
			averageGPA(allStudents);
		}
		System.out.println("\n\n--------end of readWriteFile----------");
	} // end of main
	
	private static ArrayList<student> openFile(String fileName){
		ArrayList<student> studentsFound = new ArrayList<>();
		Path myPath = Paths.get(fileName);
		File myFile = myPath.toFile();

        if (Files.exists(myPath)) {
            try (BufferedReader input = new BufferedReader(
                                     new FileReader(myFile))) {
                // read all students stored in the file into the array list
                String line = input.readLine();
                while(line != null) {
                    String[] columns = line.split(",");
                    String sid = columns[0];
                    String major = columns[1];
                    double gpa = Double.parseDouble(columns[2]);

                    student s = new student(sid, major, gpa);
                    studentsFound.add(s);

                    line = input.readLine();                    
                }
				System.out.println("\n.....File " + fileName + " is accessed with " + 
					student.totalStudent + " students read successfully");
            }
            catch(IOException e) {
                System.out.println(e);
                return null;
            }			 
        } // end of if
		return studentsFound;
	} // end of openFile
	
	private static void printStudents(ArrayList<student> all){
		System.out.println();
		for (student s : all)
			System.out.println(s.details());
	} // end of printStudents
	
	private static void averageGPA(ArrayList<student> all){
		double totalGPA = 0, avgGPA = 0;
		for (student s : all)
			totalGPA += s.getGPA();
		System.out.printf("\nAverage GPA = %05.3f\n", totalGPA/student.totalStudent);
	} // end of averageGPA	
	
	private static boolean addNewStudent(String fileName, ArrayList<student> all, String u, String m, double g){	
		student newStudent = new student(u, m, g);
		all.add(newStudent);
		Path myPath = Paths.get(fileName);
		File myFile = myPath.toFile();
		if (Files.exists(myPath)) {
            try (PrintWriter go = new PrintWriter(
									new BufferedWriter(
									  new FileWriter(myFile, true)))) { // 'true' to append
                // append the new student to the file 
				go.print(u + "," + m + ",");
				go.println(g);
				System.out.println("\n.....File " + fileName + " is accessed to add the new student successfully");
			}
            catch(IOException e) {
                System.out.println(e);
				return false;
            }
		} // end of if
		return true;
	} // end of addNewStudent
} // end of readWriteFile class