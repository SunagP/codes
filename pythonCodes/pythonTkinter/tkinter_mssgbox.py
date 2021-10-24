from tkinter import *
from tkinter import messagebox

root=Tk()

root.iconbitmap(r"C:\Users\Asus\Pictures\try1.png")
# showinfo showerror , showwarning , askquestion ,askokcancel , askyesno
def popup():
    response=messagebox.askquestion("my mssg box","Hello this is me..")
    Label(root,text=response).pack()

Button(root,text="click me..",command=popup).pack()

root.mainloop()
