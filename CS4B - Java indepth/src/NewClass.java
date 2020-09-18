/*

 
But you should do a right^click save
 */


import java.io.StringWriter;
import java.util.TreeSet;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Text;

/**
 * @author tdedonno
 * @version 3/2012
 */
public abstract class  AbstractAboutNumber {

    /** subclass needs to set number before calling any isMethods
     *  note one could write this as all static methods e.g.,  static boolean isPrime( int n )
     *  this would align it more closely with the actual java.lang.Math class
     */
    protected int number = 1;

    /** you may want to add a throws Arithmetic Exception or NumberOutOfBounds Exception 
        range is 1 to about MaxInt, do the same for your constructor */
    public int setNumber( int n ) { return number = n; }
    public int getNumber( ) { return number; }

    public abstract boolean isPrime( );
    public abstract boolean isEven( );
    public abstract boolean isOdd( );
    public abstract boolean isPalindrome( );
    public abstract boolean isPalindromicPrime( );
    public abstract boolean isFibonacci( );
    public abstract boolean isPerfectSquare( );
    /** return a sorted set of Primes,  all primes return an empty set */
    public abstract TreeSet primeFactors( );

    /** should be reusing code from XMLOutputNode but I'm not */
    public String XMLOutput(  ) throws Exception
    {
        DocumentBuilderFactory  factory = DocumentBuilderFactory.newInstance( );
        DocumentBuilder b = factory.newDocumentBuilder();
        Document doc = b.newDocument();

        Element root = doc.createElement("AboutNumbers");

        //for computer generated code you normally don't add extra white spaces, for testing we need readability
        //root.appendChild( doc.createTextNode("\n" ) );
        //Create XML file and use right Click Format
        Element firstChild  = doc.createElement(  "AboutNumber" );
        Element child = doc.createElement( "Number" );
        Text text = doc.createTextNode(   Integer.toString( number )  );
        child.appendChild( text );
        firstChild.appendChild( child );

        String[] titles =  { "Prime", "Even", "Odd", "Palindrome", "PalindromicPrime", "Fibonacci", "PerfectSquare"  };
        // Note java SE7 supports String case statements, but se7 is not everywhere so even though I should use it I'm not

        for( int i = 0; i < titles.length ; ++i ) {

            //root.appendChild( doc.createTextNode("\n" ) );
            child = doc.createElement(  "NumberInfo"  );
            try {
            boolean result = false;
            switch( i ) {
                case 0: result = isPrime( ); break;
                case 1: result = isEven( ); break;
                case 2: result = isOdd( ); break;
                case 3: result = isPalindrome( ); break;
                case 4: result = isPalindromicPrime(); break;
                case 5: result = isFibonacci( ); break;
                case 6: result = isPerfectSquare(); break;
                default: throw new UnsupportedOperationException( "Unknown isNames Method" );
                }
            text = doc.createTextNode(  Boolean.toString( result ) );
            }
            catch( UnsupportedOperationException e )
            {  text = doc.createTextNode(  e.getMessage()  ); }

            child.setAttribute( "title",  titles[i]  );
            child.setAttribute( "description", "not yet implemented" );
            child.appendChild( text );
            firstChild.appendChild( child );

        } //end for( int = 0;

        /* You need to write the code to output the primeFactors, make sure you meet the aboutNumber dtd or xsd
         * until you have written all isMethods, the output xml will not pass validation, 
         * XSD is much more verbose than DTD, XSD exists on lab page and is more verbose than DTD. 

         * assigment page has link to DTD
         */
        child = doc.createElement("Prime Factors");
        child.setAttribute("title", "PrimeFactors");
        
        //AboutNumber = an new AboutNumber(3);
        //Scanner
        //ab.setNumber(in.nextint
//        try{
//            System.out.println(ab.xml);
//        }catch{
//            logger,getLogger(Aoutnumber.class.get)
//        }
        
        
        
        root.appendChild( firstChild );
        doc.appendChild( root );

        // doc.getDomConfig().setParameter(null, out)
        TransformerFactory transformerFactory =  TransformerFactory.newInstance();
        Transformer transformer = transformerFactory.newTransformer();
        StringWriter out = new StringWriter( ); //note out could be System.out
        transformer.transform( new DOMSource(doc), new StreamResult(out) );
        return out.toString();
    }

    /** Output XML data with nodes and elements only no attributes */
    @Deprecated
    @SuppressWarnings("deprecation")
    public String XMLOutputNode(  ) throws Exception
    {
        DocumentBuilderFactory  factory = DocumentBuilderFactory.newInstance( );
        DocumentBuilder b = factory.newDocumentBuilder();
        Document doc = b.newDocument();

        Element root = doc.createElement("AboutNumber");

        //for computer generated code you normally don't add extra white spaces, for testing we need readability
        //root.appendChild( doc.createTextNode("\n" ) );
        //Create XML file and use right Click Format
        Element child  = doc.createElement(  "Number" );
        Text text = doc.createTextNode(   Integer.toString( number )  );
        child.appendChild( text );
        root.appendChild( child );

        String[] isNames =  { "isPrime", "isEven", "isOdd", "isPalindrome", "isPalindromicPrime", "isFibonacci", "isPerfectSquare"  };
        // Note java SE7 supports String case statements, but se7 is not everywhere so even though I should use it I'm not

        for( int i = 0; i < isNames.length ; ++i ) {

            //root.appendChild( doc.createTextNode("\n" ) );
            child = doc.createElement(  isNames[i] );
            try {
            boolean result = false;
            switch( i ) {
                case 0: result = isPrime( ); break;
                case 1: result = isEven( ); break;
                case 2: result = isOdd( ); break;
                case 3: result = isPalindrome( ); break;
                case 4: result = isPalindromicPrime(); break;
                case 5: result = isFibonacci( ); break;
                case 6: result = isPerfectSquare(); break;
                default: throw new UnsupportedOperationException( "Unknown isNames Method" );
                }
            text = doc.createTextNode(  Boolean.toString( result ) );
            }
            catch( UnsupportedOperationException e ) 
            {  text = doc.createTextNode(  e.getMessage()  ); }

            child.appendChild( text );
            root.appendChild( child );

        } //end for( int = 0;

        /* You need to write the code to output the primeFactors, make sure you meet the aboutNumber dtd
         * until you have written all isMethods, the output xml will not pass validation, may release an XSD file
         * XSD is much more verbose than DTD, and you can specify data types
         */
        doc.appendChild( root );

        // doc.getDomConfig().setParameter(null, out)
        TransformerFactory transformerFactory =  TransformerFactory.newInstance();
        Transformer transformer = transformerFactory.newTransformer();
        StringWriter out = new StringWriter( ); //note out could be System.out
        transformer.transform( new DOMSource(doc), new StreamResult(out) );
        return out.toString();
    }
}
/* 

