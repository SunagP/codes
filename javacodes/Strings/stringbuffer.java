package Strings;
import java.io.*;
class stringbuffer {
    public static void main(String[] args)
    {
        StringBuffer x=new StringBuffer(); 
        //(oldcap*2)+2 
        //(oldcap+1)*2  
        // System.out.println(x.capacity()); 
        // x.append("1");    
        // System.out.println(x.capacity()+" "+x.length());  
        // x.append("23");    
        // System.out.println(x.capacity()); 
        x.append("345678910123456789");

        System.out.println(x);
        System.out.println(x.capacity()); 
        x.append("345678910123456789");

        System.out.println(x);
        System.out.println(x.capacity());    
        StringBuffer sb = new StringBuffer("abcdefghijk");
        // String sb ="abcd";
        sb.insert(3, "123");
        System.out.println(sb); 
    }
}
