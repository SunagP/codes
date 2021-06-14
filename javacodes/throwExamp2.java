
import java.io.*;
class throwExamp2 { 
  void myMethod(int num)throws IOException, ClassNotFoundException{ 
     if(num==1)
        throw new IOException("IOException Occurred");
     else
        throw new ClassNotFoundException("ClassNotFoundException");
  } 
} 

 class Example1{ 
  public static void main(String args[]){ 
   try{ 
    throwExamp2 obj=new throwExamp2(); 
     obj.myMethod(0); 
   }catch(Exception ex){
     System.out.println(ex);
    } 
  }
}