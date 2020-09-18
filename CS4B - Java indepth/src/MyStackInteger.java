import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * This program will have both MyStackGeneric and MyStackInteger. MSG will be 
 * used as a generic class so that it can be reused down the road. MSG has the
 * bulk of the code and if any class was the extend this class all the basic 
 * methods will transfered to the new class. MSI extends MSG as an integer and 
 * will only work with integer values. The functions this program can do is
 * addition, subtraction, and multiply.
 * 
 * @author cdelprato0
 */
public class MyStackInteger extends MyStackGeneric<Integer> {

    //Overrides the Generic method in MSG and sets the operation in this method
    @Override
    protected Integer minus(Integer object1, Integer object2) {
        return (object1 - object2); //returns the 2 integer objects subtracted
    }
    
    //Overrides the Generic method in MSG and sets the operation in this method
    @Override
    protected Integer plus(Integer object1, Integer object2) {
        return (object1 + object2);  //returns the 2 integer objects added
    }

    //Overrides the Generic method in MSG and sets the operation in this method
    @Override
    protected Integer multiply(Integer object1, Integer object2) {
        return (object1 * object2);  //returns the to integer objects mulitpled
    }
    
    //Overrides the Generic method in MSG and sets the operation in this method
    @Override
    protected Integer newElement(String word) {
        return new Integer(word);
    }

    public static void main(String[] args) {
        //Creates a new stack from MSI. Will be able to hold integer values
        MyStackInteger newStack = new MyStackInteger();

        //reads in the input from the user
        Scanner input = new Scanner( System.in );
        
        //Calls the ProcessIO method that performs all of the operations. The
        //mehtod is stored in MSG.
        newStack.processIO( input, System.out );
        
    }//End MAIN
}
