import java.util.Scanner;

public class studInherit {
    String name;
    int id;
    Scanner sc = new Scanner(System.in);
    void input()
    {
      System.out.println("Enter name :");
      name  = sc.next();
      System.out.println("Enter id :");
      id = sc.nextInt();


    }

    void disp(){
        System.out.println("Name : "+name);
        System.out.println("Id : "+id);
    }
}

class exam extends studInherit{
    int m[] = new int[6];
    Scanner sc = new Scanner(System.in);
    void setmarks(){
        System.out.println("Enter marks in 6 Subjects : ");

        for(int i=0;i<6;i++){
        m[i] = sc.nextInt();
       
        }
    }
    void dispmarks(){
        System.out.println("marks scored in 6 Subjects : ");

        for(int i=0;i<6;i++){
       System.out.println("subject "+(i+1)+" : "+m[i]);
        }
    }
    
}
class result extends exam{
    int total = 0;
    
    void dispres(){
        for (int i =0;i<6;i++){
        total += m[i];
        }
        int avg = total/6;
        System.out.println("Total marks scored in 6 subjects : "+total);
        System.out.println("Average marks scored in 6 subjects : "+avg);

        if(avg>=90 && avg<=100)
        {
            System.out.println("Grade : S");
        }
        if(avg>=80&&avg<90)
        {
            System.out.println("Grade : A");
        }
        if(avg>=60&&avg<80)
        {
            System.out.println("Grade : B");
        }
        if(avg>=50&&avg<60)
        {
            System.out.println("Grade : C");
        }
    }
}

class testSt{
    public static void main(String[] args){
        result r = new result();
        r.input();
        r.setmarks();

        r.disp();
        r.dispmarks();
        r.dispres();
    }
}