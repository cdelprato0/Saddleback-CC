/**
 *  This program will out Welcome to Java five times.
 * 
 * @author cdelprato0
 * @output outputs Welcome to Java five times
 * @input none
 */
public class Exercise1_2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        final int MAX_COUNT = 5; //Constant that hold the number of runs needed
        int count; //Keeps count in the FOR loop
        
        //PROCESSING - Runs the loop 5 times printing the text
        for(count = 0; count < MAX_COUNT; count++)
        {
            System.out.print("Welcome to Java\n");
        }//END FOR
    }//END MAIN
}//END PROGRAM
