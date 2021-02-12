from tkinter import *

root=Tk()
root.title("Calculator")
enter=Entry(root,borderwidth=5,width=35)
enter.grid(row=0,column=1,columnspan=3,padx=10,pady=10)

def  button_click(number):
    current=enter.get()
    enter.delete(0,END)
    enter.insert(0,str(current) + str(number))


def button_clear():

    enter.delete(0,END)


def button_add():
    first_number=enter.get()
    global f_num
    global math
    math="add"
    f_num=first_number
    enter.delete(0,END)



def button_sub():
    first_number=enter.get()
    global f_num
    global math
    math="sub"
    f_num=first_number
    enter.delete(0,END)

def button_mul():
    first_number=enter.get()
    global f_num
    global math
    math="mul"
    f_num=first_number
    enter.delete(0,END)

def button_div():
    first_number=enter.get()
    global f_num
    global math
    math="div"
    f_num=first_number
    enter.delete(0,END)

def button_enter():
    sec_num=enter.get()
    enter.delete(0,END)
    if math == "add":
        enter.insert(0,int(f_num)+int(sec_num))
    if math == "sub":
        enter.insert(0,int(f_num)-int(sec_num))
    if math == "mul":
        enter.insert(0,int(f_num)*int(sec_num))
    if math == "div":
        enter.insert(0,int(f_num)/int(sec_num))


button_1=Button(root,text=1,padx=40,pady=20,command=lambda : button_click(1))
button_2=Button(root,text=2,padx=40,pady=20,command=lambda : button_click(2))
button_3=Button(root,text=3,padx=40,pady=20,command=lambda : button_click(3))
button_4=Button(root,text=4,padx=40,pady=20,command=lambda : button_click(4))
button_5=Button(root,text=5,padx=40,pady=20,command=lambda : button_click(5))
button_6=Button(root,text=6,padx=40,pady=20,command=lambda : button_click(6))
button_7=Button(root,text=7,padx=40,pady=20,command=lambda : button_click(7))
button_8=Button(root,text=8,padx=40,pady=20,command=lambda : button_click(8))
button_9=Button(root,text=9,padx=40,pady=20,command=lambda : button_click(9))
button_0=Button(root,text=0,padx=40,pady=20,command=lambda : button_click(0))
button_clear=Button(root,text="clear",padx=79,pady=20,command=button_clear)
button_enter=Button(root,text="=",padx=91,pady=20,command= button_enter)
button_add=Button(root,text="+",padx=39,pady=20,command= button_add)
button_sub=Button(root,text="-",padx=41,pady=20,command= button_sub)
button_mul=Button(root,text="*",padx=42,pady=20,command= button_mul)
button_div=Button(root,text="/",padx=40,pady=20,command= button_div)

button_1.grid(row=1,column=1)
button_2.grid(row=1,column=2)
button_3.grid(row=1,column=3)
button_4.grid(row=2,column=1)
button_5.grid(row=2,column=2)
button_6.grid(row=2,column=3)
button_7.grid(row=3,column=1)
button_8.grid(row=3,column=2)
button_9.grid(row=3,column=3)
button_0.grid(row=4,column=1)
button_clear.grid(row=4,column=2,columnspan=2)
button_enter.grid(row=5,column=2,columnspan=2)
button_add.grid(row=5,column=1)
button_sub.grid(row=6,column=1)
button_mul.grid(row=6,column=2)
button_div.grid(row=6,column=3)


root.mainloop()
