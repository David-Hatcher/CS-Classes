/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package USF.CSE;

import java.util.Random; 
/**
 *
 * @author fang1
 */
public class GetRandom2 {
    public static void main(String args[]) { 
        // create 'r' as an instance of Random class 
        Random r = new Random(); 
  
        // Generate and print 2 random integers in range 0 to 4
        float rand_1 = r.nextFloat(); 
        float rand_2 = r.nextFloat(); 
	System.out.println(rand_1 + ", " + rand_2);
		
        // Compare and print result 
        if (rand_1 > rand_2)
            System.out.println("A"); 
        else if (rand_1 < rand_2)
            System.out.println("B");
        else
            System.out.println("C");
    } 
}
