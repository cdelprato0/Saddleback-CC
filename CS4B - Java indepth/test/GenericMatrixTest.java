/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import org.junit.Test;
import static org.junit.Assert.*;
import org.junit.Before;

/**
 *
 * @author chazd
 */
public class GenericMatrixTest {
    
    public GenericMatrixTest() {
    }

    @Before
    public void setUp() throws Exception {
    }

    /**
     * Test of add method, of class GenericMatrix.
     */
    @Test
    public void testAdd() {
        System.out.println("add");
        Object o1 = null;
        Object o2 = null;
        GenericMatrix instance = new GenericMatrixImpl();
        Object expResult = null;
        Object result = instance.add(o1, o2);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of multiply method, of class GenericMatrix.
     */
    @Test
    public void testMultiply() {
        System.out.println("multiply");
        Object o1 = null;
        Object o2 = null;
        GenericMatrix instance = new GenericMatrixImpl();
        Object expResult = null;
        Object result = instance.multiply(o1, o2);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of zero method, of class GenericMatrix.
     */
    @Test
    public void testZero() {
        System.out.println("zero");
        GenericMatrix instance = new GenericMatrixImpl();
        Object expResult = null;
        Object result = instance.zero();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of addMatrix method, of class GenericMatrix.
     */
    @Test
    public void testAddMatrix() {
        System.out.println("addMatrix");
        Object[][] matrix1 = null;
        Object[][] matrix2 = null;
        GenericMatrix instance = new GenericMatrixImpl();
        Object[][] expResult = null;
        Object[][] result = instance.addMatrix(matrix1, matrix2);
        assertArrayEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
        
        System.out.println("");
        
    }

    /**
     * Test of multiplyMatrix method, of class GenericMatrix.
     */
    @Test
    public void testMultiplyMatrix() {
        System.out.println("multiplyMatrix");
        Object[][] matrix1 = null;
        Object[][] matrix2 = null;
        GenericMatrix instance = new GenericMatrixImpl();
        Object[][] expResult = null;
        Object[][] result = instance.multiplyMatrix(matrix1, matrix2);
        assertArrayEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of printResult method, of class GenericMatrix.
     */
    @Test
    public void testPrintResult() {
        System.out.println("printResult");
        Number[][] m1 = null;
        Number[][] m2 = null;
        Number[][] m3 = null;
        char op = ' ';
        GenericMatrix instance = new GenericMatrixImpl();
        instance.printResult(m1, m2, m3, op);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }


    public class GenericMatrixImpl extends GenericMatrix {

        public E add(E o1, E o2) {
            return null;
        }

        public E multiply(E o1, E o2) {
            return null;
        }

        public E zero() {
            return null;
        }

        @Override
        protected Object add(Object o1, Object o2) {
            throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        }

        @Override
        protected Object multiply(Object o1, Object o2) {
            throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        }

        @Override
        protected Object minus(Object object1, Object object2) {
            throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        }

        @Override
        protected Object plus(Object object1, Object object2) {
            throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        }

        @Override
        protected Object newElement(String word) {
            throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        }
    }
    
}
