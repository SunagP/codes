// import java.lang.*;
class JavaFinally
{
   public static void main(String args[])
   {
     JavaFinally.myMethod();  
   }
   public static void myMethod()
   {
      try {
        // System.exit(12);
        // return 112;
        for (int i = 0; i < 5; i++) {
            if (i > 3) {
              break;
              
            }
            System.out.println(i);
            
          }

        //   return 0;
       
      }
      finally {
        System.out.println("This is Finally block");
        System.out.println("Finally block ran even after return statement");
      }
   }
}