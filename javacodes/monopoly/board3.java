import java.awt.Color;
import java.awt.*;
import javax.swing.*;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;
import java.sql.*;
import java.awt.event.*;
import java.util.Random;
public class board3 extends JFrame implements ActionListener
{   
    JLabel currentStatus =new JLabel("<html><h1>Woohooo....Game Started❤❤</h1>");
    JLabel owns[]=new JLabel[32];
    int moveNumber=0;
    ImageIcon cities[]=new ImageIcon[32];
    static String name[]=new String[4];
    // money of each player
    int m[]=new int[4];
    //class that implements action listener for displaying info of players and cities
    information2 in=new information2();
    // class that contains names of cities - cities.java
    cities c=new cities();
    // determines whose turn to play
    int turn=0;
    //current positions of each players
    int p[]=new int[4];
    // to get random numbers for dice
    Random r=new Random();
    Color colour=new Color(190,245,221);
    // numbers on faces of dice
    int face1,face2;
    // icon of the frame
    ImageIcon icon=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/icon.jpg");
    // buttons for all 32 places
    static JButton btns[]=new JButton[32];
    // buttons for all players
    JButton players[]=new JButton[4];
    // end game and end turn buttons
    JButton game[]=new JButton[2];
    // button to roll dice
    JButton roll=new JButton("Roll dice");
    // button for buying 
    JButton buy=new JButton("Buy");
    Cursor cur = new Cursor(Cursor.HAND_CURSOR);
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
    ImageIcon background=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/bgfade.jpg");    
    JLabel back=new JLabel("",background,JLabel.CENTER); 
    // labels where dice faces are shown
    JLabel f1,f2;
    // pieces
    JTextArea pieces[]=new JTextArea[4];
    // class that contains coordinates for pieces - cities.java
    coordinates xy=new coordinates();
    // string x,y are names of 2 players entered in start frame by user - monopoly.java 
    public void communityChest(int task,int turn,int m[],JButton players[],int board)
    {
        switch(task)
        {
            case 100:   m[turn]=m[turn]-(board*100);
                        try{  
                        Class.forName("com.mysql.jdbc.Driver");  
                        
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
                        String query="update players set amount="+m[turn]+" where pid="+turn; 
                        String query1="update players set amount=amount+100 where pid not in("+turn+")";
                        con.prepareStatement(query).execute(); 
                        con.prepareStatement(query1).execute();
                        players[turn].setText(name[turn]+"("+m[turn]+")");
                        for(int i=0;i<players.length;i++)
                        {
                            if(i!=turn)
                            {
                                m[i]=m[i]+100;
                                players[i].setText(name[i]+"("+m[i]+")");
                            }
                        } 
                        con.close();
                
                        }catch(Exception ex){ System.out.println(ex);}
                        break; 
            case 101:   m[turn]=m[turn]+(board*50);
                        try{  
                        Class.forName("com.mysql.jdbc.Driver");  
                        
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  ; 
                        String query="update players set amount="+m[turn]+" where pid="+turn; 
                        String query1="update players set amount=amount-50 where pid not in("+turn+")";
                        con.prepareStatement(query).execute(); 
                        con.prepareStatement(query1).execute(); 
                        con.close();
                        players[turn].setText(name[turn]+"("+m[turn]+")");
                        for(int i=0;i<players.length;i++)
                        {
                            if(i!=turn)
                            {
                                m[i]=m[i]-50;
                                players[i].setText(name[i]+"("+m[i]+")");
                            }
                        } 
                
                        }catch(Exception ex){ System.out.println(ex);} 
                        break;
            case 102:   m[turn]=m[turn]-250;
                        try{  
                        Class.forName("com.mysql.jdbc.Driver");  
                        
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root",""); 
                        String query="update players set amount="+m[turn]+" where pid="+turn;
                        con.prepareStatement(query).execute();  
                        con.close();
                        players[turn].setText(name[turn]+"("+m[turn]+")");
                
                        }catch(Exception ex){ System.out.println(ex);} 
                        break;
            case 103:   m[turn]=m[turn]-1000;
                        try{  
                        Class.forName("com.mysql.jdbc.Driver");  
                        
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");
                        String query="update players set amount="+m[turn]+" where pid="+turn; 
                        con.prepareStatement(query).execute();  
                        con.close();
                        players[turn].setText(name[turn]+"("+m[turn]+")");
                
                        }catch(Exception ex){ System.out.println(ex);}
                        break; 
            case 104:   m[turn]=m[turn]+500;
                        try{  
                        Class.forName("com.mysql.jdbc.Driver");  
                        
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root",""); 
                        String query="update players set amount="+m[turn]+" where pid="+turn;
                        con.prepareStatement(query).execute();  
                        con.close();
                        players[turn].setText(name[turn]+"("+m[turn]+")");
                
                        }catch(Exception ex){ System.out.println(ex);} 
                        break;
            case 105:   m[turn]=m[turn]-200;
                        try{  
                        Class.forName("com.mysql.jdbc.Driver");  
                        
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root",""); 
                        String query="update players set amount="+m[turn]+" where pid="+turn; 
                        con.prepareStatement(query).execute(); 
                        con.close();
                        players[turn].setText(name[turn]+"("+m[turn]+")");
                
                        }catch(Exception ex){ System.out.println(ex);} 
                        break;
        }
    }                               
    public void chance(int task,int turn,int m[],JButton players[],int board)
    {
        switch(task)
        {
            case 100:   m[turn]=m[turn]-250;
                        try{  
                        Class.forName("com.mysql.jdbc.Driver");  
                        
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
                        String query="update players set amount="+m[turn]+" where pid="+turn; 
                        con.prepareStatement(query).execute(); 
                        players[turn].setText(name[turn]+"("+m[turn]+")"); 
                        con.close();
                
                        }catch(Exception ex){ System.out.println(ex);}
                        break; 
            case 101:   m[turn]=m[turn]+400;
                        try{  
                        Class.forName("com.mysql.jdbc.Driver");  
                        
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  ; 
                        String query="update players set amount="+m[turn]+" where pid="+turn; 
                        con.prepareStatement(query).execute(); 
                        con.close();
                        players[turn].setText(name[turn]+"("+m[turn]+")");
                
                        }catch(Exception ex){ System.out.println(ex);} 
                        break;
            case 102:   m[turn]=m[turn]+500;
                        try{  
                        Class.forName("com.mysql.jdbc.Driver");  
                        
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root",""); 
                        String query="update players set amount="+m[turn]+" where pid="+turn;
                        con.prepareStatement(query).execute();  
                        con.close();
                        players[turn].setText(name[turn]+"("+m[turn]+")");
                
                        }catch(Exception ex){ System.out.println(ex);} 
                        break;
            case 103:   m[turn]=m[turn]-300;
                        try{  
                        Class.forName("com.mysql.jdbc.Driver");  
                        
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");
                        String query="update players set amount="+m[turn]+" where pid="+turn; 
                        con.prepareStatement(query).execute();  
                        con.close();
                        players[turn].setText(name[turn]+"("+m[turn]+")");
                
                        }catch(Exception ex){ System.out.println(ex);}
                        break; 
            case 104:   m[turn]=m[turn]+200;
                        try{  
                        Class.forName("com.mysql.jdbc.Driver");  
                        
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root",""); 
                        String query="update players set amount="+m[turn]+" where pid="+turn;
                        con.prepareStatement(query).execute();  
                        con.close();
                        players[turn].setText(name[turn]+"("+m[turn]+")");
                
                        }catch(Exception ex){ System.out.println(ex);} 
                        break;
            case 105:   m[turn]=m[turn]-500;
                        try{  
                        Class.forName("com.mysql.jdbc.Driver");  
                        
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root",""); 
                        String query="update players set amount="+m[turn]+" where pid="+turn; 
                        con.prepareStatement(query).execute(); 
                        con.close();
                        players[turn].setText(name[turn]+"("+m[turn]+")");
                
                        }catch(Exception ex){ System.out.println(ex);} 
                        break;
        }
    }                               
    board3(String x,String y,String z,String w)
    {
        name[0]=x;
        name[1]=y;
        name[2]=z;
        name[3]=w;
        setLayout(null);                       
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        set3(x,y,z,w);
        // back=>labelObject for backgroung image : setting size
        back.setBounds(0,0,1500,850);
        add(back);
        // sets initial position to city0
        p[0]=0;
        p[1]=0;
        p[2]=0;
        p[3]=0;

        // sets turn to play for player 1
        turn=0;
         // mySql connection - incomplete                    
         try{  
            Class.forName("com.mysql.jdbc.Driver");  
            Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
             
            // Statement stmt=con.createStatement();  
            String query = " insert into players (pid, pname, color ,amount)" + " values (?, ?, ?,?)";
            // String query = "insert into catallog values(6,6,6)";
            String query3 = "delete from moves";
            con.prepareStatement(query3).execute();
            String query2 = "delete from owns";
            con.prepareStatement(query2).execute();
            String query1 = "delete from players";
            con.prepareStatement(query1).execute();
            PreparedStatement x1 = con.prepareStatement(query);
            PreparedStatement x2 = con.prepareStatement(query);
            PreparedStatement x3 = con.prepareStatement(query);
            PreparedStatement x4 = con.prepareStatement(query);
            x1.setInt(1, 0);
            x1.setString(2,x);
            x1.setString(3,"green");
            x1.setInt(4, 10000);
            
            x2.setInt(1, 1);
            x2.setString(2,y);
            x2.setString(3,"red");
            x2.setInt(4, 10000);

            x3.setInt(1, 2);
            x3.setString(2,z);
            x3.setString(3,"yellow");
            x3.setInt(4, 10000);

            x4.setInt(1, 3);
            x4.setString(2,w);
            x4.setString(3,"blue");
            x4.setInt(4, 10000);

            x1.execute();
            x2.execute(); 
            x3.execute(); 
            x4.execute(); 
            
            con.close();  
            }catch(Exception _e){ System.out.println(_e);}
        // makes entire frame visible
        this.setVisible(true);
    }
    //  on click action for roll dice
    public void actionPerformed(ActionEvent e)
    {
        int flag=0;
        String where="",what="";
        int task=r.nextInt(6)+100;
        String work="";
        buy.setEnabled(true);
        moveNumber++;
        int sumDice=0;
        int play=-1;
        int amt=0;
        int rent=0;
        // random numbers chosen
        face1=r.nextInt(6)+1;
        face2=r.nextInt(6)+1;
        // face1=1;
        // face2=1;
        sumDice=face1+face2;
        // images corresponding to those random numbers
        dice1=new ImageIcon(getClass().getResource("face"+face1+".png"));
        dice2=new ImageIcon(getClass().getResource("face"+face2+".png"));
        // setting labels to those images for display
        f1.setIcon(dice1);
        f2.setIcon(dice2);
        // setting new position for player with current turn
        if(p[turn]+sumDice>=32)
        {
            flag=1;
        }
        p[turn]=(p[turn]+face1+face2)%32;
        where=name[turn]+" landed on "+c.C[p[turn]];
        if(p[turn]==8)
        {
            where="<html>"+name[turn]+" landed on "+c.C[p[turn]]+"<br> Rs 500 debited from your account";
        }
        if(p[turn]==4)
        {
            where="<html>"+name[turn]+" landed on "+c.C[p[turn]]+"<br> Rs 250 debited from your account";
        }
        if(p[turn]==0||p[turn]==8||p[turn]==16||p[turn]==24||p[turn]==31||p[turn]==23||p[turn]==18||p[turn]==15||p[turn]==7||p[turn]==4||p[turn]==2)
        {
            buy.setEnabled(false);
        }
        if(p[turn]==31||p[turn]==18||p[turn]==7)
        {
            try{  
                Class.forName("com.mysql.jdbc.Driver");  
                
                Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
                Statement stmt=con.createStatement(); 
                String query = "select task from chance where cid="+task;
                ResultSet rs=stmt.executeQuery(query);  
                while(rs.next())
                {
                    work = rs.getString(1); 
                }
                con.close();  
           
            }catch(Exception ex){ System.out.println(ex);} 
            chance(task,turn,m,players,3); 
        }
        if(p[turn]==23||p[turn]==15||p[turn]==2)
        {
            try{  
                Class.forName("com.mysql.jdbc.Driver");  
                
                Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
                Statement stmt=con.createStatement(); 
                String query = "select work from CommunityChest where Cid="+task;
                ResultSet rs=stmt.executeQuery(query);  
                while(rs.next())
                {
                    work = rs.getString(1); 
                }
                con.close();  
           
            }catch(Exception ex){ System.out.println(ex);}
            communityChest(task, turn, m, players, 3);
        }
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
            buy.setEnabled(false);
            m[turn]=m[turn]-rent;
            amt=m[turn];
            m[play]=m[play]+rent;
            what="<br>you paid Rs"+rent+" to "+name[play]+" as rent";
        }
        else
        {
            if(p[turn]==8)
            {
                m[turn]=m[turn]-500;
            }
            if(p[turn]==4)
            {
                m[turn]=m[turn]-250;
            }
            if(flag==1)
            {
                m[turn]=m[turn]+500;
                flag=0;
            }
            if(p[turn]==24)
            {
                m[turn]=m[turn]-500;
                pieces[turn].setLocation(xy.x[turn][8],xy.y[turn][8]);
                p[turn]=8;
                where="<html><h2>You landed on Go to Jail<br>So you have been arrested<br>Rs 500 has been debited</h2>";
            }
            amt=m[turn];
            try{  
                Class.forName("com.mysql.jdbc.Driver");  
                Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
                String query = "update players set amount ="+amt+" where pid="+turn;
                con.prepareStatement(query).execute();
                con.close();  
                }catch(Exception ex){ System.out.println(ex);}
                players[turn].setText(name[turn]+"("+amt+")");
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
           currentStatus.setText("<html><h2>"+where+what+"</h2><br>"+"<h2>"+work+"</h2>");
        repaint();
        
    }
    void set3(String x,String y,String z,String w)
    {
        currentStatus.setBounds(550,150,450,300);
        currentStatus.setVisible(true);
        currentStatus.setForeground(Color.BLACK);
        add(currentStatus);
        // initializing and setting properties to pieces
        pieces[0]=new JTextArea();
        pieces[1]=new JTextArea();
        pieces[2]=new JTextArea();
        pieces[3]=new JTextArea();
        pieces[0].setBackground(Color.GREEN);
        pieces[0].setBounds(485,85,15,15);
        pieces[1].setBackground(Color.red);
        pieces[1].setBounds(470,85,15,15);
        pieces[2].setBackground(Color.YELLOW);
        pieces[2].setBounds(455,85,15,15);
        pieces[3].setBackground(Color.BLUE);
        pieces[3].setBounds(440,85,15,15);
        add(pieces[0]);
        add(pieces[1]);
        add(pieces[2]);
        add(pieces[3]);

        // setting properties for area that displays current city
        // city.setBounds(1200,400,150,200);
        // city.setBackground(colour);
        // city.setBorder(new TitledBorder(new LineBorder(Color.black, 5),"Current"));
        // add(city);
        // setting properties for area that displays info of players / cities on clicking
        info.setBounds(1200,150,150,200);
        info.setBackground(colour);
        info.setBorder(new TitledBorder(new LineBorder(Color.black, 5),"info"));
        Font f22=new Font("TimesRoman",Font.BOLD,15);
        info.setFont(f22);
        add(info);
        // images for places
        cities[1]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/MEDIRTERRANEAN AVENUE.png");
        cities[2]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/COMMUNITY CHEST.png");
         cities[3]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/BALTIC AVENUE.png");
         cities[4]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/INCOME TAX.png"); 
         cities[5]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/READING RAILROAD.png");
         cities[6]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/ORIENTAL AVENUE.png");
         cities[7]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/CHANCE.png");
         cities[9]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/ST. CHARLES PLACE.png");
         cities[10]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/ELECTRIC COMPANY.png");
         cities[11]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/STATES AVENUE.png");
         cities[12]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/VIRGINIA AVENUE.png");
          cities[13]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/PENNSYLVANIA RAILROAD.png");
        
    
         cities[14]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/ST. JAMES PLACE.png");
         cities[15]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/COMMUNITY CHEST 4.png");
         cities[17]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/KENTUCKY AVENUE.png");
         cities[18]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/CHANCE 2.png");
         cities[19]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/INDIANA AVENUE.png");
         cities[20]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/ILLIONOIS AVENUE.png");
         cities[21]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/B & O RAILROAD.png");
         cities[22]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/ATLANTIC AVENUE.png");
         cities[23]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/COMMUNITY CHEST 3.png");
         cities[25]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/PACIFIC AVENUE.png");
         cities[26]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/NORTH CAROLINA AVENUE.png");
         cities[27]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/VENTNOR AVENUE.png");
         cities[28]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/PENNSYLVANIA AVENUE.png");
         cities[29]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/SHORT LINE.png");
         cities[30]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/PARK PLACE.png");
         cities[31]=new ImageIcon("C:/Users/Asus/Desktop/GIT/codes/javacodes/monopoly/images/CHANCE 3.png");
        //  setting properties for corner squares of board
        btns[0]=new JButton(go);
        btns[0].setVisible(true);
        btns[0].setSize(100,100);
        btns[0].setCursor(cur);
        btns[0].setForeground(Color.RED);
        btns[0].addActionListener(in);
        add(btns[0]);

        btns[8]=new JButton(jail);
        btns[8].setVisible(true);
        btns[8].setSize(100,100);
        btns[8].setCursor(cur);
        btns[8].setForeground(Color.RED);
        btns[8].addActionListener(in);
        add(btns[8]);

        btns[16]=new JButton(parking);
        btns[16].setVisible(true);
        btns[16].setSize(100,100);
        btns[16].setCursor(cur);
        btns[16].setForeground(Color.RED);
        btns[16].addActionListener(in);
        add(btns[16]);

        btns[24]=new JButton(goTojail);
        btns[24].setVisible(true);
        btns[24].setSize(100,100);
        btns[24].setCursor(cur);
        btns[24].setForeground(Color.RED);
        btns[24].addActionListener(in);
        add(btns[24]);
        // creating non corner places
        for(int i=1;i<8;i++)
        {
            if(i==1)
            {
                btns[i]=new JButton(cities[i]);
                // btns[i].setText(Integer.toString(i));
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
                // btns[i].setText(Integer.toString(i));
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
            // btns[i].setText(Integer.toString(i));
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
            // btns[i].setText(Integer.toString(i));
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
            // btns[i].setText(Integer.toString(i));
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
                if(i<7)
                {
                    owns[i]=new JLabel();
                    owns[i].setBounds(500+(i-1)*70,200,70,10);
                    // owns[i-1].setBackground(colour);
                    // owns[i-1].setOpaque(true);
                    add(owns[i]);
                }
            }
        }
        for(int i=9;i<17;i++)
        {
            if(i<16)
            {
                owns[i]=new JLabel();
                owns[i].setBounds(980,200+(i-9)*70,10,70);
                // owns[i].setBackground(colour);
                // owns[i].setOpaque(true);
                add(owns[i]);
            }
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
            owns[i]=new JLabel();
            owns[i].setBounds(920-(i-17)*70,680,70,10);
            // owns[i].setBackground(colour);
            // owns[i].setOpaque(true);
            add(owns[i]);
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
                owns[i]=new JLabel();
                owns[i].setBounds(500,690-(i-24)*70,10,70);
                // owns[i].setBackground(colour);
                // owns[i].setOpaque(true);
                add(owns[i]);
            }
        }
        // assigning initial money to players
        m[0]=10000;
        m[1]=10000;
        m[2]=10000;
        m[3]=10000;

        // player buttons
        players[0]=new JButton(x+"("+m[0]+")");
        players[0].setVisible(true);
        players[0].setSize(240,40);
        players[0].setLocation(50,400);
        players[0].setCursor(cur);
        players[0].setForeground(Color.RED);
        // players[0].addActionListener(new ActionListener(){
        //     public void actionPerformed(ActionEvent e)
        //     {
        //        city.setText(x+"\n"+x);
        //     }
        // });
        add(players[0]);
        players[1]=new JButton(y+"("+m[1]+")");
        players[1].setVisible(true);
        players[1].setSize(240,40);
        players[1].setLocation(50,460);
        players[1].setCursor(cur);
        players[1].setForeground(Color.RED);
        buy.setForeground(Color.WHITE);                                      
        buy.setBorder(BorderFactory.createLineBorder(Color.WHITE,3));
        buy.setBackground(Color.BLUE);
        roll.setForeground(Color.WHITE);                                      
        roll.setBorder(BorderFactory.createLineBorder(Color.WHITE,3));
        roll.setBackground(Color.BLUE);
        // players[1].addActionListener(new ActionListener(){
        //     public void actionPerformed(ActionEvent e)
        //     {
        //        city.setText(y+"\n"+y);
        //     }
        // });
        add(players[1]);



        players[2]=new JButton(z+"("+m[2]+")");
        players[2].setVisible(true);
        players[2].setSize(240,40);
        players[2].setCursor(cur);
        players[2].setLocation(50,520);
        players[2].setForeground(Color.RED);
        // players[2].addActionListener(new ActionListener(){
        //     public void actionPerformed(ActionEvent e)
        //     {
        //        city.setText(z+"\n"+z);
        //     }
        // });
        add(players[2]);


        players[3]=new JButton(w+"("+m[3]+")");
        players[3].setVisible(true);
        players[3].setSize(240,40);
        players[3].setCursor(cur);
        players[3].setLocation(50,580);
        players[3].setForeground(Color.RED);
        // players[3].addActionListener(new ActionListener(){
        //     public void actionPerformed(ActionEvent e)
        //     {
        //        city.setText(w+"\n"+w);
        //     }
        // });
        add(players[3]);
        for(int i=0;i<players.length;i++)
        {
            players[i].setForeground(Color.WHITE);                                      
            players[i].setBorder(BorderFactory.createLineBorder(Color.WHITE,3));
            players[i].setBackground(Color.BLACK); 
        }
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
                turn=(turn+1)%4;
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
        game[0].setForeground(Color.WHITE);                                      
        game[0].setBorder(BorderFactory.createLineBorder(Color.WHITE,3));
        game[0].setBackground(Color.BLUE);
        game[1].setForeground(Color.WHITE);                                      
        game[1].setBorder(BorderFactory.createLineBorder(Color.WHITE,3));
        game[1].setBackground(Color.BLUE);
        game[0].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e)
            {
                JOptionPane.showMessageDialog(null,"game ended", "title",JOptionPane.PLAIN_MESSAGE);
                System.exit(0);
            }
        });;
        // dice rolling button
        roll.setVisible(true);
        roll.setSize(210,30);
        roll.setCursor(cur);
        roll.setLocation(640,650);
        // roll.setForeground(Color.RED);
        roll.addActionListener(this);
        add(roll);
        // buy button
        buy.setVisible(true);
        buy.setSize(80,30);
        buy.setCursor(cur);
        buy.setLocation(1235,360);
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
                        currentStatus.setText("<html><h2>You bought "+c.C[p[turn]]+"</h2>");
                        switch(turn)
                        {
                            case 0 : owns[p[turn]].setBackground(Color.GREEN);
                                     owns[p[turn]].setOpaque(true);
                                     break;
                            case 1 : owns[p[turn]].setBackground(Color.red);
                                     owns[p[turn]].setOpaque(true);
                                     break;
                            case 2 : owns[p[turn]].setBackground(Color.YELLOW);
                                     owns[p[turn]].setOpaque(true);
                                     break;
                            case 3 : owns[p[turn]].setBackground(Color.BLUE);
                                     owns[p[turn]].setOpaque(true);
                                     break;
                        }
                    }
                if(turn==3){
                    players[turn].setText(y+"("+m[turn]+")");
                    try{  
                        Class.forName("com.mysql.jdbc.Driver");  
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
                        String query = "update players set amount ="+amt+" where pid=3";
                        con.prepareStatement(query).execute();
                        con.close();  
                        }catch(Exception ex){ System.out.println(ex);}  

                }
                if(turn==2){
                    players[turn].setText(y+"("+m[turn]+")");
                    try{  
                        Class.forName("com.mysql.jdbc.Driver");  
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
                        String query = "update players set amount ="+amt+" where pid=2";
                        con.prepareStatement(query).execute();
                        con.close();  
                        }catch(Exception ex){ System.out.println(ex);}  

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
        Font f=new Font("TimesRoman",Font.BOLD,20);
        game[0].setFont(f);
        game[1].setFont(f);
        buy.setFont(f);
        roll.setFont(f);
        players[0].setFont(f);
        players[1].setFont(f);
        players[2].setFont(f);
        players[3].setFont(f);
        // title and icon for frame
        this.setTitle("monopoly game");                                        
        this.setIconImage(icon.getImage()); 
        setSize(1500, 1500);
        ImageIcon dice1=new ImageIcon(getClass().getResource("face1.png"));
        ImageIcon dice2=new ImageIcon(getClass().getResource("face2.png"));
        f1=new JLabel(dice1);
        f2=new JLabel(dice2);
        //creating labels to display dice faces
        f1.setBounds(675,550,50,50);
        f2.setBounds(765,550,50,50);
        add(f1);
        add(f2);   
    }
}
// class that has action listener for city and player buttons
class information2 implements ActionListener
{
    cities c=new cities();
    public void actionPerformed(ActionEvent e)
    {
        // gets text from buttons that calls action
        // String str=((AbstractButton) e.getSource()).getText();
        String city="";
        String owner="None";
        int rent=-1,price=-1;
        int owns=-1;
        for(int i=0;i<32;i++)
        {
            if((AbstractButton) e.getSource()==board3.btns[i])
            {
                try{  
                    Class.forName("com.mysql.jdbc.Driver");  
                    Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/monopoly","root","");  
                    String query = "select landprice,rent from land where lid="+i;
                    String query1 = "select pid from owns where lid="+i;
                    Statement stmt=con.createStatement(); 
                    ResultSet rs=stmt.executeQuery(query);  
                    while(rs.next())
                    {
                        price = rs.getInt(1); 
                        rent = rs.getInt(2); 
                    }
                    ResultSet rs1=stmt.executeQuery(query1);  
                    while(rs1.next())
                    {
                        owns = rs1.getInt(1);  
                    }
                    if(owns!=-1)
                    {
                        owner=board3.name[owns];
                    }
                    con.close();  
                    }catch(Exception ex){ System.out.println(ex);} 
                city=c.C[i];
                board3.info.setText(city+"\nprice = Rs"+price+"\nrent = Rs"+rent+"\nowner - "+owner);
                break;
            }
        }
    }
}
class boardMain2
{
    public static void main(String[] args) 
    {
        board3 b=new board3("p1","p2","p3","p4");
    }
}