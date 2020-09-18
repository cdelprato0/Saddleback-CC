
import java.util.Scanner;

/**
 *
 * @author cdelprato0
 */
public class LG {
    public static void main( String[] args){
        String name;
        int peopleCount;
        String labKey;
        int labMax = 0;
        int labPoints = 0;
        double average;
        long sum = 0;
        long sumPoss = 0;
     
        String data = "5\n" +
        "possible 10 15 10 5 20 10\n" +
        "wileyCoyote 10 15 10 7 21 10\n" +
        "Goofy 10 15 10 5 20 10\n" +
        "MinnieMouse 8 12 8 4 14 6\n" +
        "MickeyMouse 8 12 8 4 14 6\n "+
        "DonaldDuck 7 13 7 5 12 5\n";
        
        Scanner input = new Scanner( data );
        
        peopleCount = input.nextInt();
        System.out.print(peopleCount + "\n");
        input.nextLine();
        
        labKey = input.next();
        System.out.print(labKey + " ");
        while( input.hasNextInt() ){
            labMax = input.nextInt();
            System.out.print(labMax + " ");
            sumPoss = (sumPoss + input.nextInt());
        }
        

       
        while( input.hasNext() ){
            name = input.next();
            System.out.print("\n" + name + " ");
            
            while( input.hasNextInt() ){
                
                labPoints = input.nextInt();
                sum = sum + labPoints;
                System.out.print(labPoints + " ");
             }

        }
        System.out.print(sum + " " + sumPoss);
        average = sum / sumPoss;
        System.out.printf("\n %5.2f", average);

    }
    
}
