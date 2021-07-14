import java.util.*;
class JavaExample{
   public static void main(String args[]){
     ArrayList<String> alist=new ArrayList<String>(); 
      alist.add("Steve");
      alist.add("Tim");
      alist.add("Lucy");
      alist.add("Pat");
      alist.add("Angela");
      alist.add("Tom");
//displaying elements
      System.out.println(alist);

      //Removing "Steve" and "Angela"
      alist.remove("Steve");
      alist.remove("Angela");
 
 //displaying elements
      System.out.println(alist);

      //Removing 3rd element
      alist.remove(2);

      //displaying elements
      System.out.println(alist);

      for(String str:alist)  
        System.out.println(str);  

        System.out.println(alist.size());
        alist.set(1,"xyzz");  

        for(String str:alist)  
        System.out.println(str);  
        System.out.println(alist.size());


          //Sorting the list  
          Collections.sort(alist);  
          //Traversing list through the for-each loop  
          for(String str:alist)  
          System.out.println(str);  
   }
}

public class arrayList {
    
}
