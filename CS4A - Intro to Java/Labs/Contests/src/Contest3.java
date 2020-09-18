import java.util.Scanner;

/**
 *
 * @author cdelprato0
 */
public class Contest3 {
    
    public static void main ( String[] args){
        int number;
        int calcNumber;
        int reverse = 0;
        int digit;
        
        Scanner input = new Scanner( System.in );
        number = input.nextInt();
        
        if( number < 0 )
        {
            number = number * -2;
        }
        calcNumber = number;
        
        while( calcNumber > 0){
            digit = calcNumber % 10;
            reverse = reverse * 10 + digit;
            calcNumber = calcNumber / 10;
            
        }
        if( number == reverse )
        {
            System.out.println(number + " is a palindrome");
        }
        else
        {
            System.out.println(number + " is not a palindrome");
        }
        
    }
}
