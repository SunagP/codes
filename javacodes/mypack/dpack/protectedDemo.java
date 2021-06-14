package mypack.dpack;
import mypack.apack.*;
import mypack.bpack.*;
import mypack.cpack.*;
public class protectedDemo {
 
    public static void main(String[] args) {
        b ob = new b();
        c oc = new c();

        ob.disp();

        oc.disp();
    }
}

// Create a class temperature with member variable temp. Implement exception handling to test if temperature is equal to zero.
// Swetha Swaminathan12:26 PM
// done ma'am
// Mahalakshmi B S12:34 PM
// Implement a growable stack using interface and class. Interface will contain abstract methods push() and pop().