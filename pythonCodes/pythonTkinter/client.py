import socket
import tkinter as tk
from tkinter import *
from tkinter.messagebox import showinfo
import struct

def Verify_send():
    x = angle_val.get()
    if x >=-60.0 and x <= 60.0:
         ba = bytearray(struct.pack("f", x))

         host = '192.168.1.1'  # as both code is running on same pc
         port = 62  # socket server port number

         client_socket = socket.socket()  # instantiate
         client_socket.connect((host, port))  # connect to the server

         client_socket.send(ba)  # send message
         data = client_socket.recv(1024).decode()  # receive response

         print('Received from server: ' + data)  # show in terminal

         client_socket.close()

    else:
        showinfo(title="Invalid input",message="Angle must be in range of -60 to +60 \n please enter proper angle")



root = tk.Tk()

root.geometry("600x300")
root.resizable(False, False)
root.title('Angle input')

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
