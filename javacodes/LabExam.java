class OverrideToString
{
    public String toString()
    {
        String str="good morning";
        return str;
    }
}


public class LabExam {
    public static void main(String args[])
    {  //i)
        char[] arr={'a','b','c','d','e','f'};
        System.out.println(arr);
        String arr_str=new String(arr);
        System.out.println(arr_str);
        String sub_arr=new String(arr,2,3);
        System.out.println(sub_arr);
        String str_obj=new String(arr_str);
        System.out.println(str_obj);

        //ii)
        String str1="hello world";
        String str2="bms college";
        String str=str1+str2;
        System.out.println(str);



        //iii) overriding
        OverrideToString o=new OverrideToString();
        String str3="hello world";
        System.out.println("Original : "+str3);
        str3=o.toString();
        System.out.println("Overrided : "+str3);

        //iv) Assign a diiferent char at pos 2 in a string “hello”
        String str4="hello";
        String x=new String(str.substring(0,2)+'v'+str4.substring(3));
        System.out.println("Original : "+str4);
        System.out.println("Replaced : "+x);



        //v) Convert the string “ This is java programming” to array of characters
        String str5 = "this is java programming";

        arr = str5.toCharArray();
        System.out.println(arr);

        //vi) comparing

        String s1= "hello world";
        String s2= "hello world";
        String s3= "bms college";
        System.out.println(s1==s2);
        System.out.println(s1==s3);
        System.out.println("s1 equals s2 : "+s1.equals(s2));
        System.out.println("s1 equals s3 : "+s1.equals(s3));
        System.out.println("s1 comparing with s2 : "+s1.compareTo(s2));
        System.out.println("s1 comparing with s3 : "+s1.compareTo(s3));


        //vii) To search a good in a string s1=”good morning” and s2=”morning is started”
        String s4="good morning";
        String s5="morning is started";

        System.out.println(s4.contains("good"));
        System.out.println(s5.contains("good"));


        //viii Extract a substring good in the string s2=”good morning”

        String str6="good morning";
        String substr=str6.substring(0,4);
        System.out.println(substr);

        //ix Replace Hello with greetings in the given string s1=”hello world”
        String h = "hello world";
        String replace=h.replace("hello","greetings");
        System.out.println(replace);

        //x Eliminate spaces in the string s1=”Hello BMSCE Good Morning”
        String s="Hello BMSCE Good Morning";
        System.out.println(s.replaceAll(" ",""));


        // xi Join the string s1={ “xyz”,24} with email id and phone number
        String s7[]={"xyz","24"};
        String email=String.join("@","sunag",s7[0]);
        String no=String.join("","01234567",s7[1]);
        System.out.println(email);
        System.out.println(no);


        //Modification
        StringBuilder sb = new StringBuilder("hello");
        sb.setCharAt(2,'v');
        System.out.println(sb);

        //concate

        String a = "hello world ";
        String b = "BMS";
        System.out.println(a.concat(b));

    }
}
