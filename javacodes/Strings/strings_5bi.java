package Strings;

public class strings_5bi {
    public static void main(String args[])
    {
        char[] arr={'a','b','c','d','e','f'};
        System.out.println(arr);
        String arr_str=new String(arr);
        System.out.println(arr_str);
        String sub_arr=new String(arr,2,3);
        System.out.println(sub_arr);
        String str_obj=new String(arr_str);
        System.out.println(str_obj);
    }
}
