// unitTest Me

package me.java;

class unitTest
{
	public static void main(String args[])
	{
		long val20 = 2432902008176640000L;
		me.java method = new me.java();
		if (method.factorial(20) == val20)
		{
			System.out.println("Test works for 20");
		}
		else
		{
			System.out.println("Test Failed on 20");
		}
	}
}