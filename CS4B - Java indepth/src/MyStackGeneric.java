import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author cdelprato0
 */
public abstract class MyStackGeneric< E > extends ArrayList< E > {

    //Creates an arrayList object that will keep the list stack E
    private final ArrayList< E > listStack = new ArrayList<>();

    //returns the size of the list array
    public int getSize() {
        return listStack.size();
    }//End METHOD

    //Adds the object to the array list
    public void Push(E object) {
        //Calls the add method that adds the object to the specfied index
        listStack.add(object);
    }//End METHOD

    //The pop method will remove an object from the stack
    public E Pop() {
        //saves the head of the stack to the variable so that it can be removed
        E remove = (E) listStack.get(getSize() - 1);
        //Removes the object from the array list
        listStack.remove(getSize() - 1);

        return remove;
    }//End METHOD

    //returns the object that is at the top of the stack
    public E Peek( ){
        return listStack.get( getSize() - 1 );
    }
    //Checks to see if the stack is empty or not
    @Override
    public boolean isEmpty() {
        return listStack.isEmpty();
    }

    //Overrides the to string methods so when this method is called it will 
    //output the new string saved
    @Override
    public String toString() {
        String newStr = "";
        for (int index = 0; index < this.getSize(); index++) {
            
            //Checks to see if the output is at the end of the stack so it does
            //not output an extra comma
            if( index == this.getSize() - 1){
                newStr += listStack.get(index);
            }else{
                newStr += listStack.get(index) + ", ";
            }
        }
        return newStr;
    }

    //These methods will be declared in the class it was extended from
    protected abstract E minus(E object1, E object2);
    protected abstract E plus(E object1, E object2);
    protected abstract E multiply(E object1, E object2);
    protected abstract E newElement(String word);

    //ProcessIO will be the work horse and have almost all of the operations of
    //the program. It will conduct the test data and be able to add, subtract,
    //and multiply. It will check all of the input to make sure it is only 
    //integers and that there is the correct arithometic
    protected String processIO(Scanner input, PrintStream output) {

        StringBuilder str = new StringBuilder();

        //Scanes through the input
        while( input.hasNext() ){
            String userInput = input.next();

            try{
                //Checks to see if it is valid input
                if( userInput.matches( "[a-zA-Z]|[+*-]" ) ){
                    //Checks to see what operation to perform
                    switch( userInput ){
                        //Prints the stack to the console
                        case "p" :
                            System.out.println( toString() );
                            continue;
                        //Adds the integers before the + sign
                        case "+" :
                            if( getSize() >= 2 ){
                                E sum = plus( Pop( ), Pop( ) );
                                Push( sum );
                            }//End IF
                            else{
                                //throws an error if the stack is empty
                                throw new Exception();
                            }//End ELSE
                            continue;
                        //Multiplies the integers before the * sign
                        case "*" :
                            if( getSize() >= 2 ){
                                E multi = multiply( Pop(), Pop());
                                Push( multi );
                            }else{
                                //Throws an exception if the stack is empty
                                throw new Exception();
                            }
                            continue;
                        //Subtracts the integers before the - sign
                        case "-" :
                            if( getSize() >= 2 ){
                                E temp = Pop();
                                E diffTemp = minus( Pop( ), temp ) ;
                                Push( diffTemp );
                            }//End IF
                            else{
                                //throws an error if the stack is empty
                                throw new Exception();
                            }//End ELSE
                            continue;
                        default: 
                    }// End SWITCH
                } //End IF
            }//End TRY
            //tells what error should be thrown if there was an error caugth
            catch ( Exception exp ){
                if( getSize() < 2 ){
                    System.out.println( "ArithmeticException need two operands");
                }//End IF
                else if( userInput.length() > 1 ){
                    System.out.println( "InputMismatchException too long: " 
                                        + userInput );
                }//End ELSE_IF
                else{
                    System.out.println( "InputMismatchException unknown command: " 
                                        + userInput );
                }//End ELSE
                continue;
            }//End CATCH
            
            //Parsed the int from the used input/ checks the userinput
            try{
                E e = (E) newElement(userInput);
                Push(e);
            }//End TRY
            catch ( Exception exp ){
                if( userInput.length() > 1 ){
                    System.out.println( "InputMismatchException too long: " 
                                        + userInput );
                }//End IF
                else{

                    System.out.println( "InputMismatchException unknown command: " 
                                        + userInput );
                }//End ELSE
            }//End CATCH
        }
        return str.toString();
    }
}
