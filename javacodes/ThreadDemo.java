// Create a second thread. 
// class NewThread implements Runnable {   
    class NewThread extends Thread{
    // Thread t; 
    // NewThread t1  ;
    NewThread(String x) {   
 // Create a new, second thread    
    // t = new Thread(this, "Demo Thread"); 
    
    // System.out.println("Child thread: " + t);    
    // t.start(); // Start the thread   
    super(x);
    System.out.println("Child thread: " + this);
    start();
} 
 // This is the entry point for the second thread. run() can call other //metods, use other classes and declare variables just like the main //thread can.The thread will end when run() returns. 
   public void run()
    {     
        try {       
            for(int i = 5; i > 0; i--) 
            {         
                System.out.println("Child Thread: "+ i );         
                Thread.sleep(500);       }     
            } 
                catch (InterruptedException e) 
                {       
                    System.out.println("Child interrupted.");     
                }     
                System.out.println("Exiting child thread.");   
            }
} 
class ThreadDemo {  
public static void main(String args[ ] ) 
{ 
   new NewThread("child 1");
   new NewThread("child 2"); 
   new NewThread("child 3");// create a new thread 
   try {       
         for(int i = 5; i > 0; i--) 
        { 
        System.out.println("Main Thread: " + i);                     
        Thread.sleep(1000);  
       } 
       } catch (InterruptedException e) 
       { 

System.out.println("Main thread interrupted.");     
}        
System.out.println("Main thread exiting.");   
} 
} 