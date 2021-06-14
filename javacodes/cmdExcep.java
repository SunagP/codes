import org.w3c.dom.ranges.RangeException;

// import RangeException;

public class cmdExcep {
      
        public static void main(String args[]){  
         String name = args[0]; 
         int m[] = new int[6];
         int k = 0;
         int sum=0;
        for(int i=1;i<7;i++) {
            
        //    if(int(args[i])>50 || args[i]<0)
         m[k]=Integer.parseInt(args[i]);
         k++;
        } 
        for(int i=0;i<6;i++) {
            
            if(m[i]>50 || m[i]<0){
                  throw new ArithmeticException("invalid marks "+m[i]);
            }
            else{
                
                // for(int j=0;j<6;j++) {
                    //    if(int(args[i])>50 || args[i]<0)
                    //  m[i]=Integer.parseInt(args[i]);
                    sum+=m[i];
                    // } 
                // System.out.println("Name :"+name);

                // System.out.println("percentage :"+(sum*100)/300);

            }
            
             
            } 
            System.out.println("Name :"+name);

            System.out.println("percentage :"+(sum*100)/300);


        // System.out.println(args[i]);  
          
        }  
        }  

