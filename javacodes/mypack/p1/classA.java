package mypack.p1;
public class classA {

    private int x;
    public void displayA( )
	{ 
	System.out.println("Class A "+x);
	}
    protected void disp(){
        System.out.println("protected method");
    }

    public class x{
        
        private int a=10;
        protected int b = 5;
        public int c = 4;
        public void displayx( )
	{ 
	System.out.println("Class x "+a+" "+b);
	}
    }
}

class ex{

    public static void main(String str[])
	{
    classA a = new classA();
    a.disp();
    }
    
}

abstract class abc{

}

class Main{
    public static void main(String str[])
	{
		classA obA=new classA();
		obA.displayA();
	}
}
