import java.util.Scanner;

/**
 * This program will read in a user input for the radius of a circle. Then it 
 * will calculate the area of the circle and output the given radius and the 
 * calculated area.
 * 
 * @author cdelprato0
 * @input - User enters the radius of the circle they have
 * @output- Outputs the given information and lets the user know what the area 
 *          is of the circle with a particular radius
 */
public class Circle {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        double radius; //Holds the user input for the radius
        double area;   //Calculates the area of the cricle and holds the value
        
        //Prompts the user to enter the radius of the circle
        System.out.print("Enter radius: ");
        
        //Creates a new scanner called input
        Scanner input = new Scanner(System.in);
        
        //Takes the input from the user and saves it into the radius 
        radius = input.nextDouble();
        
        //Calculates the area and saves the value into area
        area = radius * radius * (java.lang.Math.PI);
        
        //Outputs the final description that tells the user what radius they 
        //inputed and lets them know the area
        System.out.printf("The circle with radius of % has area of %,.2f\n", 
                          radius, area);
    }//End of main
}//End of class
