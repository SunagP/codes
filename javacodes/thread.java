public class thread{
   public static void main(String[] args) {
       t1 t = new t1();
      //  t1 to = new t1();
       Thread th = new Thread(t);
      
       th.start();
      //  th1.start();
       
        for(int i=0;i<4;i++){
            System.out.println("* "+i+" hi 1st task");
            

        }
        
    }

}

class t1 implements Runnable{
  public void run()
  {
    for(int j=0;j<6;j++){
        System.out.println("+ "+j+" hello 2nd task");
    }
  }

//   public void run1()
//   {
//     for(int j=0;j<6;j++){
//         System.out.println("+ "+j+" ++++++++");
//     }
//   }
}
