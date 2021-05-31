package mypack.p2;
import mypack.p1.*;
public class classB extends classA
{
	protected int m =10;
	public void displayB()
	{
	System.out.println("Class B");
	System.out.println("m= "+m);
	}


	public static void main(String str[])
	{
		classA obA=new classA();
		obA.displayA();
		classB obB=new classB();
		obB.displayB();
	    classA.x a1 = obA.new x(); 
		a1.displayx();
		a1.c = 5;
		 classB b1 = new classB();

		 b1.disp();
		// a1.b = 6;

		 
	}
	    
}



