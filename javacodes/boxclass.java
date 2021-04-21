// package javacodes;

public class boxclass {
    
        double h,w,d;
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
        // b1.d = 5;
        // b1.h = 6;
        // b1.w = 4;
        // b2.d = 2;
        // b2.h = 6;
        // b2.w = 4;

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