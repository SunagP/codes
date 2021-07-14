public class stringsAll {
    public static void main(String[] args) {
        //5bi
        char[] arr={'a','b','c','d','e','f'} ;
        String s=new String(arr);  

        System.out.println(s);
        String sub_arr=new String(arr,2,3);
        System.out.println(sub_arr);
        String str_obj=new String(s);
        System.out.println(str_obj);


    }
}
