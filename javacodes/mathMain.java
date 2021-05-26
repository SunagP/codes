// // Write an interface, called MyMath, for your own Math Library functions.
//  Create a new class called AdvancedMath 
//  that inherits standard Math class and implement MyMath interface.
// import java.lang.Math;
interface Mymath{
    void area(int x);
}
class AdvanceMath implements Mymath{
    int x;
    public void area(int x){
        System.out.println("Area is : "+x*x);
    }

}



public class mathMain {
    public static void main(String[] args){
    AdvanceMath a = new AdvanceMath();
    a.area(5);

    }
}
