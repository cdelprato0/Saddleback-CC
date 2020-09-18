import java.util.Scanner;
/**
 * This program will be able to detect if a character is a consonant, a vowel 
 * or an invalid input of a character
 * 
 * @author cdelprato0
 * @input users input of a letter a-z
 * @output outputs if the letter is a vowel, consonant, or if it is an invalid letter
 */
public class Vowel {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //Array that holds the values of the constants
        char consonants[] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 
            'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};
    
        //outputs to recieve the letter from the user
        System.out.print("Enter a letter: ");
        
        //Creates a new scanner that scan the input
        Scanner input = new Scanner( System.in );
        
        while(input.hasNext())
        {
            boolean found = false;
            String str = input.next();
            String strUpper = str.toUpperCase();
            char character = strUpper.charAt(0);
            
            //Detect if the user input is a vowel and will output if it is
            if( character == 'A' || character == 'E' || character == 'I' ||
                character == 'O' || character == 'U' )
            {
                System.out.println(str.charAt(0) + " is a vowel");
                found = true;
            }
        
            //If it is not a vowel it will check to see if it is consonant and output so
            if( found == false )
            {
                for( int index = 0; index < consonants.length; index++ )
                {
                    if( character == consonants[index] )
                    {
                        System.out.println(str.charAt(0) + " is a consonant");
                        found = true;
                    }
                }
            }
            
            //If the value that the user enter is not a letter it will output so
            if( found == false )
            {
                System.out.println(str.charAt(0) + " is an invalid input");
            }
        
            //It is the change variable of the while loop
            System.out.print("Enter a letter: ");
        }
    }//END MAIN
}//END PROGRAM
