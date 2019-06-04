class car{
	private int year, mileage;
	private String make, model;
	private double price;
	public car(int yr, int miles, String mk, String md, double p){
		year = yr;
		mileage = miles;
		make = mk;
		model = md;
		price = p;
	}
	public int getYear(){
		return year;
	}
	public int getMileage(){
		return mileage;
	}
	public String getMake(){
		return make;
	}
	public String getModel(){
		return model;
	}	
	public double getPrice(){
		return price;
	}
	public void setPrice(double newPrice){
		price = newPrice;
	}	
	public boolean compare(car c){
		boolean same = false;
		if (this.year == c.getYear() &&
			this.mileage == c.getMileage() &&
			this.make.equals(c.getMake()) &&
			this.model.equals(c.getModel()))
			same = true;
		return same;
	}
	public void print(){
		System.out.println(year + " - " + mileage + " - " + make + " - " + model + " - " + price);
	}
}
	
public class twoClasses{   
    public static void main(String args[]) { 
		car c1 = new car(Integer.parseInt(args[0]), Integer.parseInt(args[1]), 
							args[2], args[3], Double.parseDouble(args[4]));
		car c2 = new car(Integer.parseInt(args[5]), Integer.parseInt(args[6]), 
							args[7], args[8], Double.parseDouble(args[9]));
		
        System.out.println("\nBefore price change:");
		c1.print();
		c2.print();
		
		//set price to the higher one if both cars are in same condition
		if (c1.compare(c2)){
			if (c1.getPrice() > c2.getPrice())
				c2.setPrice(c1.getPrice());
			else
				c1.setPrice(c2.getPrice());
			System.out.println("\nAfter price change:");
			c1.print();
			c2.print();
		}
		else
			System.out.println("\nNo price change--cars of different conditions");
		

    } 
} 