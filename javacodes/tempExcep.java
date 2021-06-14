import java.util.Scanner;

public class tempExcep {
     
        static void checkTemp(int temp) {
          if (temp == 0) {
            throw new ArithmeticException("temperature is 0");
          }
          else {
            System.out.println("temperature is "+temp);
          }
        }
      
        public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
          System.out.println("Enter temperature");
          int temp = sc.nextInt();
          checkTemp(temp); 
          sc.close();
        }
      
}
