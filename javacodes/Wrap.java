public class Wrap {
    public static void main(String args[]) {
    Integer iOb = new Integer(100);
    // Double d = new Double(5.05)
    int i = iOb.intValue();

    Integer iob1 = 20;//auto boxing
    int i2 = iob1;//auto unboxing
   
    System.out.println(i + " " + iOb+" "+iob1); 
    // displays 100 100
    }
    }
