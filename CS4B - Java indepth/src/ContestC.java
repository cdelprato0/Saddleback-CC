
import java.util.Scanner;



/**
 *
 * @author chazd
 */
public class ContestC {
    
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
   
        
        int intArray[] = new int[26];
      
        for(int i = 0; i < intArray.length; i++ ){
            intArray[i] = 0;
            
        }
        while(input.hasNext()){
        String in = input.nextLine().toLowerCase().replaceAll("[^\\w-]", "");
        

        while(in.length() > 0){
            char letters = in.charAt(0);
            int index = 0;
            int num = 0;
           
            int arrayIndex = Character.getNumericValue(letters) - 10;

            while( index < in.length() && in.charAt(index) == letters){     


                switch(arrayIndex){
                    case 0: intArray[arrayIndex] ++;
                        break;
                    case 1: intArray[arrayIndex] ++;
                        break;
                    case 2: intArray[arrayIndex] ++;
                        break;
                    case 3: intArray[arrayIndex] ++;
                        break;
                    case 4: intArray[arrayIndex] ++;
                        break;
                    case 5: intArray[arrayIndex] ++;
                        break;
                    case 6: intArray[arrayIndex] ++;
                        break;
                    case 7: intArray[arrayIndex] ++;
                        break;
                    case 8: intArray[arrayIndex] ++;
                        break;
                    case 9: intArray[arrayIndex] ++;
                        break; 
                    case 10: intArray[arrayIndex] ++;
                        break; 
                    case 11: intArray[arrayIndex] ++;
                        break;
                    case 12: intArray[arrayIndex] ++;
                        break;
                    case 13: intArray[arrayIndex] ++;
                        break;
                    case 14: intArray[arrayIndex] ++;
                        break;
                    case 15: intArray[arrayIndex] ++;
                        break;
                    case 16: intArray[arrayIndex] ++;
                        break;
                    case 17: intArray[arrayIndex] ++;
                        break; 
                    case 18: intArray[arrayIndex] ++;
                        break;
                    case 19: intArray[arrayIndex] ++;
                        break;
                    case 20: intArray[arrayIndex] ++;
                        break;
                    case 21: intArray[arrayIndex] ++;
                        break; 
                    case 22: intArray[arrayIndex] ++;
                        break; 
                    case 23: intArray[arrayIndex] ++;
                        break;
                    case 24: intArray[arrayIndex] ++;
                        break; 
                    case 25: intArray[arrayIndex] ++;
                        break;  
                    case -11:

                        if( in.length() > 1 && in.charAt(1) == '1' || in.charAt(2) == '1' ){             
                        for(int i = 0; i < intArray.length; i++ ){
                                if(i == intArray.length - 1)
                                {
                                   System.out.print(intArray[i]); 
                                }
                                else{
                 
                                    System.out.print(intArray[i] + " ");
                                }
                            }     
                            System.out.println("");
                            System.exit(0);                            
                        }
                        else{
                            break;
                        }

                    default:
                        break;
                }
                index++;
                num++;  
                
            }
             in = in.substring(num);           
        }
        }
    }   
}
