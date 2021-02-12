from tkinter import *

root=Tk()

root.iconbitmap(r"C:\Users\Asus\Pictures\try1.png")

r=IntVar()
#r.set("1")


def click(value):
    mylabel=Label(root,text=value).pack()



Radiobutton(root,text="button 1",variable=r,value=1,command=lambda:click(r.get())).pack()
Radiobutton(root,text="button 2",variable=r,value=2,command=lambda:click(r.get())).pack()
mylabel=Label(root,text=r.get())
mylabel.pack()

mybutton=Button(root,text="click me...",command=lambda:click(r.get())).pack()
root.mainloop()
