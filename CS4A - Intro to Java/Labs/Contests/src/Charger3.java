
import java.util.Scanner;



/**
 *
 * @author cdelprato0
 */
public class Charger3 {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner("0 50 50 36 52 51 51 \n70 25\t34 100 99 52 49");
        int[] array = new int[14];
        
        int parseInteger;
        int count = 0;
        int sum = 0;
        double average;
        
        while( input.hasNext() ){
            int index = 0;
            String check = input.next().toLowerCase();
            
            
            if(isInt(check)){
                parseInteger = Integer.parseInt(check);
                try{
                    if(isInt(check))
                    {
                        if( parseInteger >= 0 ){

                            array[index] = parseInteger;
                            sum = sum + array[index];                           
                            System.out.println(array[index]);

                        }                        
                    }
                }
                catch(NumberFormatException c){
                    count++;
                    System.out.println("Bad Data Count was " + count );
                }
            }                 
            index++;
            
        }
        
        average = sum / (double)array.length;
        int distance = Math.abs( array[0] - (int)average);
        int c = 0;
        for(int index = 1; index < array.length; index++){
            int cdistance = Math.abs(array[index] - (int)average);
            if(cdistance < distance){
                c = index;
                distance = cdistance;
            }
        }
        int theNumber = array[c];
        
        System.out.print("Mean is ");
        System.out.printf("%5.2f", average);
        System.out.println("Closest values are: " + theNumber);
    }
    
    
    public static boolean isInt( String checkString ){
        try{
            Integer.parseInt(checkString);
        }//End TRY
        catch ( NumberFormatException excep ) {
            return false;
        }//End CATCH
        return true;
    }//End isINT    
    
    
}