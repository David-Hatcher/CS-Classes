import java.util.ArrayList;
import java.util.Scanner;

public class PrimeFactorization {
  static ArrayList<Integer> primes = new ArrayList<>();
  static ArrayList<Integer> primesFinal = new ArrayList<>();

  public static void main(String args[]) {
    System.out.println("Enter the number to factorize into primes.");
    Scanner sc = new Scanner(System.in);
    int number = sc.nextInt();
    allPossiblePrimes(number);
  }

  public static void allPossiblePrimes(int number) {
    if (number == 0 || number == 1) {
      System.out.println("No primes can be found.");
    } else {
      for (int i = number; i > 1; i--) {
        boolean isPrime = true;
        for (int x = 2; x < i - 1; x++) {
          if (i % x != 0.0) {

          } else {
            isPrime = false;
          }
        }
        if (isPrime) {
          primes.add(i);
        }
      }
    }
    divisiblePrimes(number);
  }

  public static void divisiblePrimes(int number) {
    for (int i = 0; i < primes.size(); i++) {
      if (number % primes.get(i) == 0) {
        int temp2 = number / primes.get(i);
        primesFinal.add(primes.get(i));
        primesFinal.add(temp2);
      }
    }
    System.out.println("Prime Mulitples of " + number + ".");
    for (int multiple : primesFinal) {
      System.out.print(multiple + ",");
    }
  }
}