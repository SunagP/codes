import java.io.*;
import java.util.Scanner;

public class library
{
public static void main(String args[])
    {
        if(args.length==0)
    {
            System.out.println("error..file name cannot be empty\n");
            return;
    }
else
{
    try( FileInputStream  fin=new FileInputStream(args[0]);
         FileOutputStream fout=new FileOutputStream(args[0]);)
{
    Scanner sc =new Scanner(System.in);
    System.out.print("Enter 0 to stop entiring to the file..\n");
    System.out.print("Enter the Bookname : ");
    String b=sc.nextLine();
    System.out.print("Enter the Author : ");
    String a=sc.nextLine();

    while(!b.equals("0") && !a.equals("0"))
    {
        String content=b+" : "+a+"\n";
        byte[] x=content.getBytes(); 
        fout.write(x);
        System.out.print("Enter the Bookname : ");
        b=sc.nextLine();
        System.out.print("Enter the Author : ");
        a=sc.nextLine();
    }
    System.out.println("Library contents are : ");
    int i;
    while((i=fin.read())!=-1)
        System.out.print((char)i);
        sc.close();
    }
    catch(Exception e)
    {
        System.out.println("Error Occurred ..."+e.getMessage());
    } 
}
}
}

