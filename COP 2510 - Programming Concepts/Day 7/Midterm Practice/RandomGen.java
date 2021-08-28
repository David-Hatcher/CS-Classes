package midterm.classes;

import java.util.Random;

public class RandomGen{
    private Random rand = new Random();

    public int randInt(int minimum, int maximum){
        return rand.nextInt((maximum - minimum) + 1) + minimum;
    }
}