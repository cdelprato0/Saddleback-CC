import java.util.Scanner;

/**
 * This program will output 10 numbers per line, all the numbers between
 * the first user entered number to the number of the second number entered
 * that are divisible by both 5 and 6.
 * @author cdelprato0
 * @inout user input of the smallest and largest number
 * @output will output the numbers that are divisible by 5 and 6 within the 
 *          given numbers
 */
public class Exercise4_10M {
    
    public static void main( String[] args ){
        
        int numberOne; //holds the value of the smallest number
        int numberTwo;//holds the value of the largest number
        int count = 1; //keeps count 
        
        Scanner input = new Scanner( System.in );
        
        numberOne = input.nextInt();
        numberTwo = input.nextInt();
        
        while( numberOne <= numberTwo ){
            
            //Checks to see if the number is divisible by 5 and 6
            if( (numberOne % 5 == 0) && (numberOne % 6 == 0) ){
                
                //prints the numbers that are even in count
                if( count % 10 == 0 ){
                   
                    System.out.println(numberOne);
                    count++;
                    
                }//END IF
                //prints the numbers that are odd in count
                else{
                   
                    System.out.print(numberOne + " ");
                    count++;
                }//END ELSE
            }//END IF
            numberOne++;
            
        }//END WHILE
        //Outputs an end line at the end
        System.out.println();
    }//END MAIN    
}//END PROGRAM
