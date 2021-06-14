package mypack;

public class myExcep extends Exception {
    
   

    String str1;
    /* Constructor of custom exception class
     * here I am copying the message that we are passing while
     * throwing the exception to a string and then displaying 
     * that string along with the message.
     */
    myExcep(String str2) {
     str1=str2;
    }
    public String toString(){ 
     return ("MyException Occurred: "+str1) ;
    }
 }
 
 class userDefException
 {
    public static void main(String args[]){
        try{
            System.out.println("Starting of try block");
            // I'm throwing the custom exception using throw
            throw new myExcep("This is My error Message");
        }
        catch(myExcep exp){
            System.out.println("Catch Block") ;
            System.out.println(exp) ;
        }
       }
    
}
