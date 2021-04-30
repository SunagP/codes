// import jdk.javadoc.internal.tool.Main;
import java.util.Scanner;
public class car {
    int model;
    String method;
    double speed;

    car(int x,String y,double z){
        model = x;
        method = y;
        speed = z;

    }
    car(){
        model = 2010;
        method = "sedan";
        speed = 50;
    }
    void input(){
        Scanner sc = new Scanner(System.in);
        System.out.println("model of car :");
        model = sc.nextInt();
        System.out.println("Method of car :");
        method = sc.next();
        System.out.println("speed of car in kmph :");
        speed = sc.nextDouble();
        sc.close();
    }
    void accelerate(){
        speed += 5;
        System.out.println("Accelerated by 5 kmph");
        
    }
    void br(){
        speed -= 5;
        System.out.println("decelerated by 5 kmph");
    }

    void disp(){
        System.out.println("model of car :"+model);
        System.out.println("Make of car :"+method);
        System.out.println("speed of car :"+speed+" kmph");
    }
    void dispspeed(){
        // System.out.println("model of car :"+model);
        // System.out.println("Method of car :"+method);
        System.out.println("current speed of car :"+speed+" kmph");
    }
}


class carmain{
    public static void main(String[] args){
        car c = new car(2020,"suv",90.0);
        car c1 = new car();

        c.disp();
        System.out.println("\naccelerate method is called......\n");
        for(int i = 0;i<5;i++)
        {
            c.accelerate();
            c.dispspeed();
        }
        System.out.println("\nbreak method is called......\n");
        for(int i = 0;i<5;i++)
        {
            c.br();
            c.dispspeed();
        }
        c1.input();
        c1.disp();

        int ch = 1;
        while(ch!=0){
         System.out.println("1.accelerate\n2.break\n3.display\n0.Exit");
         Scanner sc = new Scanner(System.in);
         ch = sc.nextInt();
         switch(ch){
             case 0: break;
             case 1: c1.accelerate();c1.dispspeed();break;
             case 2 :c1.br();c1.dispspeed();break;
             case 3: c1.disp();
             sc.close();
         }
        }
    }
}