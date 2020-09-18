import java.util.Scanner;
/**
 * This Program will be able to take in an integer value and add the digits of 
 * that number up into the sum.
 * @author cdelprato0
 * @input The user inputs an integer between 0 - 1000
 * @output Outputs the sum of the digits of the number
 */
public class Exercise2_6 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int number;  //Holds the value of the user input
        int calcNum; //Used to calculate the sum of the digits
        int sumDigit = 0;
        
        //OUTPUT - Prompts the user for an integer
        System.out.print("Enter an integer between 0 and 1000: ");
        
        //INPUT - Creates a new input and loads the users values into it
        Scanner input = new Scanner( System.in );
        number = input.nextInt();
        
        //PROCESSING - Used to enter the while loop so that it can lead to zero
        calcNum = number;
        
        //PROCESSING - While loop is to get each digit on the number and add 
        //             them all together to get the sum
        while(calcNum > 0)
        {
            //Gets the digit from the number
            sumDigit += calcNum % 10;
            
            //Adds the digit to the sum
            calcNum /= 10;
        }//END WHILE LOOP
        
        //OUTPUT-outputs the number that was entered and the sum of the digits
        System.out.println("The sum of all digits in " + number + " is " + sumDigit);
        
    }//END MAIN
}//END PROGRAM
