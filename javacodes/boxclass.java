
public class boxclass {
    
        double h,w,d;
        boolean a;
        int b;
        String c;
        boxclass(){
            h=1;
            w=1;
            d=1;
        }
        boxclass(double x,double y,double z){
            h=x;
            w=y;
            d=z;
        }
        boxclass(double x){
            h=w=d=x;
            
        }
        boxclass(boxclass b){
            h = b.h;
            w = b.w;
            d = b.d;

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
        void overload(int x)
        {
            System.out.println("printing integer "+x);
        }
        void overload(float x)
        {
            System.out.println("printing float value "+x);
        }
        void overload(double x)
        {
            System.out.println("printing double value "+x);
        }
        void overload(String x)
        {
            System.out.println("printing string value "+x);
        }
        boolean isequal(boxclass b){
            if((b.h == h && b.w == w) && b.d == d)
             return true;
            else return false;
        }
    
    
}
class demo{
    public static void main(String[] args) {
        // boxclass b1 = new boxclass();
        // b1.overload(5);
        // b1.overload(5.5f);
        // b1.overload("5");
        boxclass b1 = new boxclass(1,2,3);
        boxclass b2 = new boxclass(1,2,3);
        System.out.println("Dimensions of boxes b1==b2 is  "+b1.isequal(b2));
        
        boxclass b3 = new boxclass(b1);
      
        System.out.println("Dimensions of boxes b1==b3 is  "+b1.isequal(b3));
        // boxclass b4 = new boxclass(5);
        // double x= b2.vol();
    //    double y= b4.vol();
    //    double z= b3.vol();
    //    double w= b4.vol();
    //    System.out.println("volume from 3 parameters constructor "+x);
    // //    System.out.println("volume from parameterizerd constructor "+y);
    //    System.out.println("volume from single parameter constructor "+w);
    //    System.out.println("volume from default constructor "+z);
        // b1.d = 5;
        // b1.h = 6;
        // b1.w = 4;
        // b2.d = 2;
        // b2.h = 6;
        // b2.w = 4;
        // System.out.println("float is "+b1.d);
        // System.out.println("bool is "+b1.a);
        // System.out.println("int is "+b1.b);
        // System.out.println("string is "+b1.c);
        // double vol,vol1;
        // b1.setDim(10,20,30);
        // vol =b1.vol();
        // b2.setDim(1,2,3);
        // vol1 = b2.vol();
        // // b1.vol();
        // // b2.vol();
        // System.out.println("volume is " +vol );
        // System.out.println("volume is "+vol1);


        
    }
}