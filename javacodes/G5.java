import java.io.*;  
class G5{  
public static void main(String args[])throws Exception{  
  
 InputStreamReader r=new InputStreamReader(System.in);  
 BufferedReader br=new BufferedReader(r);  
  
 String str="";  
  
 do {
    str = br.readLine();
    System.out.println(str);
    } while(!str.equals("stop"));
    } 
  
//  br.close();  
//  r.close();  
 }  

