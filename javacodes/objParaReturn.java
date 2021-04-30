public class objParaReturn {
    int x , y;
    objParaReturn(int a,int b){
        x = a;
        y = b;
    }
    objParaReturn(){
        x = 0;
        y = 0;
    }
    objParaReturn isequal(objParaReturn o){
        if (o.x == x && o.y==y)
         return this;
        else return o;
    }
    void disp(){
        System.out.println("x = "+x+" y = "+y);
    }
}

class demo1{
    public static void main(String[] args) {

        objParaReturn o1 = new objParaReturn(1, 2) ;
        objParaReturn o2 = new objParaReturn(1, 2) ;
        objParaReturn o3 = new objParaReturn() ;

        o3 = o1.isequal(o2);
        o3.disp();

        objParaReturn o4 = new objParaReturn(1, 5) ;
        objParaReturn o5 = new objParaReturn() ;
        o5 = o1.isequal(o4);
        o5.disp();
    }}
