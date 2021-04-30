public class cstudent {
  public int rnum;
    char grade;

    void disp(){
        System.out.println("roll num : "+rnum+"\ngrade : "+grade);
    }
}

class testStudent{
    public static void main(String[] args){
        cstudent s = new cstudent();
        s.rnum = 10;
        s.grade = 'A';

        s.disp();
    }
}
