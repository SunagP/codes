package monopoly;
import java.awt.Color;
import java.awt.*;
import javax.swing.*;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;
import java.sql.*;
import java.awt.event.*;
import java.util.Random;
public class board extends JFrame implements ActionListener
{   int moveNumber = 0;
    ImageIcon cities[]=new ImageIcon[32]; 
    //for players name
    String name[]=new String[2];
    // money of each player
    int m[]=new int[2];
    //class that implements action listener for displaying info of players and cities
    information in=new information();
    // class that contains names of cities - cities.java
    cities c=new cities();
    // determines whose turn to play
    int turn=0;
    //current positions of each players
    int p[]=new int[2];
    // to get random numbers for dice
    Random r=new Random();
    Color colour=new Color(190,245,221);
    // numbers on faces of dice
    int face1,face2;
    // icon of the frame
    ImageIcon icon=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/icon.jpg");
    // buttons for all 32 places
    JButton btns[]=new JButton[32];
    // buttons for all players
    JButton players[]=new JButton[2];
    // end game and end turn buttons
    JButton game[]=new JButton[2];
    // button to roll dice
    JButton roll=new JButton("roll dice");
    // button for buying 
    JButton buy=new JButton("buy");
    Cursor cur = new Cursor(Cursor.HAND_CURSOR);
    // images for places
    ImageIcon city1=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/123.jpg");
    ImageIcon jail=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/jail2.jpg");                                 
    ImageIcon parking=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/parking2.jpg");                                 
    ImageIcon goTojail=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/gotojail2.jpg");                                 
    ImageIcon go=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/go2.png");
    //images for dice faces 
    ImageIcon dice1,dice2;
    // area to display info about current city
    JTextArea city=new JTextArea();
    static JTextArea info=new JTextArea();
    // background of the frame
    ImageIcon background=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/bgblur.png");    
    JLabel back=new JLabel("",background,JLabel.CENTER); 
    // labels where dice faces are shown
    JLabel f1,f2;
    // pieces
    JTextArea pieces[]=new JTextArea[2];
    // class that contains coordinates for pieces - cities.java
    coordinates xy=new coordinates();
    // string x,y are names of 2 players entered in start frame by user - monopoly.java                                
    board(String x,String y)
    {
        name[0]=x;
        name[1]=y;
        setLayout(null);                       
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        set2(x,y);
        // back=>labelObject for backgroung image : setting size
        back.setBounds(0,0,1500,850);
        add(back);
        // sets initial position to city0
        p[0]=0;
        p[1]=0;
        // sets turn to play for player 1
        turn=0;
        // mySql connection - incomplete                    
        try{  
            Class.forName("com.mysql.jdbc.Driver");  
            Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
             
            // Statement stmt=con.createStatement();  
            String query = " insert into players (pid, pname, color ,amount)" + " values (?, ?, ?,?)";
            // String query = "insert into catallog values(6,6,6)";
            String query2 = "delete from owns";
            con.prepareStatement(query2).execute();
            String query1 = "delete from players";
            con.prepareStatement(query1).execute();
            String query3 = "delete from moves";
            con.prepareStatement(query3).execute();
            PreparedStatement x1 = con.prepareStatement(query);
            PreparedStatement x2 = con.prepareStatement(query);
            x1.setInt(1, 0);
            x1.setString(2,x);
            x1.setString(3,"pink");
            x1.setInt(4, 10000);
            
            x2.setInt(1, 1);
            x2.setString(2,y);
            x2.setString(3,"green");
            x2.setInt(4, 10000);
            x1.execute();
            x2.execute(); 
            
            con.close();  
            }catch(Exception _e){ System.out.println(_e);}
        // makes entire frame visible
        this.setVisible(true);
    }
    //  on click action for roll dice
    public void actionPerformed(ActionEvent e)
    {   moveNumber++;
        int play=-1;
        int amt=0;
        int rent=0;
        int sumDice=0;
        
        // random numbers chosen
        face1=r.nextInt(6)+1;
        face2=r.nextInt(6)+1;
        sumDice=face1+face2;

        // images corresponding to those random numbers
        dice1=new ImageIcon(getClass().getResource(face1+".png"));
        dice2=new ImageIcon(getClass().getResource(face2+".png"));
        // setting labels to those images for display
        f1.setIcon(dice1);
        f2.setIcon(dice2);
        // setting new position for player with current turn
        p[turn]=(p[turn]+face1+face2)%32;
        // shows info of current city + recent player in it
        city.setText(c.C[p[turn]]+"\n"+players[turn].getText());
        // sets location of piece of player with current turn
        pieces[turn].setLocation(xy.x[turn][p[turn]],xy.y[turn][p[turn]]);
        try{  
            Class.forName("com.mysql.jdbc.Driver");  
            
            Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
            Statement stmt=con.createStatement(); 
            String query = "select pid,rent from owns,land where owns.lid="+p[turn]+" and owns.lid=land.lid";
            String query1 = "insert into moves values("+moveNumber+","+turn+","+sumDice+","+p[turn]+")";
            con.prepareStatement(query1).execute();
            ResultSet rs=stmt.executeQuery(query);  
            while(rs.next())
            {
                rent = rs.getInt(2);
                play=rs.getInt(1); 
            }
              
            con.close();  
       
        }catch(Exception ex){ System.out.println(ex);} 
        if(play==turn)
        {
            amt=m[turn];
        }
        else if(play>-1)
        {
            m[turn]=m[turn]-rent;
            amt=m[turn];
            m[play]=m[play]+rent;
        }
        else
        {
            amt=m[turn];
        }
           if(play>-1)
           {
                players[turn].setText(name[turn]+"("+amt+")");
                try{  
                    Class.forName("com.mysql.jdbc.Driver");  
                    Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
                    String query = "update players set amount ="+amt+" where pid="+turn;
                    con.prepareStatement(query).execute();
                    con.close();  
                    }catch(Exception ex){ System.out.println(ex);}  
                players[play].setText(name[play]+"("+m[play]+")");
                try{  
                    Class.forName("com.mysql.jdbc.Driver");  
                    Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
                    String query = "update players set amount ="+m[play]+" where pid="+play;
                    con.prepareStatement(query).execute();
                    con.close();  
                    }catch(Exception ex){ System.out.println(ex);}  
           }
        repaint();
        
    }
    void set2(String x,String y)
    {
        // initializing and setting properties to pieces
        pieces[0]=new JTextArea();
        pieces[1]=new JTextArea();
        pieces[0].setBackground(Color.GREEN);
        pieces[0].setBounds(485,85,15,15);
        pieces[1].setBackground(Color.PINK);
        pieces[1].setBounds(470,85,15,15);
        add(pieces[0]);
        add(pieces[1]);
        // setting properties for area that displays current city
        city.setBounds(1200,400,150,200);
        city.setBackground(colour);
        city.setBorder(new TitledBorder(new LineBorder(Color.black, 5),"Current"));
        add(city);
        // setting properties for area that displays info of players / cities on clicking
        info.setBounds(1200,150,150,200);
        info.setBackground(colour);
        info.setBorder(new TitledBorder(new LineBorder(Color.black, 5),"info"));
        add(info);
        // images for places
    
            cities[1]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/MEDIRTERRANEAN AVENUE.png");
            cities[2]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/COMMUNITY CHEST.png");
            cities[3]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/BALTIC AVENUE.png");
            cities[4]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/INCOME TAX.png");
            cities[5]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/READING RAILROAD.png");
            cities[6]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/ORIENTAL AVENUE.png");
            cities[7]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/CHANCE.png");
            // ImageIcon city8=new ImageIcon("images/VERMONT AVENUE.png");
            // ImageIcon city9=new ImageIcon("images/CONNECTICUT AVENUE.png");
            cities[9]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/ST. CHARLES PLACE.png");
            cities[10]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/ELECTRIC COMPANY.png");
            cities[11]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/STATES AVENUE.png");
            cities[12]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/VIRGINIA AVENUE.png");
            cities[13]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/PENNSYLVANIA RAILROAD.png");


            cities[14]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/ST. JAMES PLACE.png");
            cities[15]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/COMMUNITY CHEST 3.png");
            // ImageIcon city=new ImageIcon("images/TENNESSEE AVENUE.png");
            // ImageIcon city=new ImageIcon("images/NEW YORK AVENUE.png");
            cities[17]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/KENTUCKY AVENUE.png");
            cities[18]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/CHANCE 2.png");
            cities[19]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/INDIANA AVENUE.png");
            cities[20]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/ILLIONOIS AVENUE.png");
            cities[21]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/B & O RAILROAD.png");
            cities[22]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/ATLANTIC AVENUE.png");
            cities[23]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/VENTNOR AVENUE.png");
            // ImageIcon city24=new ImageIcon("images/WATER WORKS.png");
            cities[25]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/PACIFIC AVENUE.png");
            cities[26]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/NORTH CAROLINA AVENUE.png");
            cities[27]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/COMMUNITY CHEST 3.png");
            cities[28]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/PENNSYLVANIA AVENUE.png");
            cities[29]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/SHORT LINE.png");
            cities[30]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/CHANCE 3.png");
            cities[31]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/PARK PLACE.png");
        //  setting properties for corner squares of board
        btns[0]=new JButton(go);
        btns[0].setVisible(true);
        btns[0].setSize(100,100);
        btns[0].setCursor(cur);
        btns[0].setForeground(Color.RED); 
        add(btns[0]);

        btns[8]=new JButton(jail);
        btns[8].setVisible(true);
        btns[8].setSize(100,100);
        btns[8].setCursor(cur);
        btns[8].setForeground(Color.RED);
        add(btns[8]);

        btns[16]=new JButton(parking);
        btns[16].setVisible(true);
        btns[16].setSize(100,100);
        btns[16].setCursor(cur);
        btns[16].setForeground(Color.RED);
        add(btns[16]);

        btns[24]=new JButton(goTojail);
        btns[24].setVisible(true);
        btns[24].setSize(100,100);
        btns[24].setCursor(cur);
        btns[24].setForeground(Color.RED);
        add(btns[24]);
        // creating non corner places
        for(int i=1;i<8;i++)
        {
            if(i==1)
            {
                btns[i]=new JButton(cities[i]);
                btns[i].setVisible(true);
                btns[i].setSize(70,100);
                btns[i].setCursor(cur);
                btns[i].addActionListener(in);
                btns[i].setForeground(Color.RED);
                add(btns[i]);
            }
            else
            {
                btns[i]=new JButton(cities[i]);
                btns[i].setVisible(true);
                btns[i].setSize(70,100);
                btns[i].setCursor(cur);
                btns[i].addActionListener(in);
                btns[i].setForeground(Color.RED);
                add(btns[i]);
            }
        }
        for(int i=9;i<16;i++)
        {
            btns[i]=new JButton(cities[i]);
            btns[i].setVisible(true);
            btns[i].setSize(100,70);
            btns[i].setCursor(cur);
            btns[i].addActionListener(in);
            btns[i].setForeground(Color.RED);
            add(btns[i]);
        }
        for(int i=17;i<24;i++)
        {
            btns[i]=new JButton(cities[i]);
            btns[i].setVisible(true);
            btns[i].setSize(70,100);
            btns[i].setCursor(cur);
            btns[i].addActionListener(in);
            btns[i].setForeground(Color.RED);
            add(btns[i]);
        }
        for(int i=25;i<32;i++)
        {
            btns[i]=new JButton(cities[i]);
            btns[i].setVisible(true);
            btns[i].setSize(100,70);
            btns[i].setCursor(cur);
            btns[i].addActionListener(in);
            btns[i].setForeground(Color.RED);
            add(btns[i]);
        }
        //  setting locations for all the city buttons
        for(int i=0;i<9;i++)
        {
            if(i==0)
            {
                btns[i].setLocation(400,100);
            }
            else
            {
                btns[i].setLocation(500+(i-1)*70,100);
            }
        }
        for(int i=9;i<17;i++)
        {
            if(i==9)
            {
                btns[i].setLocation(990,200);
            }
            else
            {
                btns[i].setLocation(990,200+(i-9)*70);
            }
        }
        for(int i=17;i<24;i++)
        {
            if(i==17)
            {
                btns[i].setLocation(920,690);
            }
            else
            {
                btns[i].setLocation(920-(i-17)*70,690);
            }
        }
        for(int i=24;i<32;i++)
        {
            if(i==24)
            {
                btns[i].setLocation(400,690);
            }
            else
            {
                btns[i].setLocation(400,690-(i-24)*70);
            }
        }
        // assigning initial money to players
        m[0]=10000;
        m[1]=10000;
        // player buttons
        players[0]=new JButton(x+"("+m[0]+")");
        players[0].setVisible(true);
        players[0].setSize(180,30);
        players[0].setCursor(cur);
        players[0].setLocation(50,400);
        players[0].setForeground(Color.RED);
        players[0].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e)
            {
               city.setText(x+"\n"+x);
            }
        });
        add(players[0]);
        players[1]=new JButton(y+"("+m[1]+")");
        players[1].setVisible(true);
        players[1].setSize(180,30);
        players[1].setCursor(cur);
        players[1].setLocation(50,450);
        players[1].setForeground(Color.RED);
        players[1].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e)
            {
               city.setText(y+"\n"+y);
            }
        });
        add(players[1]);
        // end turn and end game buttons
        game[1]=new JButton("end turn");
        game[1].setVisible(true);
        game[1].setSize(180,30);
        game[1].setCursor(cur);
        game[1].setLocation(1200,700);
        game[1].setForeground(Color.RED);
        game[1].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e)
            {
                turn=(turn+1)%2;
            }
        });
        add(game[1]);
        game[0]=new JButton("end game");
        game[0].setVisible(true);
        game[0].setSize(180,30);
        game[0].setCursor(cur);
        game[0].setLocation(1200,750);
        game[0].setForeground(Color.RED);
        add(game[0]);
        // dice rolling button
        roll.setVisible(true);
        roll.setSize(80,30);
        roll.setCursor(cur);
        roll.setLocation(575,650);
        roll.setForeground(Color.RED);
        roll.addActionListener(this);
        add(roll);
        // buy button
        buy.setVisible(true);
        buy.setSize(80,30);
        buy.setCursor(cur);
        buy.setLocation(850,550);
        buy.setForeground(Color.RED);
        buy.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e)
            {
                int cost=0;
                int play=-1;
                try{  
                    Class.forName("com.mysql.jdbc.Driver");  
                    Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
                    Statement stmt=con.createStatement();
                    String query = "select landprice from land where lid="+p[turn];
                    String query1 = "insert into owns values("+turn+","+p[turn]+");";
                    String query2 = "select pid from owns where lid="+p[turn];
                    // con.prepareStatement(query).execute();
                    ResultSet rs=stmt.executeQuery(query);
                    while(rs.next())
                    {
                        cost=rs.getInt(1);
                    }
                    ResultSet rs1=stmt.executeQuery(query2);
                    while(rs1.next())
                    {
                        play=rs1.getInt(1);
                    }
                    if(play>-1)
                    {
                        System.out.println("already sold");
                    }
                    else
                    {
                        con.prepareStatement(query1).execute();
                    }
                    con.close();  
                    }catch(Exception ex){ System.out.println(ex);}
                    int amt=0;
                    if(play>-1)
                    {
                        amt=m[turn];
                    }
                    else
                    {
                        m[turn]=m[turn]-cost;
                        amt=m[turn];
                    }
                if(turn==1){
                    players[turn].setText(y+"("+m[turn]+")");
                    try{  
                        Class.forName("com.mysql.jdbc.Driver");  
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
                        String query = "update players set amount ="+amt+" where pid=1";
                        con.prepareStatement(query).execute();
                        con.close();  
                        }catch(Exception ex){ System.out.println(ex);}  

                }
                if(turn==0){
                    players[turn].setText(x+"("+m[turn]+")");
                    try{  
                        Class.forName("com.mysql.jdbc.Driver");  
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
                        String query = "update players set amount ="+amt+" where pid=0";
                        con.prepareStatement(query).execute();
                        con.close();  
                        }catch(Exception ex){ System.out.println(ex);}  
                }
            } 
        });
        add(buy);
        // title and icon for frame
        this.setTitle("monopoly game");                                        
        this.setIconImage(icon.getImage()); 
        setSize(1500, 1500);
        ImageIcon dice1=new ImageIcon(getClass().getResource("1.png"));
        ImageIcon dice2=new ImageIcon(getClass().getResource("2.png"));
        f1=new JLabel(dice1);
        f2=new JLabel(dice2);
        //creating labels to display dice faces
        f1.setBounds(550,550,50,50);
        f2.setBounds(650,550,50,50);
        add(f1);
        add(f2);   
    }
}
// class that has action listener for city and player buttons
class information implements ActionListener
{
    public void actionPerformed(ActionEvent e)
    {
        // gets text from buttons that calls action
        String str=((AbstractButton) e.getSource()).getText();
        board.info.setText(str);
        // System.out.println(str);
    }
}
class boardMain
{
    public static void main(String[] args) 
    {
        board b=new board("p1","p2");
    }
}