package Strings;

class OverrideToString
{
    public String toString()
    {
        String str="good morning";
        return str;
    }
}
class strings_5biii
{
    public static void main(String args[])
    {
        OverrideToString o=new OverrideToString();
        String str="hello world";
        System.out.println("Original : "+str);
        str=o.toString();
        System.out.println("Overrided : "+str);
    }
}
