import java.util.Date;
import java.util.Scanner;

/**
 * This program will be able to take in a user's input of milliseconds and 
 * translate it into the day of the week, the month, the exact time with hours, 
 * minutes, and seconds, the time zone, and the year.
 * 
 * @author cdelprato0
 * @input The users input of milliseconds in time
 * @output Outputs the date with day of week, month, year, and time of the
 *          milliseconds entered
 */
public class MyTime {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        long userMilliseconds; //The variable that holds the user's input
        
        //Creates a new Scanner called userInput
        Scanner userInput = new Scanner(System.in);
        
        //This will take the user's input that is of long data type and load it
        //into the variable
        userMilliseconds = userInput.nextLong();
        
        //Outputs the date that is assoicated with the user's milliseconds
        System.out.println( new Date(userMilliseconds));
    }//end main
}//end class
