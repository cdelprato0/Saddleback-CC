import java.util.Scanner;

/**
 * This program will be able to read in a users input of a number and will 
 * double its value and output the reversed digits of the doubled number
 * @author cdelprato0
 * @input user inputs any number
 * @output outputs the reversed number
 */
public class Exercise5_3M {
    
    //This method will be able to reverse the given numbers digits
    public static void reverse( long number ){
        
        long reversedNum = 0; //Sets the reversed num to zero
        
        //Reverses the digits of the number and saves it to the variable 
        //reservedNum
        while( number != 0){
            
            reversedNum = reversedNum * 10;
            reversedNum = reversedNum + number % 10;
            number = number / 10;
        }//END WHILE
        
        //Outputs the reversed digits
        System.out.println(reversedNum);
    }//END METHOD
    
    public static void main( String[] args ){
        
        long inputNum; //Holds the value of the entered number
        long doubleNum; //Holds the value of the doubled number
        
        //Reads in the number from the user
        Scanner input = new Scanner( System.in );
        inputNum = input.nextLong();
        
        //Doubles the number the user entered
        doubleNum =  inputNum * 2;
                
        //Calls the reverse method which will reverse the number's digits
        reverse(doubleNum);
        
    }//END MAIN
}//END PROGRAM
