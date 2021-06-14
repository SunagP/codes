class count{
    int c;

    public  void  increment(){
        c++;
        
    }

}
public class counter{
     public static void main(String[] args) {
        count c =  new count();
        Thread t1 = new Thread(new Runnable() {
            
            public  void  run(){
                for(int i=0;i<5;i++){
                    c.increment();
                    System.out.println("value t1 : "+c.c);

                }
               
            }
        });t1.start();
        try
        {
            t1.join();
            // t1.sleep(1000);
        }
        catch(InterruptedException e) 
        {       
         System.out.println("Interrupted");     
        } 

       
       

        Thread t2 = new Thread(new Runnable() {
            
            public  void  run(){
                for(int i=0;i<10;i++){
                    c.increment();
                    System.out.println("value t2 : "+c.c);

                }
            }
        });t2.start();

        // c.increment();
        // c.increment();
        // System.out.println("value : "+c.c);
    }
        
    }
