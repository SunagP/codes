// https://www.ultraboardgames.com/monopoly/game-rules.php

import java.awt.*;
import javax.swing.*;
import javax.swing.border.Border;

import java.awt.event.*;
class RoundedBorder implements Border {

    private int radius;


    RoundedBorder(int radius) {
        this.radius = radius;
    }


    public Insets getBorderInsets(Component c) {
        return new Insets(this.radius+1, this.radius+1, this.radius+2, this.radius);
    }


    public boolean isBorderOpaque() {
        return true;
    }


    public void paintBorder(Component c, Graphics g, int x, int y, int width, int height) {
        g.drawRoundRect(x, y, width-1, height-1, radius, radius);
    }
}

public class monopoly extends JFrame implements ActionListener
{
    int nop=2;
    // btnAction a=new btnAction();                                               //actionListener object for button
    public void actionPerformed(ActionEvent e)
    {
        System.out.println("action performed");
                 String a=t[0].getText();
                 String b=t[1].getText();
                 String c=t[2].getText();
                 String d=t[3].getText();
                 switch(nop)
                 {
                    case 2 : System.out.println(a+" "+b);
                             board bo2=new board(a,b);
                    break;
                    case 3 : System.out.println(a+" "+b+" "+c);
                             board2 bo3=new board2(a,b,c);
                    break;
                    case 4 : System.out.println(a+" "+b+" "+c+" "+d);
                             board3 bo4=new board3(a,b,c,d);
                    break;
                 }
                 this.dispose();
    }
    Container c=this.getContentPane();                                         //container to hold buttons,background,text labels etc
    Color cl=new Color(100,100,100);                                           //object of color with rgb 100,100,100
    Color c2=new Color(0,255,0);                                           //object of color with rgb 100,100,100
    ImageIcon icon=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/icon.jpg");                                  //icon for the game
    ImageIcon background=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/background.jpg");                      //background image of start page
    JTextField t[]=new JTextField[4];                                          //array of text fields to hold players' name
    JLabel back=new JLabel("",background,JLabel.CENTER);                       //setting background image to the start page
    JLabel message=new JLabel("Enter player names :");                         //text object
    JLabel select=new JLabel("SELECT NUMBER OF PLAYERS :");                         //text object
    Font f=new Font("TimesRoman",Font.BOLD|Font.ITALIC,30);                                     //font object
    Font f1=new Font("TimesRoman ITALIC",Font.BOLD,20);                                     //font object
    JButton rules=new JButton("RULES");                                 
    JButton start=new JButton("Start Game");                                    // start game button
    JButton players2=new JButton("2 players");                                    // start game button
    JButton players3=new JButton("3 players");                                    
    JButton players4=new JButton("4 players");                                 
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
        c.add(rules); 
        c.add(select);
        c.add(start);
        c.add(players2);
        c.add(players3);
        c.add(players4);
        this.c.setBackground(cl);                                              //setting background color of frame to cl defined before
        this.setTitle("monopoly game");                                        //seting title of the frame
        this.setIconImage(icon.getImage());                                    //setting icon for the frame
        this.setSize(1500,1500);                                               //this => frame : setting size of the frame
        for(int i=0;i<4;i++)
        {
            t[i]=new JTextField();                                            //text fields for player names
        }
        t[0].setText("player1");                                              //setting text that appears by default
        t[0].setBounds(1160,60,200,30);
        t[0].setVisible(false); 
        t[0].setFont(f1);                                      //size of text fields
        t[1].setText("player2");                                                          
        t[1].setFont(f1);                                                          
        t[1].setBounds(1160,95,200,30);
        t[1].setVisible(false);
        t[2].setText("player3");
        t[2].setFont(f1);
        t[2].setBounds(1160,130,200,30);
        t[2].setVisible(false);
        t[3].setText("player4");
        t[3].setFont(f1);
        t[3].setBounds(1160,165,200,30);
        t[3].setVisible(false);
        message.setBounds(850,60,800,30);
        message.setFont(f);
        message.setVisible(false);                                                   //setting font to f that is defined before
        select.setBounds(1020,25,800,35);
        select.setFont(f);                                                   //setting font to f that is defined before
        for(int i=0;i<4;i++)
        {
            c.add(t[i]);                                                     //adding text fields to frame container (if there is no container,add() method can be used)
        }
        c.add(message);
        back.setBounds(0,-300,1500,1500);                                    // back=>labelObject for backgroung image : setting size
        c.add(back);
        //adding properties to start button
        start.setVisible(true);                                               //making button visible
        start.setSize(300, 50);
        start.setFont(f);
        start.setLocation(1000,700);
        start.setCursor(cur);
        start.addActionListener(this);                                          //passing object of actionListener to button
        start.setForeground(Color.WHITE);                                      //foreground => color of text within button
        start.setBorder(BorderFactory.createLineBorder(Color.WHITE,3));
        start.setBackground(Color.BLUE); 
        
        rules.setVisible(true);                                               //making button visible
        rules.setSize(200, 50);
        rules.setFont(f);
        rules.setForeground(Color.WHITE);                                      //foreground => color of text within button
        rules.setLocation(1150,245);
        rules.setCursor(cur);
        rules.setBorder(BorderFactory.createLineBorder(Color.WHITE,3));
        rules.setBackground(Color.BLUE); 
        rules.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                UIManager um=new UIManager();
                um.put("OptionPane.background",Color.RED);
                um.put("Panel.background",Color.CYAN);
                JLabel rules=new JLabel("<html><h1><br><br>********Become the wealthiest player through buying and renting of property and force other players into bankruptcy********<br><br><br>1)Each player's token is placed  on the corner marked GO, and dice can be rolled<br>to move his piece the number of spaces indicated by the dice.<br>2)Two or more tokens may rest on the same space at the same time.<br>3)Depending on the space the token reaches, you may buy the property, or be obliged to pay rent, pay taxes,<br>draw a Chance or Community Chest card, Go To Jail, or etc...<br>4)Each time a player's token lands on or passes over GO, Rs 500 is credited to the player.<br>5)When you land on an unowned property you can buy that property from the Bank at its shown price.<br>6)When you land on a property that is owned by another player, the owner collects rent from you in accordance with the shown rent.<br>7)When you land on community chest or chance random tasks are shown and money is credited or debited in accordance with them.<br>8)When you land on income tax you pay a tax of Rs250<br>9)When you land on Jail you pay a penalty of Rs500<br>10)When you land on go to jail you are sent to jail and Rs500 is debited as penalty.</h1>");
                // rules.setBackground(Color.CYAN);
                JOptionPane.showMessageDialog(null,rules,"RULES",JOptionPane.PLAIN_MESSAGE);
            }
        });                                         //passing object of actionListener to button

        players2.setVisible(true);                                               //making button visible
        players2.setSize(300, 50);
        players2.setFont(f);
        players2.setForeground(Color.BLACK);
        // players2.setBorder(new RoundedBorder(30));
        players2.setBorder(BorderFactory.createLineBorder(Color.RED,3));
        players3.setBorder(BorderFactory.createLineBorder(Color.RED,3));
        players4.setBorder(BorderFactory.createLineBorder(Color.RED,3));
        players2.setBackground(c2);                                      //foreground => color of text within button
        players2.setLocation(1100,75);
        players2.setCursor(cur);
        players2.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e)
            {
                players2.setVisible(false);
                players3.setVisible(false);
                players4.setVisible(false);
                message.setVisible(true);
                for(int i=0;i<nop;i++)
                {
                    t[i].setVisible(true);                                                     //adding text fields to frame container (if there is no container,add() method can be used)
                }
                select.setVisible(false);
            }
        });

        players3.setVisible(true);                                               //making button visible
        players3.setSize(300, 50);
        players3.setFont(f);
        players3.setForeground(Color.BLACK);                                      //foreground => color of text within button
        players3.setBackground(c2);                                      //foreground => color of text within button
        players3.setLocation(1100,130);
        players3.setCursor(cur);
        players3.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e)
            {
                players2.setVisible(false);
                players3.setVisible(false);
                players4.setVisible(false);
                message.setVisible(true);
                nop=3;
                for(int i=0;i<nop;i++)
                {
                    t[i].setVisible(true);                                                     //adding text fields to frame container (if there is no container,add() method can be used)
                }
                select.setVisible(false);
            }
        });
        
        players4.setVisible(true);                                               //making button visible
        players4.setSize(300, 50);
        players4.setFont(f);
        players4.setForeground(Color.BLACK);
        players4.setBackground(c2);                                      //foreground => color of text within button
        players4.setLocation(1100,185);
        players4.setCursor(cur);
        players4.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e)
            {
                players2.setVisible(false);
                players3.setVisible(false);
                players4.setVisible(false);
                message.setVisible(true);
                nop=4;
                for(int i=0;i<nop;i++)
                {
                    t[i].setVisible(true);                                                     //adding text fields to frame container (if there is no container,add() method can be used)
                }
                select.setVisible(false);
            }
        });
    }

}
class Main
{
 public static void main(String[] args) 
 {
     monopoly M=new monopoly();                                            //instantiating frame object
 }
}