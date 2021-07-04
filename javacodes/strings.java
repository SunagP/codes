import java.nio.charset.Charset;

public class strings {
    

  public static void main(String Args[])
  {
//     char c[]={'j','a','v','a'};
//     String s1=new String(c);
//     String s2=new String(s1);
//    System.out.println(s1);
   
//    System.out.println(s1.hashCode());

//    System.out.println(s2);
//    System.out.println("abc".hashCode());

   byte[] b = {65,66,99};
   
   Charset c = Charset.defaultCharset();
//    String s = new String(b, "US-ASCII");
    try {
        String s = new String(b, "US-ASCII");
        System.out.println(s);
    } 
    catch (Exception e) {
        System.out.println(e);
    }
  
   String s3=new String(b,c);
   System.out.println(s3);
   
  int x = 5;

  String y = "hi "+x+" hello";
  System.out.println(y);



}
}

