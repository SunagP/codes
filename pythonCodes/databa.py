import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  password="",
  database="lab1"
)
sql = "SELECT * FROM emp "
# print(mydb.database)

try:
   # Execute the SQL command
   cursor = mydb.cursor()
   cursor.execute(sql)
   # Fetch all the rows in a list of lists.
   results = cursor.fetchall()
   for row in results:
      fname = row[0]
      ssn = row[1]
      bdate = row[2]
      # sex = row[3]
      # income = row[4]
      # Now print fetched result
      # print(fname,ssn,bdate)
      print( "fname=%s,ssn=%d" % \
            (fname, ssn))
except:
   print ("Error: unable to fecth data")

# disconnect from server
mydb.close()
