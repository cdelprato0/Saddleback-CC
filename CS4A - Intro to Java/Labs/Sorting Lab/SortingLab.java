
import java.util.Random;

/**
 *
 * @author chazd_000
 */
public class SortingLab {
    
    public static void SelectionSort(int[] intAr){
         
        for (int i = 0; i < intAr.length - 1; i++)
        {
            int index = i;
            for (int j = i + 1; j < intAr.length; j++)
                if (intAr[j] < intAr[index])
                    index = j;
      
            int smallerNumber = intAr[index]; 
            intAr[index] = intAr[i];
            intAr[i] = smallerNumber;
        }
    }
    
    public static void InsertionSort(int[] intAr){
         
        int temp;
        for (int i = 1; i < intAr.length; i++) {
            for(int j = i ; j > 0 ; j--){
                if(intAr[j] < intAr[j-1]){
                    temp = intAr[j];
                    intAr[j] = intAr[j-1];
                    intAr[j-1] = temp;
                }
            }
        }
    }
    
    public static void BubbleSort(int[] intAr) {
              
        int temp = 0;
               
        for(int i=0; i < intAr.length; i++){
            for(int j=1; j < (intAr.length-i); j++){
                             
                if(intAr[j-1] > intAr[j]){
                    temp = intAr[j-1];
                    intAr[j-1] = intAr[j];
                    intAr[j] = temp;
                }                 
            }
        }
       
    }
    
    public static void main( String[] args ){
        
        int arSize = 100000;
        
        long beforeTime;
        long afterTime;
        
        int[] intArray = new int[arSize];
        
        for( int index = 0; index < intArray.length; index++ ){
            Random randNum = new Random();
            intArray[index] = randNum.nextInt(1000);
        }
        
        
        for( int count = 0; count < 15; count++){
            
            beforeTime = System.nanoTime();
            SelectionSort(intArray);
            afterTime = System.nanoTime();
            System.out.print((afterTime - beforeTime) + "\t");
           
        }
        System.out.println("Selection Sort");
        
        
        for( int count = 0; count < 15; count++){
            beforeTime = System.nanoTime();
            InsertionSort(intArray);
            afterTime = System.nanoTime();
            System.out.print((afterTime - beforeTime) + "\t");            
        }
        System.out.println("Insertion Sort");
        
        for( int count = 0; count < 15; count++){
            beforeTime = System.nanoTime();
            BubbleSort(intArray);
            afterTime = System.nanoTime();
            System.out.print((afterTime - beforeTime) + "\t");            
        }
        System.out.println("Bubble Sort");     
        
        
        for( int count = 0; count < 15; count++){
            beforeTime = System.nanoTime();
            java.util.Arrays.sort(intArray);
            afterTime = System.nanoTime();
            System.out.print((afterTime - beforeTime) + "\t");            
        }
        System.out.println("Java Sort");                          
    }
}
