import java.sql.*;

class sqlcon{  
public static void main(String args[]){  
try{  
Class.forName("com.mysql.jdbc.Driver");  
Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/sonoo","root","");  
 
Statement stmt=con.createStatement();  
String query = " insert into emp (id, name, age)" + " values (?, ?, ?)";
// String query = "insert into catallog values(6,6,6)";
PreparedStatement x = con.prepareStatement(query);
x.setInt(1, 6);
x.setString(2, "name3");
x.setInt(3, 6);
x.execute();
ResultSet rs=stmt.executeQuery("select * from emp");  
while(rs.next())  
System.out.println(rs.getInt(1)+"  "+rs.getString(2)+"  "+rs.getString(3));  

con.close();  
}catch(Exception e){ System.out.println(e);}  
}  
} 