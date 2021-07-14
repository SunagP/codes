import java.util.*;
 class linkedList{
   public static void main(String args[]){

//      LinkedList<String> list=new LinkedList<String>();

//      //Adding elements to the Linked list
//      list.add("Steve");
//      list.add("Carl");
//      list.add("Raj");

//      //Adding an element to the first position
//      list.addFirst("Negan");
// //Adding an element to the last position
//      list.addLast("Rick");

//      //Adding an element to the 3rd position
//      list.add(2, "Glenn");
//      list.removeFirst();
//      list.removeLast();
//      //Iterating LinkedList
//      Iterator<String> iterator=list.iterator();
//     //  while(iterator.hasNext()){
//     //    System.out.println(iterator.next());
     
     

//     //  }
     
//     //  while(iterator.hasNext()){
//     //     System.out.println(iterator.next());
      
//     //   }

        LinkedList<String> llistobj = new LinkedList<String>();
        ArrayList<String> arraylist= new ArrayList<String>();
        arraylist.add("String1");
        arraylist.add("String2");
        llistobj.addAll(arraylist);
        Iterator<String> iteratorx=llistobj.iterator();
        while(iteratorx.hasNext()){
            System.out.println(iteratorx.next());
          
          }


   } 
}


