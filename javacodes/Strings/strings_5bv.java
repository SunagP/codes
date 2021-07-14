package Strings;

public class strings_5bv {
    public static void main(String args[])
    {
        String str="This is java programming";
        int len=str.length();
        System.out.println(len);
        char[] ch=new char[len];
        str.getChars(0,len,ch,0);
        System.out.println(ch);
    }
}
