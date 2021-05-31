// public class excep {
    
      
//         public static void main(String args[]){
              
//             String str = null;
//             System.out.println(str.length());
              
//         }
//     }
// public class excep {
//     public static void main(String[] args) {
//         try {
//           int[] myNumbers = {1, 2, 3};
//           System.out.println(myNumbers[10]);
//         } 
//         // catch (Exception e) {
//         //   System.out.println("Something went wrong.");
//         // } 
//         finally{
//           System.out.println("The 'try catch' is finished.");
//         }
//       }
//   }
// public class excep{
//   static void checkAge(int age) {
      
//     if (age < 18) {
//       throw new ArithmeticException("Access denied - You must be at least 18 years old.");
//     }
//     else {
//       System.out.println("Access granted - You are old enough!");
//     }
//   }

//   public static void main(String[] args) {
//     checkAge(15); // Set age to 15 (which is below 18...)
//   }
// }
public class excep{
    public static void main(String[] args) {  
          
        try{    
             int a[]=new int[5]; 
             a[5]=30/0; 
            //  System.out.println(a[10]); 
            //  try{
            // //   
            //  System.out.println(a[10]); 
            // }    
            }    
            catch(ArithmeticException e)  
               {  
                System.out.println("Arithmetic Exception occurs");  
               }    
            catch(ArrayIndexOutOfBoundsException e)  
               {  
                System.out.println("ArrayIndexOutOfBounds Exception occurs");  
               }    
            catch(Exception e)  
               {  
                System.out.println("Exception occurs");  
               } 
               finally{
                System.out.println("hiiiiiii");  
               }            
           
 }  
}