import java.io.*;  

class fileCopy {  
 public static void main(String arg[]) throws Exception {   
  FileReader fin = new FileReader("abc.txt");  
  FileWriter fout = new FileWriter("sunag.txt", true);  
  int c;  
  while ((c = fin.read()) != -1) {  
   fout.write(c);  
  }  
  System.out.println("Copy finish...");  
  fin.close();  
  fout.close();  
 }  
} 
