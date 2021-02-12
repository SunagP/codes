from tkinter import *

root = Tk()
#creating widget
mylabel= Label(root,text="hello world!!!")
mylabel1= Label(root,text="I'm Sunag P")
#showing on the screen
#mylabel.pack()
#mylabel1.pack()
#we can use grid()also instead of pack() to form grid like patterns
mylabel2= Label(root,text="I live in Bengaluru")
mylabel.grid(row=0,column=0)
mylabel1.grid(row=1,column=0)
mylabel2.grid(row=2,column=0)
root.mainloop()
