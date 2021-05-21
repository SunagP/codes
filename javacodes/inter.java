interface interface1{
public void print();
default void hi(){
    System.out.println("hi....");
}
}
interface interface2 extends interface1{
   public void disp();
}

final class abcd implements interface2{
 public void disp(){System.out.println("hi....");}
public void print(){System.out.println("hello....");}

}


public class inter {
    public static void main(String[] args){
        abcd obj = new abcd();
        obj.disp();
        obj.print();
    }
}
