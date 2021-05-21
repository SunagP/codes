class a{
  int x;

  // @Override
    public String toString() {
        return (x+"");
    }
}

public class commandline{
    
   
        public static void main(String[] args) {
          System.out.println("Command-Line arguments are");
      
          // loop through all arguments
          for(String str: args) {
            System.out.println(str);
          }
        }
      }

