
import java.util.Scanner;


/**
 *
 * @author cdelprato0
 */
public class Combinations {
    
    public static void main( String[] args ){
        
        int number1;
        int number2;
        int combinations = 0;
        boolean valid = true;
        
        Scanner input = new Scanner( System.in );
        do{
            
            number1 = input.nextInt();
            number2 = input.nextInt();
            
            if( number1 > number2 ){
                valid = false;
                
                System.out.print("First number must be less than second try again! ");
            }
            else{
                valid = true;
                
                while( number1 < number2 ){
                    
                    for( int count = ( number1 + 1 ); count <= number2; count++){
                        
                        System.out.println(number1 + " " + count);
                        combinations++;
                        
                    }
                    
                    number1++;
                }
            }
            
        }while( !valid );
        
        System.out.println("The total number of combinations is " + combinations);
        
    }
    
}
