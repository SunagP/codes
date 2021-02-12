from tkinter import *

root = Tk()

def show():
    Label(root,text=var.get()).pack()
var = StringVar()

c = Checkbutton(root,text="check me",variable=var,onvalue="yooo",offvalue="noooo")
c.deselect()
c.pack()
b=Button(root,text="hey click me",command=show).pack()

root.mainloop()
