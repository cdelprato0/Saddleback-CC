import java.util.Scanner;

/**
 *
 * @author Chaz
 */

   
    class Rectangle{
        double height;
        double width;
        double x;
        double y;
        
        Rectangle( double pointX, double pointY, double r ){
            x = pointX;
            y = pointY;
            height = r * 2;
            width = height;
        }
        Rectangle( double pointX, double pointY, double h, double w){
            x = pointX;
            y = pointY;
            height = h;
            width = w;
        }
        //Calculates the perimeter
        public double GetPerimeter(){
            return (width*2 + 2*height);
        }//END METHOD 
        
        //Calculates the Area
        public double GetArea(){
            return (width*height);
        }//END METHOD

        private boolean Contains(double cx, double cy){ 
            return ( ( cx >= ( x - width / 2 ) && cx <= ( x + width / 2 ) ) && 
                     ( cy >= ( y - height / 2 ) && cy <= ( y + height / 2 ) ) );
            
        }
        public boolean Contains(Rectangle rec){
            if(rec.Contains( ( x - width / 2 ) , ( y - height / 2 ) ) &&
                rec.Contains( ( x + width / 2 ), ( y + height / 2 ) ) &&
                 rec.Contains( ( x - width / 2 ), ( y + height / 2 ) ) &&
                  rec.Contains( ( x + width / 2), ( y - height / 2 ) ) ){
                
                System.out.println("\ncontains: " + true);
                return true;
            }
            else {
                System.out.println("\ncontains: " + false);
                return false;
            }
            
        }
        
        public boolean Overlaps(Rectangle rec){
            
            if(rec.Contains(x, y) ||
                rec.Contains( ( x + width ), ( y + height ) ) ||
                 rec.Contains( ( x ), ( y + height ) ) ||
                  rec.Contains( ( x + width ), ( y ) ) ){
                System.out.println("overlaps: " + true);
                return true;
            }
            else {
                System.out.println("overlaps: " + false);
                return false;
            }            
            
        }
        
        @Override
        public java.lang.String toString(){
            return(String.format("\nperimeter: %.3f\narea: %.3f\n" , GetPerimeter() 
                   , GetArea()));
            
        }
    }

public class Exercise9_12 {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner( System.in );
        System.out.print("Enter rectangle: ");
        
        while( input.hasNext() ){
            String[] numbers = input.nextLine().split("\\s+");
            double[] num = new double[numbers.length];
        
            for( int index = 0; index < numbers.length; index++){
                num[index] = Double.parseDouble(numbers[index]);
            }

            Rectangle rec1 = null;
            rec1 = createRectangle( num, rec1 );
            System.out.print(rec1.toString());
      
            System.out.print("Enter rectangle: ");
            
            
            numbers = input.nextLine().split("\\s+");
            num = new double[numbers.length];
        
            for( int index = 0; index < numbers.length; index++ ){
                num[index] = Double.parseDouble( numbers[index] );
            } 
            
            Rectangle rec2 = null;
            rec2 = createRectangle( num, rec2 );
            rec2.Contains(rec1);
            rec2.Overlaps(rec1);
            
            System.out.print("Enter rectangle: ");
        }
        
    }
    public static Rectangle createRectangle( double[] num, Rectangle rec){
        switch( num.length ){
            case 3: rec = new Rectangle(num[0], num[1], num[2]);
                    break;
            case 4: rec = new Rectangle( num[0], num[1], num[2], num[3]);
                    break;
            default: System.out.println("");
                    System.exit(0);
                    break;
        }
        return rec;
    }
}