import java.util.Scanner;
import java.util.ArrayList;

import javax.swing.*;
import java.awt.GridLayout;
import java.awt.Color;

class InputException extends Exception{
  String msg;
  public InputException(String msg){
    this.msg = msg;
  }
  
  public String getMessage(){
    return this.msg;
  }
}

public class GUI{
  private static JFrame frame;
 
  public static void main(String[] args){
    Scanner read = new Scanner(System.in);
    int lower, upper;
    
    try{
      System.out.print("Enter lower (positive) integer value: ");
      lower = read.nextInt();
      System.out.print("Enter upper (positive) integer value: ");
      upper = read.nextInt();
      read.close();
      
      if(lower > upper)
        throw new InputException("Error. Lower value must be less than upper value.");
      if(lower < 0 || upper < 0)
        throw new InputException("Error. Entries must be positive numbers.");
      
      // set criterion for scalling grid layout
      int normed = (int) Math.ceil((int)(Math.sqrt(upper)));
      // initialize GUI layout features
      frame = new JFrame("GUI");
      frame.setDefaultCloseOperation(frame.EXIT_ON_CLOSE);
      frame.setSize(500,500);
      frame.setLayout(new GridLayout(normed, normed));

      ArrayList<Integer> primes = new ArrayList<Integer>();
      sieve(primes, upper);
      display(primes, lower, upper);
      
    } catch(InputException iexp){
      System.err.print(iexp.getMessage());
    }
  }
  
  private static void sieve(ArrayList<Integer> primes, int size){
    //initialize
    for(int i = 0; i< size; i++)
        primes.add(i,i);
    
    // find primes
    for(int i = 2; i*i < primes.size(); i++){
      if(primes.get(i) != 0)
        for(int j = i*i; j < primes.size(); j += i)
           primes.set(j,0);
    }
    
    // filter zeroes
    ArrayList <Integer> zeros = new ArrayList<Integer>();
    zeros.add(0);
    primes.removeAll(zeros);
    
  }
  
  private static void display(ArrayList<Integer> primes, int lower, int upper){
    for(int i = lower; i <= upper; i++){
      JButton button = new JButton(String.valueOf(i));
      
      button.setBackground(Color.BLUE);
      
      for(int j = 0; j < primes.size(); j++){
        if(i == primes.get(j))
          button.setBackground(Color.GREEN);
      }
      
      frame.add(button);
      button.setOpaque(true);
    }
    
    frame.setVisible(true);
  }
  
}