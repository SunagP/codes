from tkinter import *
root=Tk()
root.geometry("400x400")

ver=Scale(root,from_=0,to=200)
ver.pack()


hori=Scale(root,from_=0,to=200,orient="horizontal")
hori.pack()


def slide():
    my_lb=Label(root,text=ver.get()).pack()
    my_lb1=Label(root,text=hori.get()).pack()
    root.geometry(str(hori.get())+'x'+str(ver.get()))



b=Button(root,text="click",command=slide).pack()
root.mainloop()
