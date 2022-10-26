import sqlite3 as s

con  = s.connect("Emp.db")

cur = con.cursor()

try:
    cur.execute(''' create table employee(emp_ssn INTEGER PRIMARY key,
    emp_name text,
    emp_category text,
    gross_sal real,
    basic_sal real)''')

except :
    pass

for item in (
    (1,"Preetham","A",'NULL',1000),
    (2,"Sumith","B",'NULL',1000),
    (3,"Rishabh","C",'NULL',1000)
):cur.execute("insert into employee values(?,?,?,?,?)",item)



cur.execute("select * from employee")
empTup = cur.fetchall()

# print(empTup)
# cat = input("Enter category ")
for i in empTup:
    if i[2] =='A':
        sal = 0.8*i[-1] + i[-1]
        g=0.3*sal
    elif i[2] =='B':
        sal = 0.5*i[-1] + i[-1]
        g=0.2*sal
    else :
        sal = 0.2*i[-1] + i[-1]
        g=0.1*sal
        #cur.execute("update employee set gross_sal = "+str(g)+" where emp_category = "+str(cat))
    cur.execute(f"update employee set gross_sal={g} where emp_ssn={i[0]}")
# print(cat)
cur.execute("select * from employee")
print(cur.fetchall())