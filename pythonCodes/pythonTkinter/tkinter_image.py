#moving images forward and backward
#creating status bar


from tkinter import *

root = Tk()
root.title("yo yo ...")
#to change the icon
root.iconbitmap(r"C:\Users\Asus\Pictures\try3.png")


from PIL import ImageTk,Image

my_pic1=ImageTk.PhotoImage(Image.open(r'C:\Users\Asus\Pictures\try3.png'))
my_pic2=ImageTk.PhotoImage(Image.open(r'C:\Users\Asus\Pictures\try1.png'))
my_pic3=ImageTk.PhotoImage(Image.open(r'C:\Users\Asus\Pictures\ginni formula.png'))
my_pic4=ImageTk.PhotoImage(Image.open(r'C:\Users\Asus\Pictures\amma.png'))
my_pic5=ImageTk.PhotoImage(Image.open(r'C:\Users\Asus\Pictures\numpy function.png'))

my_pic_list=[my_pic1,my_pic2,my_pic3,my_pic4,my_pic5]

my_label=Label(image=my_pic1)
my_label.grid(row=0,column=0,columnspan=3)
#creating status bar
#anchor specifies the diretion where text should be present
status=Label(root,text="Image 1 of "+str(len(my_pic_list)),bd=1,relief=SUNKEN,anchor=E)
def forward(pic_num):
    global my_label
    global button_back
    global button_forward

    my_label.grid_forget()
    my_label=Label(image=my_pic_list[pic_num-1])
    button_forward=Button(root, text=">>",command= lambda : forward(pic_num+1))
    status=Label(root,text="Image " + str(pic_num) +"of "+str(len(my_pic_list)),bd=1,relief=SUNKEN,anchor=E)
    status.grid(row=2,column=0,columnspan=3,sticky=W+E)
    #button_back=Button(root, text="<<",command= lambda : backward(pic_num-1))

    if(pic_num==5):
        button_forward=Button(root, text=">>",state=DISABLED)

    button_back.grid(row=1,column=2)
    button_forward.grid(row=1,column=2)
    my_label.grid(row=0,column=0,columnspan=3)

def backward(pic_num):
    global my_label
    global button_back
    global button_forward

    my_label.grid_forget()
    my_label=Label(image=my_pic_list[pic_num-1])
    button_forward=Button(root, text=">>",command= lambda : forward(pic_num+1))
    button_back=Button(root, text="<<",command= lambda : backward(pic_num-1))
    #if(pic_num==1):
        #button_back=Button(root, text="<<",state=DISABLED)

    button_back.grid(row=1,column=2)
    button_forward.grid(row=1,column=2)
    my_label.grid(row=0,column=0,columnspan=3)


button_back=Button(root, text="<<",command=backward)
button_forward=Button(root, text=">>",command= lambda : forward(2))
button_exit=Button(root,text="Exit..",command=root.quit)


button_back.grid(row=1,column=0)
button_forward.grid(row=1,column=2)
button_exit.grid(row=1,column=1)
status.grid(row=2,column=0,columnspan=3,sticky=W+E)

root.mainloop()
