import java.util.Scanner;

/**
 * This program will be able to read in a number and add all the digits up and
 * output the sum of those digits.
 * 
 * @author cdelprato0
 * @input User input of a number.
 * @output Outputs the number given and the sum of each digit of that number.
 */
public class Exercise2_6M {
    
    public static void main( String args[] ){
        
        int sum = 0; //Holds the vaule for the sum
        
        //Prompts the user to enter a number
        System.out.print("Enter an integer: ");
        
        //Takes in the user input and saves it
        Scanner input = new Scanner(System.in);
        int numbers = input.nextInt();
        
        //Used for outputting the number that was given from the user
        int outputNum = numbers;
        
        //Will take all number positive and negative except zero
        while( numbers != 0 ) {
            
            //Accumlates the sum using the Math.abs and dividing by 10 to get
            //each digit by it self
            sum = sum + Math.abs(numbers % 10);
            
            numbers = numbers / 10;
        }//END While Loop
        
        //Outputs the final prompt that has the number given and the sum of all 
        //the digits
        System.out.println("The sum of all digits in " + outputNum + " is " + sum);
        
    }//END main
    
}//End Class
