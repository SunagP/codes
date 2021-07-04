class multen extends Thread
{
    public void run()
    {
        for(int i=1;i<=100;i++)
        {
            if(i%10==0)
                System.out.println("Multiple of 10 - "+i);
        }
    }
}

class even extends Thread
{
    public void run()
    {
        for(int i=1;i<=100;i++)
        {
            if(i%2==0)
             System.out.println("even number - "+i);
        }
    }
}

class mulfive extends Thread
{
    public void run()
    {
        for(int i=1;i<=100;i++)
        {
            if(i%5==0)
                System.out.println("Multiple of 5 - "+i);
        }
    }
}

public class threeThread
{
public static void main(String args[])
    {
    multen obj1 = new multen();
    even obj2 = new even();
    mulfive obj3 = new mulfive();

    obj1.start();
    obj2.start();
    obj3.start();

    System.out.println("Thread 1 IS "+obj1.isAlive());
    System.out.println("Thread 2 IS "+obj2.isAlive());
    System.out.println("Thread 3 IS "+obj3.isAlive());

    try{
        obj1.join();
        obj2.join();
        obj3.join();
    }
    catch(Exception e)
    {
        System.out.println(e);
    }
    System.out.println("main is the last to execute");

    }
}