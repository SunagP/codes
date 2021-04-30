public class class2d {
    int x,y;
    void disp(){
        System.out.println("x :"+x+"\ny :"+y);
    }
}

class class3d extends class2d{
    int z;
    void disp3d(){
        System.out.println("x :"+x+"\ny :"+y+"\nz :"+z);
    }
}


class test2d{
     public static void main(String[] args) {
        class2d c = new class2d();
        class3d c3d = new class3d();
        c.x = 10;
        c.y = 20;
        c3d.x = 5;
        c3d.y = 6;
        c3d.z = 7;

        c.disp();
        c3d.disp3d();
    }
}