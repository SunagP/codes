
import java.io.*;  
class file{  
public static void main(String args[])throws Exception{  
FileInputStream fin=new FileInputStream("C:/Users/Asus/Videos/Captures/invisible.mp4");  
FileOutputStream fout=new FileOutputStream("new.mp4");  
int i=0;  
while((i=fin.read())!=-1){  
fout.write((byte)i);  
}  
fin.close();  
}  
}  