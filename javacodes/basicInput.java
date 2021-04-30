import java.util.Scanner;

public class basicInput {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter name :");
    String name = sc.next();
    System.out.println("Enter age :");
    int age = sc.nextInt();

    System.out.println("Enter salary :");

    double sal = sc.nextDouble();

    System.out.println("name :"+name);
    System.out.println("age :"+age);
    System.out.println("salary :"+sal);

    sc.close();


        
    }
}
