import java.util.Scanner;

public class fruits {
  int price;
  float q,t;
  Scanner sc = new Scanner(System.in);

  void read(){
      System.out.println("Enter unit price : ");
      price = sc.nextInt();
      System.out.println("Enter quantity in kg : ");
      q = sc.nextFloat();

  }
  void total(){
    t = price*q;

    System.out.println("Total amount to be paid : "+t);
  }
  void disp(){
    System.out.println("unit price : "+price);
      
    System.out.println("quantity required in kg : "+q);

    
  }

}

class mango extends fruits{
    String name,taste;
    void readm(){
        System.out.println("Enter type of mango : ");
        name = sc.next();
        System.out.println("What is the taste of it?? : ");
        taste = sc.next();
  
    }

    void makeJuice(){
        if(taste.equals("sweet")){
            System.out.println("Woah..! it's best suited for making juices");
            System.out.println("do you want to try it??y/n");
            String ch = sc.next();

            if(ch.equals("y")){
                System.out.println("Enter number glasses you want");
                int qu = sc.nextInt();

                System.out.println("Total bill amount :"+(qu*45));
            }
            if(ch.equals("n")){
                System.out.println("Thank you !!!");
                
            }

        }
        if(taste.equals("sour")){
            System.out.println("It's not best suited for making juices");
        }
        // else{
        //     System.out.println("cannot make juice with this taste");
        // }
    }


}

class testfruit{
    public static void main(String[] args){

        mango m = new mango();

        m.read();
        m.disp();
        m.total();

        m.readm();
        m.makeJuice();
    }
}
