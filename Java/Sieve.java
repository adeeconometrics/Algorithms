import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;

public class Sieve{
    public static void main(String[] args){
        Scanner read = new Scanner(System.in);
        System.out.println("Enter two positive intgers: ");
        int low = read.nextInt();
        int high = read.nextInt();
        read.close();

        ArrayList<Integer> primes = new ArrayList<Integer> ();
        sieve(primes, high);

        System.out.print(String.valueOf(primes)+ "\nsize: " + primes.size());            

    }

    private static void sieve(ArrayList<Integer> primes, int size){
        for(int i = 0; i< size; i++)
            primes.add(i,i);
        
        for(int i = 2; i*i < primes.size(); i++){
            if(primes.get(i) != 0){
                for(int j = i*i; j < primes.size(); j+= i)
                    primes.set(j,0);
            }
        }

        System.out.println("inside: " + String.valueOf(primes));

        ArrayList <Integer> zeros = new ArrayList<Integer>();
        zeros.add(0);

        primes.removeAll(zeros);
    }

//    private static int[] removeZeros(ArrayList<Integer> primes){
//      int non_zero = 0;
//      for(int i = 0; i < primes.length; i++)
//        if(primes[i] != 0) 
//          ++non_zero;
        
//      ArrayList<Integer> reduced_primes = new int[non_zero];
//      int j = 0;
        
//      for(int i = 0; i < primes.length; i++){
//          if(primes[i] != 0){
//            reduced_primes[j] = primes[i];
//            ++j;
//          }
//       }
     
//      return reduced_primes;
//    }
} 