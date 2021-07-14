package Strings;

public class strings_5bvii {
    public static void main(String args[])
    {
        String s1="good morning";
        String s2="morning is started";

        System.out.println(s1.contains("good"));
        System.out.println(s2.contains("good"));

        //viii Extract a substring good in the string s2=”good morning”

        String str="good morning";
        String substr=str.substring(0,4);
        System.out.println(substr);

        //ix Replace Hello with greetings in the given string s1=”hello world”
        String h = "hello world";
        String replace=h.replace("hello","greetings");
        System.out.println(replace);

        //x Eliminate spaces in the string s1=”Hello BMSCE Good Morning”
        String s="Hello BMSCE Good Morning";
        System.out.println(s.replaceAll(" ",""));


        // xi Join the string s1={ “xyz”,24} with email id and phone number
        String s3[]={"xyz","24"};
        String email=String.join("@","sunag",s3[0]);
        String no=String.join("","01234567",s3[1]);
        System.out.println(email);
        System.out.println(no);


        String x = "bms";
        x = x.concat("! is the best.");

        x.concat("! is the best."); 
        System.out.println(x);
    }
}
