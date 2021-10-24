from tkinter import *

root=Tk()
#creating button
#mybutton=Button(root,text="Clik me!")
#creating a button of required dimension use padx= 50 ,pady= 50
def myclick():
    mylabel=Label(root,text="hello world!!")
    mylabel.pack()
    #fg is for font colour and bg is for background colour command is for function call don't use () during function call
mybutton=Button(root,text="Click me!",padx= 10 ,pady= 5,command=myclick,fg="black",bg="blue")
mybutton.pack()

root.mainloop()
