package Strings;

public class strings_5bvi {
    public static void main(String args[])
    {
        // String s1= "hello world";
        // String s2= "hello world";
        // String s3= "bms college";
        // System.out.println(s1==s2);
        // System.out.println(s1==s3);
        // System.out.println("s1 equals s2 : "+s1.equals(s2));
        // System.out.println("s1 equals s3 : "+s1.equals(s3));
        // System.out.println("s1 comparing with s2 : "+s1.compareTo(s2));
        // System.out.println("s1 comparing with s3 : "+s1.compareTo(s3));

        String s1="Sachin";  
        String s2="Sachin";  
        String s3="Ratan";  
        System.out.println(s1.compareTo(s2));//0  
        System.out.println(s1.compareTo(s3));//1(because s1>s3)  
        System.out.println(s3.compareTo(s1));//-1(because s3 < s1 )  
    }
}
