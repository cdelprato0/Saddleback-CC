
import java.util.Random;


/**
 *
 * @author cdelprato{
 */
public class SearchingLab {
    
    public static boolean BinarySearch( int intArray[], int key){
        boolean found = false;
        int low = 0;
        int high = intArray.length - 1;
          
        while(high >= low) {
            int middle = (low + high) / 2;
            if(intArray[middle] == key) {
               return true;
            }
            if(intArray[middle] < key) {
                low = middle + 1;
            }
            if(intArray[middle] > key) {
                high = middle - 1;
            }
            return false;
            
        }
        return found;
    }
                 
    public static boolean LinearSearch( int intArray[], int key )
    {
        int index = 0;
        for(;index < intArray.length; index++) {
            if(intArray[index] == key) {
                 return true;
            }
            if(intArray[index] < key) {
                return false;
            }
                                 
        }
        return false;
    }


        
    
    
    public static void main( String[] args ){
        
        boolean found;
        int foundindex;
        
        int arSize = 1000000;
        int searches = 25;
        
        
        long beforeTime;
        long afterTime;
        
        int[] intArray = new int[arSize];
        long[][] myTimes = new long[3][searches];
        
        for(int index = 0; index < arSize; index++){
            Random ran = new Random();
            intArray[index] = ran.nextInt(900) + 100;
            
        }
        int key = 555;
        java.util.Arrays.sort(intArray);
                
        for(int index = 0; index < searches; index ++){
            
            beforeTime = System.nanoTime();
            found = LinearSearch(intArray, key);
            afterTime = System.nanoTime();
            myTimes[0][index] = afterTime - beforeTime;
            
            
            beforeTime = System.nanoTime();
            found = BinarySearch(intArray, key); 
            afterTime = System.nanoTime();
            myTimes[1][index] = afterTime - beforeTime;

            beforeTime = System.nanoTime();
            foundindex = java.util.Arrays.binarySearch(intArray, key); 
            afterTime = System.nanoTime();
            myTimes[2][index] = afterTime - beforeTime;
            
        }
        
        for(int i = 0; i < 3 ; i++){
            for( int j = 0 ;j < searches; j++){
                System.out.print(myTimes[i][j] + "\t");
            }
            System.out.println("");
        }        
    }
}
