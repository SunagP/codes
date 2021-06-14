
    import java.io.*;
public class new1 {


   
      
        public static void main(String[] args)
            throws NoClassDefFoundError
        {
      
            try {
                Class temp = Class.forName("gfg"); // calling the gfg class
            }
            catch (ClassNotFoundException e) {
                // block executes when mention exception occur
                System.out.println("Class does not exist check the name of the class");
            }
        }
    }  

