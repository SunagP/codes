package monopoly;
import java.awt.*;
import javax.swing.*;
import java.sql.*;
import java.awt.event.*;

public class monopoly extends JFrame implements ActionListener
{
    // btnAction a=new btnAction();                                                                 //actionListener object for button
    public void actionPerformed(ActionEvent e)
    {
        System.out.println("action performed");
                 String a=t[0].getText();
                 String b=t[1].getText();
                 System.out.println(a+' '+b);
                 board bo=new board(a,b);

                //  try{  
                //     Class.forName("com.mysql.jdbc.Driver");  
                //     Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
                     
                //     // Statement stmt=con.createStatement();  
                //     String query = " insert into players (pid, pname, color ,amount)" + " values (?, ?, ?,?)";
                //     // String query = "insert into catallog values(6,6,6)";
                //     String query1 = "delete from players";
                //     con.prepareStatement(query1).execute();
                //     PreparedStatement x = con.prepareStatement(query);
                //     PreparedStatement x1 = con.prepareStatement(query);
                //     x.setInt(1, 1);
                //     x.setString(2,a);
                //     x.setString(3,"red");
                //     x.setInt(4, 10000);
                    
                //     x1.setInt(1, 2);
                //     x1.setString(2,b);
                //     x1.setString(3,"green");
                //     x1.setInt(4, 10000);
                //     x.execute();
                //     x1.execute();
                //     // ResultSet rs=stmt.executeQuery("select * from emp");  
                //     // while(rs.next())  
                //     // System.out.println(rs.getInt(1)+"  "+rs.getString(2)+"  "+rs.getString(3));  
                    
                //     con.close();  
                //     }catch(Exception _e){ System.out.println(_e);}  
    }
    
    Container c=this.getContentPane();                                                        //container to hold buttons,background,text labels etc
    Color cl=new Color(100,100,100);                                                                  //object of color with rgb 100,100,100
    ImageIcon icon=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/icon.jpg");                                  //icon for the game
    ImageIcon background=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/background.jpg");                      //background image of start page
    JTextField t[]=new JTextField[2];                                          //array of text fields to hold players' name
    JLabel back=new JLabel("",background,JLabel.CENTER);                       //setting background image to the start page
    JLabel message=new JLabel("Enter player names :");                         //text object
    Font f=new Font("Arial",Font.BOLD,30);                                     //font object
    JButton btn1=new JButton("Start Game");                                    // start game button
    Cursor cur = new Cursor(Cursor.HAND_CURSOR);                               //cursor object for on hover for start button
    monopoly()
    {
        c.setLayout(null);                                                     //setting layout to null to place components wherever we want
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);                   //to make the frame close on clicking x
        set();
        this.setVisible(true);                                                 //making frame visible
    }
    //method to set properties and components on frame
    void set()
    {
        c.add(btn1);
        this.c.setBackground(cl);                                              //setting background color of frame to cl defined before
        this.setTitle("monopoly game");                                        //seting title of the frame
        this.setIconImage(icon.getImage());                                    //setting icon for the frame
        this.setSize(1500,1500);                                               //this => frame : setting size of the frame
        for(int i=0;i<2;i++)
        {
            t[i]=new JTextField();                                            //text fields for player names
        }
        t[0].setText("player1");                                              //setting text that appears by default
        t[0].setBounds(100,600,180,30);                                       //size of text fields
        t[1].setText("player2");                                                          
        t[1].setBounds(100,650,180,30);
        message.setBounds(30,550,800,30);
        message.setFont(f);                                                   //setting font to f that is defined before
        // t[2].setText("player3");
        // t[2].setBounds(100,180,180,30);
        // t[3].setText("player4");
        // t[3].setBounds(100,230,180,30);
        for(int i=0;i<2;i++)
        {
            c.add(t[i]);                                                     //adding text fields to frame container (if there is no container,add() method can be used)
        }
        c.add(message);
        back.setBounds(0,-300,1500,1500);                                    // back=>labelObject for backgroung image : setting size
        c.add(back);
        //adding properties to start button
        btn1.setVisible(true);                                               //making button visible
        btn1.setSize(300, 50);
        btn1.setFont(f);
        btn1.setForeground(Color.RED);                                      //foreground => color of text within button
        btn1.setLocation(1000,700);
        btn1.setCursor(cur);
        btn1.addActionListener(this);                                          //passing object of actionListener to button
    }

}
class Main
{
 public static void main(String[] args) 
 {
     monopoly M=new monopoly();                                            //instantiating frame object
 }
}