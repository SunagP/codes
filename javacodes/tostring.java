public class tostring {
    
}
class Studentx{  
    int rollno;  
    String name;  
    String city;  
      Studentx(int rollno, String name, String city){  
    this.rollno=rollno;  
    this.name=name;  
    this.city=city;  
    }
    public String toString(){//overriding the toString() method  
        return rollno+" "+name+" "+city;   }      
   
   public static void main(String args[]){  
      Studentx s1=new Studentx(101,"Raj","lucknow");  
      Studentx s2=new Studentx(102,"Vijay","ghaziabad");  
        
      System.out.println(s1);//compiler writes here s1.toString()  
      System.out.println(s2);//compiler writes here s2.toString()  
    } 
}