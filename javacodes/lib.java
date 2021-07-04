import java.io.*;
import java.util.Scanner;

class lib{
    int bookNo; String bookName, author, issueDate;
boolean issue=false;

lib(int n, String name, String a, String i)
{
issue = true;

bookNo = n;
bookName = name;
author =a;
issueDate = i;
}
lib(){}

void get()
{
Scanner sc = new Scanner(System.in);
Scanner in = new Scanner(System.in);
System.out.println("Enter book details...");

System.out.println("Enter book no : ");
bookNo = sc.nextInt();

System.out.println("Enter book name : ");
bookName = in.nextLine();

System.out.println("Enter author name : ");
author = sc.nextLine();

System.out.println("Enter issue date : ");
issueDate = in.nextLine();
sc.close();
in.close();
}

public String toString(){
return bookNo + "\n" + bookName + "\n" + author +"\n"+ issueDate +"\n"+ issue;
}
}
class FileIOlibrary{
public static void main(String args[]) {
try{

lib lib = new lib(123,"hello world", "swastika","20-20-2020");
lib.get();

FileOutputStream f = new FileOutputStream(new File("library.txt"));
ObjectOutputStream o = new ObjectOutputStream(f);


FileInputStream i = new FileInputStream(new File("library.txt"));
ObjectInputStream in = new ObjectInputStream(i);

System.out.println("Saving the entered details in a file");
o.writeObject(lib);

o.close();
f.close();

library libTemp = (library) in.readObject();

System.out.println("Data read from file\n");
System.out.println(libTemp.toString());

}

catch (FileNotFoundException e) {
            System.out.println("File not found");
        } catch (IOException e) {
            System.out.println("Error initializing stream");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
}
}



