from tkinter import *

root=Tk()

my_lb=LabelFrame(root,text="my frame...",padx=50,pady=50)


my_lb.pack(padx=10,pady=10)

b=Button(my_lb,text="click me..")

b.grid()

root.mainloop()
