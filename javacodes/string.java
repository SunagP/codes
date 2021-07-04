public class string {
    public static void main(String[] args) {
        String s1 = "hello";
        String s2 = "hello";
        // s1 = "hi";
        String s3 = new String("hi");
        String s4 = new String("hi");
       
        System.out.println(s1);
        System.out.println(s2);
        System.out.println(s3.equals("hi"));
        // System.out.println(s3==s2);
        // System.out.println(s3==s4);
        // System.out.println(s1.intern());
    }
}
