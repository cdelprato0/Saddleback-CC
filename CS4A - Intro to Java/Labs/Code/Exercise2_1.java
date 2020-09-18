import java.util.Scanner;
/**
 * This program will be able to take in a degree in Celsius and convert it to 
 * Fahrenheit.
 * 
 * @author cdelprato0
 * @input User enters the degrees in Celsius
 * @output Outputs the degrees in Fahrenheit
 */
public class Exercise2_1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        double tempC; //Holds the value for Celsius
        double tempF; //Holds the value for Fahrenhiet
        
        //OUTPUT - Outputs the temperture prompt
        System.out.print("Enter a temperature in Celsius: ");
        
        //INPUT - Creates a new scanner item and reads in the user input
        Scanner input = new Scanner( System.in );
        tempC = input.nextDouble();
        
        //PROCESSING - Calculates the temperture from Celsius to Fahrenheit
        tempF = (9.0/5) * tempC + 32;
        
        //OUTPUT - outputs the tempture in Fahrenheit
        System.out.printf("The temperature is %,.2f in Fahrenheit.\n" , tempF);
    }
}
