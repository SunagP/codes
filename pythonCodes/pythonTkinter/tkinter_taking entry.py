from tkinter import *

root=Tk()
#creating button
#mybutton=Button(root,text="Clik me!")
#creating a button of required dimension use padx= 50 ,pady= 50
x=Label(root,text="Enter your Name...")
x.pack()
#taking entry
enter=Entry(root,width=50,borderwidth=4)
enter.pack()
#we can use insert function to add text in the entry box
enter.insert(0,"your name please..")
def myclick():
    mylabel=Label(root,text="hello " + enter.get())
    mylabel.pack()
    #fg is for font colour and bg is for background colour command is for function call don't use () during function call
mybutton=Button(root,text="Click me!",padx= 10 ,pady= 5,command=myclick,fg="black",bg="white")
mybutton.pack()

root.mainloop()
