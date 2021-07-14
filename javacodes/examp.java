
import java.util.ArrayList;
import java.util.List;
import java.util.*;
  
public class examp {
  
    public static void main(String[] args) {
        
        String str[] = { "Apple", "Banana" };
        List<String> list = Arrays.asList(str); 
       
        List<String> l = new ArrayList<>(list);
          
  
        l.add("Mango"); // modify the list
  
        for(String s: l )
          System.out.println(s);
  
    }
  
}