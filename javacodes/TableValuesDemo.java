import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
// import java.util.ArrayList;
import java.util.HashMap;

// import com.mysql.jdbc.Statement;
import java.sql.*;

public class TableValuesDemo {
   public static void main(String[] args) {
      Connection con = null;
      Statement statement = null;
      try {
         HashMap hm = new HashMap<>();
         Class.forName("com.mysql.jdbc.Driver");
         con = DriverManager.getConnection("jdbc:mysql://localhost:3306/lab_2", "root", "");
         statement = (Statement) con.createStatement();
         String sql;
         sql = "select *from catalog";
         ResultSet resultSet = statement.executeQuery(sql);
         while (resultSet.next()) {
         hm.put(resultSet.getString("sid"), resultSet.getInt("pid"));
      }
      System.out.println(hm);

      } catch (Exception e) {
         e.printStackTrace();
      }
   }
}