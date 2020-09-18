import java.util.Scanner;

/**
 * This program will be able to read in a number form the user and determine if 
 * it is even or not
 * @author cdelprato0
 * @input user inputs an integer
 * @output outputs if it is even or not
 */
public class Exercise3_2 {
    
    public static void main( String[] args){
        int number;  //Holds the value of the user input
        boolean even;//Determines if the integer is even or not
        
        //Outputs the propmt for the user
        System.out.print("Enter an integer: ");
        
        //Creates a new Scanner so the input can be saved to a varible
        Scanner input = new Scanner(System.in);
        number =  input.nextInt();
        
        //Checks to see if the integer is even or odd
        if( number % 2 == 0){
            
            //if it is even sets the bool to true and outputs
            even = true;
            System.out.printf("Is " + number + " an even number? " + even + "\n");
        }//END ELSE
        else{
            //If the integer is odd it sets the bool to false and outputs
            even = false;
            System.out.printf("Is " + number + " an even number? " + even + "\n");
        }//END ELSE
        
    }//end main
    
}//end class
