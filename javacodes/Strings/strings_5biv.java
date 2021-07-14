package Strings;

public class strings_5biv {
    
    public static void main(String args[])
    {
        String str="hello";
        String x=new String(str.substring(0,2)+'v'+str.substring(3));
        System.out.println("Original : "+str);
        System.out.println("Replaced : "+x);
    }
}
