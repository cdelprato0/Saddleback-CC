/**
 * This program will output 10 numbers per line, all the numbers between
 * 100-1000 that are divisible by both 5 and 6.
 * 
 * @author cdelprato0
 * @input none
 * @output outputs the numbers that are divisible 5 and 6
 */
public class Exercise4_10 {
    
    public static void main( String[] args ){
        
        int numberOne = 100; //Sets the starting value at 100
        int numberTwo = 1000;//Set the last value to 1000
        int count = 1; //keeps count 
        
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
