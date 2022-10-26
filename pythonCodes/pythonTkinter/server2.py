import socket
import struct
import tkinter as tk
from tkinter import *
from tkinter.messagebox import showinfo

TCP_IP = '192.168.1.2'
TCP_PORT = 62
BUFFER_SIZE = 1024

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

conn, addr = s.accept()
print('Connection address:', addr)
li=[]
while 1:
     data = conn.recv(BUFFER_SIZE)
     if not data: break
     d = struct.unpack('f', data)
     print ("received data:", d)
     li.append(d)
     conn.send(data)


root = tk.Tk()

root.geometry("600x300")
root.resizable(False, False)
root.title('Angle input')

root.config(bg='cyan')
angle_val = tk.DoubleVar()
angle = Frame(root,bg='cyan')
angle.pack(padx=20, pady=10, fill='x', expand=True)
angle_label = Label(angle, text="Angle received:")
angle_label.pack(padx=224)
angle_label.pack(fill='x', expand=True)
s = f"angle 1 : {round(li[0][0],2)}\n angle 2 :{round(li[1][0],2)}"
angle_label = Label(angle, text=s,width=500)
angle_label.pack(padx=224)
angle_label.pack(fill='x', expand=True)

root.mainloop()

conn.close()
