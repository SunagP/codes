class child extends Thread
{
        public void run()
        {
        for(int i=0;i<10;i++)
        {
            System.out.println(i+" child Thread");
        }
}
}

class child2 implements Runnable
{
    public void run()
        {
        for(int i=0;i<10;i++)
        {
            System.out.println(i+" child Thread");
        }
        }
}

public class childThread
{
public static void main(String args[])
{

// child c = new child();

child2 t = new child2();
Thread c = new Thread(t);

        c.start();
        try{
        c.join();
        }
        catch(Exception e)
        {
        System.out.println(e);
        }

        for(int i=0;i<10;i++)
        {
        System.out.println(i+" parent Thread");
}
}
}