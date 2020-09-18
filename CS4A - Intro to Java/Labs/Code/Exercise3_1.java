import java.util.Scanner;

/**
 *This program will be able to take in a user's input of side lengths and 
 * determine if they can create a triangle.
 * 
 * @author cdelprato0
 * @input user enters the three sides of the triangle
 * @output output the users given sides and determines if it is a triangle or not
 */
public class Exercise3_1 {
    
    public static void main( String[] args){
        
        double side1;  //One side of he triangle
        double side2;  //One side of he triangle
        double side3;  //One side of he triangle
        double biggestSide = 0;  //Holds the biggest side
        boolean triangle; //Checks if it is a triangle or not
        
        //OUTPUT - Propmts the user for their input
        System.out.print("Enter three edges: ");
        
        //INPUT - Reads in the user's input of numbers and assigns each side to 
        //          a variable
        Scanner input = new Scanner(System.in);
        
        side1 = input.nextDouble();
        side2 = input.nextDouble();
        side3 = input.nextDouble();
        
        //PROCESSING - Takes each side and finds which side is the largest
        if( side1 > side2 && side1 > side3 ){
            biggestSide = side1;
        }
        else if( side2 > side3 && side2 > side1 ){
            biggestSide = side2;
        }
        else if( side3 > side1 && side3 > side2 ){
            biggestSide = side3;
        }
        
        //PROCESSING - Checks to see if the sides that have been given are able
        //             to create a triangle
        if( (side1 + side2) > biggestSide && (side1 + side3) > biggestSide &&
            (side2 + side3) > biggestSide){
            triangle = true;
        }
        else if( side1 == side2 && side1 == side3 ){
            triangle = true;
        }
        else{
            triangle = false;
        }
        
        //OUTPUT - outputs to the console the given sides and if they can form a
        //         triangle
        System.out.print("Can edges " + side1 + ", " + side2 + ", and " + side3 +
                         " form a triangle? " + triangle + "\n");     
        
    }
    
}
