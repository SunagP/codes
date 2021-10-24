from tkinter import *
from tkinter import messagebox
from PIL import ImageTk,Image
from tkinter import filedialog
root=Tk()

root.iconbitmap(r"C:\Users\Asus\Pictures\try1.png")


def open():
    global my_img
    root.my_file=filedialog.askopenfilename(initialdir=r"C:\Users\Asus\Pictures",title="my files",filetype=(("png files",'*.png'),("jpg file","*.jpg"),("all files","*.*")))
    my_lb=Label(root,text=root.my_file).pack()
    my_img=ImageTk.PhotoImage(Image.open(root.my_file))
    my_lb_img=Label(image=my_img).pack()

b=Button(root,text="open files",command=open).pack()
b1=Button(root,text="exit..",command=root.destroy).pack()



root.mainloop()
