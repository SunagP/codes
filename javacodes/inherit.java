class A1{
    private int a,b;
    protected float c,d;
    public int e,f;
    public A1(){
       a = b=1;
       c=d=2;
       e=f=3;
    }
    public A1(int x,int y,float z){
        a=b=x;
        c=d=z;
        e=f=y;
     }

     void disp(){
         System.out.println("Base class display");
         System.out.println("a : "+a+" "+" b : "+b+" c : "+c+" d :"+d+" e :"+e+" f :"+f);

     }
}

class B1 extends A1{
    int x,y,z;
    public B1(){
       super();
    //    System.out.println("Deriver class");
    }
    
    void disp(){
        super.c = 2.5f;
        super.d = 3.5f;
        System.out.println("Derived class B1 display");
        System.out.println("Modified base class c,d values using super key word \nc : "+super.c+"\nd : "+super.d);

        super.disp();

    }
    
}
final class C1 extends B1
{
  final void disp(){
    System.out.println("Derived class C1 display");
    // super.disp();

}
}
final class D1 extends B1
{
  final void disp(){
    System.out.println("Derived class D1 display");
    // super.disp();

}
}




public class inherit {
    public static void main(String[] args) {
        A1 a = new A1();
        B1 b = new B1();
        C1 c = new C1();
        D1 d = new D1();

        a.disp();
        b.disp();
        c.disp();
        d.disp();

        A1 a1 = new A1(1 ,2,3.2f);

        a1.disp();

        
    
    }
    
}
