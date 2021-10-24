import tkinter as tk
from tkinter import *
from tkinter.messagebox import showinfo

def Verify_send():
    x = angle_val.get()
    if x >=-60.0 and x <= 60.0:
        showinfo(title="Valid input",message="Data verified succefully")
    else:
        showinfo(title="Invalid input",message="Angle must be in range of -60 to +60 \n please enter proper angle")
    
# root window

root = tk.Tk()

root.geometry("600x300")
root.resizable(False, False)
root.title('Angle input')
bgimg = PhotoImage(file=r'C:\Users\Asus\Desktop\GIT\codes\pythonCodes\pythonTkinter\img1.png')
canvas1 = Canvas( root, width = 400,
                 height = 400)
  
# canvas1.pack(fill = "both", expand = True)
  
# # Display image
# canvas1.create_image( 0, 0, image = bgimg, 
#                      anchor = "nw")
root.config(bg='cyan')
angle_val = tk.DoubleVar()
angle = Frame(root,bg='cyan')
angle.pack(padx=10, pady=10, fill='x', expand=True)
angle_label = Label(angle, text="Enter Angle :")
angle_label.pack(padx=224)
angle_label.pack(fill='x', expand=True)

angle_entry = Entry(angle, textvariable=angle_val)
angle_entry.pack(pady=10)
angle_entry.focus()

Submit_button = Button(angle, text="Submit", command=Verify_send)

Submit_button.pack(pady=10)


root.mainloop()