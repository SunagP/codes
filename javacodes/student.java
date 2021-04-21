// package javacodes;
import java.util.Scanner;
import java.util.*;
public class student {
    int id;
    String name;
    int m1,m2,m3;
    float avg;

    void input(){
        Scanner sc= new Scanner(System.in);    //System.in is a standard input stream  
        System.out.print("Enter id : ");  
        id = sc.nextInt();

        System.out.print("Enter name : ");
        name = sc.next();

        System.out.print("Enter marks in subjects 1 : ");  
        m1 = sc.nextInt();
        System.out.print("Enter marks in subjects 2 : ");
        m2 = sc.nextInt();
        System.out.print("Enter marks in subjects 3 : ");
        m3 = sc.nextInt(); 
        
        
    }
    // void input(int id,String){

    // }

    void disp(){
        
        System.out.println("Student id :"+id+"\n");
        System.out.println("Student id :"+name+"\n");
        System.out.println("Average of 3 subjects :"+((m1+m2+m3)/3.0)+"\n");
    }
}

class Main{
    public static void main(String[] args){
 
   student s = new student();
   s.input();
   s.disp(); 
   

    }}
