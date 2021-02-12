from tkinter import *
from tkinter import messagebox
from PIL import ImageTk,Image
root=Tk()

root.iconbitmap(r"C:\Users\Asus\Pictures\try1.png")
root.title("1st window..")


def open():
    global i
    top=Toplevel()
    top.title('2nd window...')

    i=ImageTk.PhotoImage(Image.open(r"C:\Users\Asus\Pictures\try1.png"))
    my_lb=Label(top,image=i).pack()
    b2=Button(top,text="Exit..",command=top.destroy).pack()

b=Button(root,text="click to view 2nd window..",command=open).pack()









root.mainloop()
