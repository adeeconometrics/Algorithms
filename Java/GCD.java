import java.util.InputMismatchException;
import java.util.Scanner;

public class GCD{
    public static void main(String [] args){
        Boolean _flag = true;
        Scanner input = new Scanner(System.in);
        try{
            while(_flag){
                System.out.println("Enter two non-negative integers");

                int a = input.nextInt();
                int b = input.nextInt();
                
                if(a == b) System.out.println("gcd: "+ a);
                else System.out.println("gcd: "+gcd(a,b));
                
                System.out.println("-----------------------------");  
            }
        }catch(InputMismatchException e){
            System.err.println(e.getMessage());
        }


        input.close();
    }

    public static int gcd(int a, int b){
        if(b == 0) return a;
        else{
            System.out.println(String.valueOf(a)+" = "+ String.valueOf(b)+
                                "*" + String.valueOf(a/b) + " + " + String.valueOf(a%b));
        
            return gcd(b, a%b);
        }
    }
}