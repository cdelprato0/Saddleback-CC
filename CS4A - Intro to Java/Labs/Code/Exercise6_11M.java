
import java.util.Scanner;

/**
 * This program will be able to calculate the mean and standard deviation of an
 * array of double numbers and output to the console the solutions.
 *
 * @author cdelprato
 * @input user enters 10 numbers
 * @output displays the mean and standard deviation
 */
public class Exercise6_11M {
    
    public static void main( String[] args )
    {
        double[] doubleAr = new double[10]; //Creates the array
        double sum = 0.0; //Accumlates the running total
        double mean;  //Find the average of the numbers
        
        //Creates a new input 
        Scanner input = new Scanner( System.in );
        
        //Reads in the users input and calculates the sum
        for( int index = 0; index < doubleAr.length; index++){
            doubleAr[index] = input.nextDouble();
            sum = sum + doubleAr[index];
        }//End for
        
        //Calculates the average using the sum and size
        mean = sum / doubleAr.length;
        
        double oneOverN = 1.0/(doubleAr.length - 1); //used for 1/N
        double xNot = 0.0;  //the varience
        double standardDev; //standard deviation
        
        //Calculates the varience
        for( int index = 0; index < doubleAr.length; index++ ){
            xNot += Math.pow( ( doubleAr[index] - mean ), 2 );
        }//End for
         
        //Calculates the Standard deviation
        standardDev = Math.sqrt( oneOverN * xNot );
        
        //Outputs the solutions to the console
        System.out.println( "The mean is " + mean );
        System.out.println( "The standard deviation is " + standardDev );
        
    }//End main
    
}//End Class
