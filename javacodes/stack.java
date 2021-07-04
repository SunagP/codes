// import java.util.Scanner;
// public class stack {
//     int max = 10;
//     int arr[] = new int[max];
//     int top;
//     stack(){
//         top = -1;
//     }
//     void push(int x)
//     {
//         if (top >= (max - 1)) {
//             System.out.println("Stack Overflow");
           
//         }
//         else {
//             top++;
//             arr[top] = x;
//             System.out.println(x + " pushed");
           
//         }
//     }
 
//     void pop()
//     {
//         if (top < 0) {
//             System.out.println("Stack Underflow");
            
//         }
//         else {
//             int x = arr[top--];
//             System.out.println(x+" popped");
//         }
//     }
//     void disp()
//     {
//         if (top < 0) {
//             System.out.println("Stack Underflow");
            
//         }
//         else{
//             System.out.println("Stack elements are :");
//             for(int i =0;i<top;i++)
//             {
//                 System.out.println(arr[i]);
//             }
//         }

//     }

// }

// class stackmain{
//     public static void main(String[] args) {
//         stack s = new stack();
//         Scanner sc = new Scanner(System.in);
//         int ch = 1;
//         while(ch!=0)
//         {
//             System.out.println("Enter choice:\n1.push\n2.pop\n3.display\n0.Exit");
//             ch = sc.nextInt();
//             switch(ch){
//               case 0:break;
//               case 1: System.out.println("Enter element to push");
//                       int x = sc.nextInt();
//                       s.push(x);break;
//               case 2:  s.pop();
//               break;
//               case 3: s.disp();
                  
//             }
//         }
//         // s.push(6);
//         // int x = s.pop();
//         // System.out.println(x+" popped");
//     sc.close();}
// }
