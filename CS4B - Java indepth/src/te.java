
import java.util.Arrays;
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author chazd
 */
public class te {
    public static void main(String[] args) {
        String input;
        String[] split;
        String[] split2;
        
            
            input = "Book Flight to New York,12/01/2018 23:59";
            split = input.split("[,/]");
            split2 = split[3].split("[\\s:]");
            
            System.out.println(Arrays.toString(split));
            System.out.println(Arrays.toString(split2));
        
    }
   
}
