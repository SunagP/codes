// package javacodes;
import java.util.Scanner;
class bank
{
    Scanner sc=new Scanner(System.in);
    String name,accNum;
    int bal=0;
    void read()
    {
        
        System.out.println("Enter customer name: ");
        name=sc.next();
        System.out.println("Enter account number: ");
        accNum=sc.next();
    }
    void disp()
    {
        System.out.println("name: "+name);
        System.out.println("account number: "+accNum);
        System.out.println("Current Balance: "+bal);
    }
    void deposit()
    {
        // Scanner sc=new Scanner(System.in);
        System.out.println("enter amount to be deposited: ");
        int d=sc.nextInt();
        bal=bal+d;
        System.out.println(d+" deposited");
    }
    void withdraw()
    {
        // Scanner sc=new Scanner(System.in);
        System.out.println("enter amount to be withdrawn: ");
        int w=sc.nextInt();
        if(bal>=w)
        {
            bal=bal-w;
            System.out.println(w+" withdrawn");
        }
        else
        {
            System.out.println("low balance cannot withdraw");
        }
    }

}
class bankMain
{
    public static void main(String[] args)
    {   Scanner sc=new Scanner(System.in);
        bank b=new bank();
        b.read();
        b.disp();
        // b.deposit();
        // b.disp();
        // b.withdraw();
        // b.disp();
        int ch=1;
        while(ch!=0){
        System.out.println("Enter your choice :::\n1.Withdrawl\n2.Deposit\n3.Display\n0.Exit");
        ch=sc.nextInt();
        switch(ch){
          case 1: b.withdraw();break;
          case 2: b.deposit();break;
          case 3: b.disp();break;
          case 0:break ;
        }
    }sc.close();
        
    }
}