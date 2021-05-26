abstract class shape{
    int x;
 abstract  void disp();
}

interface ipoint{
String s="hi";
}
class triangle extends shape implements ipoint{
    void disp(){
        System.out.println(s+" In class triangle");
    }
}
class Hexagon extends shape implements ipoint{
    void disp(){
        System.out.println(s+ " In class Hexagon");
    }
}
class circle extends shape {
    void disp(){
        System.out.println("In class circle");
    }
}
class ThreeDcircle extends circle{
    void disp(){
        System.out.println("In class 3d circle");
    }
}



public class interf {
    public static void main(String[] args){
    shape t = new triangle();
    Hexagon h = new Hexagon();
    circle c = new circle();
    ThreeDcircle c3 = new ThreeDcircle();

    t.disp();
    h.disp();
    c.disp();
    c3.disp();
    
    
    }
}
