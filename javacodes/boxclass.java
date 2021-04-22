
public class boxclass {
    
        double h,w,d;
        boolean a;
        int b;
        String c;
        boxclass(){
            h=2;
            w=5;
            d=6;
        }
        boxclass(double x,double y,double z){
            h=x;
            w=y;
            d=z;
        }
        void setDim(double x,double y,double z){
            h=x;
            w=y;
            d=z;
        }
        double vol(){
            // System.out.println("volume is "+h*w*d+"\n");
            return (h*w*d) ;
        }
    
    
}
class demo{
    public static void main(String[] args) {
        boxclass b1 = new boxclass();
        boxclass b2 = new boxclass();
        boxclass b3 = new boxclass();
        boxclass b4 = new boxclass(5,5,5);
       double x= b3.vol();
       double y= b4.vol();
       System.out.println("volume from default constructor "+x);
       System.out.println("volume from parameterizerd constructor "+y);
        // b1.d = 5;
        // b1.h = 6;
        // b1.w = 4;
        // b2.d = 2;
        // b2.h = 6;
        // b2.w = 4;
        System.out.println("float is "+b1.d);
        System.out.println("bool is "+b1.a);
        System.out.println("int is "+b1.b);
        System.out.println("string is "+b1.c);
        double vol,vol1;
        b1.setDim(10,20,30);
        vol =b1.vol();
        b2.setDim(1,2,3);
        vol1 = b2.vol();
        // b1.vol();
        // b2.vol();
        System.out.println("volume is " +vol );
        System.out.println("volume is "+vol1);


        
    }
}