import java.util.Scanner;

class Stack<E>
{
   E a[];
   int top;
   Stack()
   {
      a=(E[])new Object[100];

      top=-1;
   }
   void push(E data)
   {
      a[++top]=data;
   }
   E pop()
   {
      return a[top--];
   }
   boolean hasElements()
   {
      return top!=-1;
   }
 }

 class Student
 {
    String name;
    int standard;
    Student(String n,int s)
    {
       name=n;
       standard=s;
    }
    public String toString()
    {
       return name+" "+standard;
    }
 }
 class GenStack
 {
    public static void main(String arg[])
    {
       Stack<Integer> si=new Stack<Integer>();  
       Stack<Double> sd=new Stack<Double>();  
       Stack<Student> ss=new Stack<Student>(); 
       Scanner sc = new Scanner(System.in);
       int ch=1;
       while(ch!=0){
        System.out.println("Enter your choice :::\n1.int push\n2.double push\n3.obj push\n4.int pop\n5.double pop\n6.obj pop\n0.Exit");
        ch=sc.nextInt();
        switch(ch){
            case 1: System.out.println("Enter integer to push");
            int x = sc.nextInt();
            si.push(x);break;
            case 2: System.out.println("Enter double value to push");
            double y = sc.nextDouble();
            sd.push(y);break;
            case 3: System.out.println("Enter obj to push");
            System.out.println("Enter name ");
            String n = sc.next();
            System.out.println("Enter class ");
            int c = sc.nextInt();
            ss.push(new Student(n,c));break;

            case 4: System.out.println("popped integer : "+si.pop());break;
            case 5: System.out.println("popped double : "+sd.pop());break;
            case 6: System.out.println("popped student : "+ss.pop());break;

          
        }
    }
       
    }
 }
   