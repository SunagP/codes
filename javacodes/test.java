public class test {
    int x,y;
    test(){
        x=10;
        y=20;
    }

    void math(test t){
        t.x *= 2;
        t.y /= 2;
    }
    void disp(){
        System.out.println(x);
        System.out.println(y);
    }
}
class maintest{
    public static void main(String[] args) {

        test t = new test();
        t.disp();
        t.math(t);
        t.disp();
    }
}