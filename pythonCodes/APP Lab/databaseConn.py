import sqlite3 as s

con = s.connect("NewDB.db")

c = con.cursor()

# c.execute("create table mytable(name varchar,age int);")
#c.execute("insert into mytable values('sunag',21);")
# l=[('sumith',21),('venky reddy',21),('pradeep',21)]
# c.executemany("""INSERT INTO mytable VALUES(?,?)""",l)
#c.execute("""DELETE FROM mytable WHERE name='pradeep'""")

c.execute("select * from mytable")

x=c.fetchone()[0]
print(x)
con.commit()
