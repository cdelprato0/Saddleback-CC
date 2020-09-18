
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;
import java.util.regex.Pattern;
import javafx.beans.property.DoubleProperty;
import javafx.beans.property.SimpleDoubleProperty;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author chazd
 */


public abstract class Quiz {
    

    
    public static void main(String[] args) {

        DoubleProperty balance = new SimpleDoubleProperty();
        balance.addListener(ov-> System.out.println(2 + balance.doubleValue()));
        
        balance.set(4.5);
    }
    

    
}
