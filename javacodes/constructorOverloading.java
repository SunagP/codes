public class constructorOverloading {
    int x,y;
    constructorOverloading(){
        x = 1;
        y = 1;
    }
    constructorOverloading(int l){
        x = y = l;
        
    }
    constructorOverloading(int l,int w){
        x = l;
        y = w;
        
    }
    void area(){
        System.out.println("area is "+x*y + " sq units");
    }
}


class conMain{
    public static void main(String[] args){
        constructorOverloading o = new constructorOverloading();
        constructorOverloading o1 = new constructorOverloading(5);
        constructorOverloading o2 = new constructorOverloading(5,4);
        o.area();
        o1.area();
        o2.area();



    }
}
