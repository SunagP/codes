import java.util.Scanner;
import java.util.ArrayList;
interface operations
{
    void pop();
    void push(int a);
    void displayTop();
}
    class stack2{
    ArrayList<Integer> stack=new ArrayList<Integer>();
    int currentSize=0;
    void push(int a)
    {
        stack.add(a);
        currentSize++;
    }
    void pop()
    {
        if(stack.isEmpty()==true)
        {
            System.out.println("stack is empty cant pop");
        }
        else
        {
            System.out.println(stack.get(currentSize-1)+" is poped");
            stack.remove(currentSize-1);
            currentSize--;
        }
    }
    void displayTop()
    {
       
        if(stack.isEmpty()==true)
        {
            System.out.println("stack is empty cant pop");
        }
        else
        {
            System.out.println(stack.get(0));
        }
    }
}
public class stack1
{
    public static void main(String[] args)
    {
        stack2 S=new stack2();
        Scanner sc=new Scanner(System.in);
        int x=1;
        do
        {
            System.out.println("enter 0 to exit");
            System.out.println("enter 1 to push");
            System.out.println("enter 2 to pop");
            System.out.println("enter 3 to display top element");
            x=sc.nextInt();

            switch(x)
            {
                case 1 : int n;
                         System.out.println("enter element to be pushed:");
                         n=sc.nextInt();
                         S.push(n);
                break;
                case 2 : S.pop();
                break;
                case 3 : S.displayTop();
                break;
                case 0 : break;
            }
        } while(x!=0);
        sc.close();
    }
}