import java.util.Scanner;
import java.util.ArrayList;
    class queue<T>
    {
    ArrayList<T> q=new ArrayList<T>();
    int currentSize=0;
    void enqueue(T a)
    {
        q.add(a);
        currentSize++;
    }
    void dequeue()
    {
        if(q.isEmpty()==true)
        {
            System.out.println("queue is empty cant dequeue");
        }
        else
        {
            System.out.println(q.get(0)+" is dequed");
            q.remove(0);
            currentSize--;
        }
    }
}
class QueueGrowable
{
    public static void main(String[] args)
    {
        queue<Integer> S=new queue<Integer>();
        queue<Double> S2=new queue<Double>();
        queue<String> S3=new queue<String>();
        Scanner sc=new Scanner(System.in);
        int x,y;
        System.out.println("enter 1 for integer");
        System.out.println("enter 2 for double");
        System.out.println("enter 3 for string");
        y=sc.nextInt();
        if(y==1){    
        do
        {
            System.out.println("enter 0 to exit");
            System.out.println("enter 1 to enqueue");
            System.out.println("enter 2 to dequeue");
            // System.out.println("enter 3 to display top element");
            x=sc.nextInt();
            
            switch(x)
            {
                case 1 : int n;
                System.out.println("enter element to be pushed:");
                n=sc.nextInt();
                S.enqueue(n);
                break;
                case 2 : S.dequeue();
                break;
                // case 3 : S2.displayTop();
                // break;
                case 0 : break;
            }
        } while(x>0);
    }
        if(y==2){
        do
        {
            System.out.println("enter 0 to exit");
            System.out.println("enter 1 to enqueue");
            System.out.println("enter 2 to dequeue");
            // System.out.println("enter 3 to display top element");
            x=sc.nextInt();
            
            switch(x)
            {
                case 1 : double n;
                System.out.println("enter element to be pushed:");
                n=sc.nextDouble();
                S2.enqueue(n);
                break;
                case 2 : S2.dequeue();
                break;
                // case 3 : S2.displayTop();
                // break;
                case 0 : break;
            }
        } while(x>0);
    }
        if(y==3){
        do
        {
            System.out.println("enter 0 to exit");
            System.out.println("enter 1 to enqueue");
            System.out.println("enter 2 to dequeue");
            // System.out.println("enter 3 to display top element");
            x=sc.nextInt();
            
            switch(x)
            {
                case 1 :
                String n;
                System.out.println("enter element to enqueue:");
                n=sc.next();
                S3.enqueue(n);
                break;
                case 2 : S3.dequeue();
                break;
                // case 3 : S3.displayTop();
                // break;
                case 0 : break;
            }
        } while(x>0);
    }

    }
    }