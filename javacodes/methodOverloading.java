public class methodOverloading {
    void area(int x){
        System.out.println("area of square is "+x*x + " sq units");
    }
    void area(int x,int y){
        System.out.println("area of rectangle is "+x*y + " sq units");
    }
}

class overMain{
    public static void main(String[] args){
        methodOverloading o = new methodOverloading();
        methodOverloading o1 = new methodOverloading();
        o.area(5);
        o1.area(4,5);



    }
}
