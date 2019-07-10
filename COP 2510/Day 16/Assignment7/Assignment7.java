import java.io.*;
import java.nio.file.*;
import java.util.ArrayList;
import java.util.Arrays;


class ReadFile {
    PrintHelper ph = new PrintHelper();
    public ArrayList<ArrayList<String>> readOrdersFile(String fileName){
        File filePath = new File ("../Ass7_Data/" + fileName);
        ArrayList<ArrayList<String>> lineItems = new ArrayList<ArrayList<String>>();
        try {
            int lineCount = 0;
            BufferedReader input = new BufferedReader(
                                    new FileReader(filePath));
            String currentLine = input.readLine();
            while(currentLine != null){
                lineCount++;
                ArrayList<String> currentItem = new ArrayList<String>();
                String[] currentLines = currentLine.split("\t");
                for (String line : currentLines) {
                    currentItem.add(line);
                }
                lineItems.add(currentItem);
                currentLine = input.readLine();
            }
            input.close();
            ph.PrintLn("File " + filePath.toString() + " is read successfully with " + lineCount + " lines\n");
        } catch (IOException e) {
            // ph.PrintLn("......No file of " + filePath.toString() + " can be found.\n" +
            // "Please check if such a file exists and re-run this program\n\n" +
            // ".....Reading " + fileName + " failed\n\n");
        }
        return lineItems;
    }
    public ArrayList<String> readCustomersFile(String fileName){
        ArrayList<String> customers = new ArrayList<String>();
        File filePath = new File ("../Ass7_Data/" + fileName);
        try {
            int customersCount = 0;
            BufferedReader input = new BufferedReader(
                                    new FileReader(filePath));
            String customerCurrent = input.readLine();
            while(customerCurrent != null){
                customersCount++;
                customers.add(customerCurrent);
                customerCurrent = input.readLine();
            }
            input.close();
            ph.PrintLn("File " + filePath.toString() + " is read successfully with " + customersCount + " lines\n");
        } catch (IOException e) {
            // ph.PrintLn("......No file of " + filePath.toString() + " can be found.\n" +
            // "Please check if such a file exists and re-run this program\n\n"+
            // ".....Reading " + fileName + " failed\n\n");
        }
        return customers;
    }
    public int getLineCount(File filePath){
        int lines = 0;
        try {
            BufferedReader input = new BufferedReader(
                                    new FileReader(filePath));
            while(input.readLine() != null){
                lines++;
            }
            input.close();
        } catch (IOException e) {
            ph.PrintLn("File Doesn't exist!!!!!");
        }
        return lines;
    }
}
class WriteFile{
    PrintHelper ph = new PrintHelper();
    ReadFile rf = new ReadFile();
    public void writeSIMCFile(ArrayList<ArrayList<String>> data){
        File filePath = new File ("../Ass7_Data/SIMC.txt");
        int previousLines = 0;
        try {
            if(!filePath.exists()){
                filePath.createNewFile();
            }
            else{
                previousLines = rf.getLineCount(filePath);
                FileWriter clearing = new FileWriter(filePath);
                clearing.close();
            }
            PrintWriter output = new PrintWriter(
                new BufferedWriter(
                new FileWriter(filePath,true)));
            for (ArrayList<String> line : data) {
                String simcLine = "";
                for (String info : line) {
                    simcLine += info + "\t";
                }
                output.println(simcLine);
            }
            output.close();
            ph.PrintLn("File " + filePath.toString() + " is created (" + data.size() + " lines) but only " + (data.size()-previousLines) + " are updated");
        } catch (IOException e) {
            System.out.println("Something went wrong with writing " + e.getMessage());
        }
    }
}
class Orders{
    private ArrayList<ArrayList<String>> custOrderVal = new ArrayList<ArrayList<String>>();
    private ArrayList<String> customersThatDidNotOrder = new ArrayList<String>();
    private double highestValue = 0;
    private double lowestValue = 1.0/0.0;
    private int orderCount;
    private int customersOrderedCount = 0;
    private String highestValueCustomer;
    private String highestValueOrder;
    private String lowestValueCustomer;
    private String lowestValueOrder;

    public String getOrderCount(){
        return "\t(Q2) Total Orders in orders file = " + orderCount + "\n";
    }    
    public String getHighestValue(){
        return "\t(Q4) Largest order = " + highestValue + ", which is order " + highestValueOrder + " of customer " + highestValueCustomer + "\n";
    }
    public String getLowestValue(){
        return "\t(Q5) Smallest order = " + lowestValue + ", which is order " + lowestValueOrder + " of customer " + lowestValueCustomer + "\n";
    }
    public void compileOrders(ArrayList<ArrayList<String>> data){
        ArrayList<String> orders = new ArrayList<String>();
        ArrayList<String> values = new ArrayList<String>();
        ArrayList<String> customers = new ArrayList<String>();
        for (ArrayList<String> lineItem : data) {
            double price = Double.parseDouble(lineItem.get(18));
            double quantity = Double.parseDouble(lineItem.get(19));
            double discount = (1-Double.parseDouble(lineItem.get(20)));
            String currentAdd;
            if(orders.contains(lineItem.get(11))){
                int index = orders.indexOf(lineItem.get(11));
                double previousValue = Double.parseDouble(values.remove(index));
                currentAdd = Double.toString(discount*quantity*price + previousValue);
                values.add(index,currentAdd);
            }
            else{
                customers.add(lineItem.get(0));
                orders.add(lineItem.get(11));
                currentAdd = Double.toString(discount*quantity*price);
                values.add(currentAdd);                
            }
        }
        combineLists(customers, orders, values);
    }
    private void combineLists(ArrayList<String> customers, ArrayList<String> orders, ArrayList<String> values){
        ArrayList<ArrayList<String>> cov = new ArrayList<ArrayList<String>>();
        for(int i = 0; i < orders.size(); i++){
            ArrayList<String> covCurrent = new ArrayList<String>();
            covCurrent.add(customers.get(i));
            covCurrent.add(orders.get(i));
            covCurrent.add(values.get(i));
            cov.add(covCurrent);
        }
        orderCount = cov.size();
        custOrderVal = cov;
    }
    public void findHighestAndLowestOrder(){
        for (ArrayList<String> order : custOrderVal) {
            String currentCustomer = order.get(0);
            String currentOrder = order.get(1);
            double currentValue = Double.parseDouble(order.get(2));
            if(currentValue > highestValue){
                highestValue = currentValue;
                highestValueOrder = currentOrder;
                highestValueCustomer = currentCustomer;
            }
            else if(currentValue < lowestValue){
                lowestValue = currentValue;
                lowestValueOrder = currentOrder;
                lowestValueCustomer = currentCustomer;
            }
        }
    }
    public void findCustomersWithoutOrders(ArrayList<String> data){
        for (String customer : data) {
            boolean didCustomerOrder = false;
            for (ArrayList<String> order : custOrderVal) {
                if(order.contains(customer)){
                    didCustomerOrder = true;
                    customersOrderedCount++;
                    break;                   
                }
            }
            if(didCustomerOrder == false){
                customersThatDidNotOrder.add(customer);
            }
        }
    }
    public String getCustomersOrderedCount(){
        return "\t(Q1) Total customers in orders file = " + customersOrderedCount + "\n";
    }
    public String getCustomersWhoDidNotOrder(){
        String noOrdersCust =  "\t(Q3) " + customersThatDidNotOrder.size() + " customers with no orders = ";
        for (String customer : customersThatDidNotOrder) {
            noOrdersCust += customer + "   ";
        }
        noOrdersCust+= "\n";
        return noOrdersCust;
    }
    public ArrayList<ArrayList<String>> createSIMCOrders(ArrayList<ArrayList<String>> data){
        ArrayList<String> countries = new ArrayList<String>(Arrays.asList("Spain","Mexico","Italy","Canada"));
        ArrayList<ArrayList<String>> simc = new ArrayList<ArrayList<String>>();
        for (ArrayList<String> line : data) {
            if(countries.contains(line.get(8))){
                ArrayList<String> simcLine = new ArrayList<String>();
                simcLine.add(line.get(0));//CustomerID
                simcLine.add(line.get(8));//Country
                simcLine.add(line.get(11));//OrderID
                simcLine.add(line.get(12));//OrderDate
                simcLine.add(line.get(17));//ProductID
                simcLine.add(line.get(18));//UnitPrice
                simcLine.add(line.get(19));//Quantity
                double discount = Double.parseDouble(line.get(20));
                if(discount == 0.0){
                    discount = 0.3;
                }
                else if(discount > .2){
                    discount -= 0.1;
                }
                simcLine.add(Double.toString(discount));
                simc.add(simcLine);
            }
        }
        return simc;
    }  
}
class PrintHelper{
    public void PrintLn(Object message){
        System.out.println(message);
    }
}
public class Assignment7{
    static PrintHelper ph = new PrintHelper();
    static Orders ord = new Orders();
    static ReadFile rf = new ReadFile();
    static WriteFile wf = new WriteFile();  
    private static void runProgram(ArrayList<ArrayList<String>> ordersList, ArrayList<String> customersList, ArrayList<ArrayList<String>> simcList){   
        ord.compileOrders(ordersList);
        ord.findHighestAndLowestOrder();
        ord.findCustomersWithoutOrders(customersList);
        ph.PrintLn(ord.getCustomersOrderedCount());
        ph.PrintLn(ord.getOrderCount());
        ph.PrintLn(ord.getCustomersWhoDidNotOrder());
        ph.PrintLn(ord.getHighestValue());
        ph.PrintLn(ord.getLowestValue());
        wf.writeSIMCFile(simcList); 
    }
    public static void main(String[] args) {
        ph.PrintLn("\n--------begin of Assignment 7--------\n");        
        if(args.length < 2){
            ph.PrintLn(".....Did you forget to enter 2 file names at command line?");
            ph.PrintLn("Please re-run this program\n");
        }
        else{
            try {
                ArrayList<ArrayList<String>> ordersList = rf.readOrdersFile(args[0]);
                if(ordersList.size() == 0){throw new IOException(args[0]);}
                ArrayList<String> customersList = rf.readCustomersFile(args[1]);
                if(customersList.size() == 0){throw new IOException(args[1]);}
                ArrayList<ArrayList<String>> simcList = ord.createSIMCOrders(ordersList);
                runProgram(ordersList,customersList,simcList);
            } catch (IOException e) {
                ph.PrintLn("......No file of ../Ass7_data/" + e.getMessage() + " can be found.\n" +
                "Please check if such a file exists and re-run this program\n\n"+
                ".....Reading " + e.getMessage() + " failed\n");                
            }  
        }
        ph.PrintLn("--------end of Assignment 7--------");
    }
}