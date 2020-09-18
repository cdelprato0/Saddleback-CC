
import java.util.Scanner;

/**
 * This program will read in numbers from a user and check to see if they are 
 * positive or negative and will add them to a total and get the average of all 
 * the numbers
 * 
 * @author cdelprato0
 * @input user inputs the numbers
 * @output it will output the positive numbers, negative numbers, total numbers,
 *          and average
 */
public class CounterInteger {
    
    public static void main( String[] args)
    {
        int numbers;
        int posCount = 0;
        int negCount = 0;
        int totalCount = 0;
        double sum = 0.0;
        double average;
        
        //Prompts the user
        System.out.print("Enter integers, input ends with 0: ");
        
        //Reads in the user input
        Scanner input = new Scanner(System.in);
        
        //Reads the entered numbers and performs the folling test to see if it 
        //is negative or postive
        while((numbers = input.nextInt()) != 0){
          
            if( numbers > 0 ){
                posCount++;
                totalCount++;
            }//End If
            else if( numbers < 0){
                negCount++;
                totalCount++;
            }//End Else If
            //Keeps a sum to compute the average
            sum = sum + numbers;
        }//End While
        
        //Test to see if the first number entered is zero
        if ( totalCount == 0 )
        {
            if ( numbers == 0){
                System.out.println("No numbers were entered except 0");
            }//End If
        }//END if
        //If not then it will output as follows
        else{
            System.out.println("The number of positives is " + posCount);
            System.out.println("The number of negatives is " + negCount);
            System.out.println("The total count is " + totalCount);
        
            average = sum / totalCount;
            System.out.printf("The average is %.2f\n", average);  
        }//End else
    }//End Main
}//End Class
