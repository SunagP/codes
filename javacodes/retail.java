package javacodes;
import java.util.Scanner;
import java.util.*;
public class retail {
    Scanner sc= new Scanner(System.in);
    int unit;
    float price;
    String desc;
    retail(){
     unit = 1;
     price = 1;

    }
    void desc(){
            //System.in is a standard input stream   
        System.out.println("Enter description of product :\n");
        desc = sc.next();
        

    }
    void input(){
        System.out.println("Enter Number of units :\n");
        unit = sc.nextInt();
        System.out.println("Enter price :\n");
        price = sc.nextFloat();
    }
    void disp(){
        System.out.println("Description of product : "+desc);
        System.out.println("Number of units : "+unit);
       
        System.out.println("total price : "+(unit*price));
       
    }
}
class mainfun{
    public static void main(String[] args){
        retail r = new retail();
        r.disp();
        r.desc();
        r.input();
        r.disp();

    }
}
