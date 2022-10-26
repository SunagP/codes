import socket
import tkinter as tk
from tkinter import *
from tkinter.messagebox import showinfo
import struct
def float_bin(my_number, places = 3):
	my_whole, my_dec = str(my_number).split(".")
	my_whole = int(my_whole)
	res = (str(bin(my_whole))+".").replace('0b','')

	for x in range(places):
		my_dec = str('0.')+str(my_dec)
		temp = '%1.20f' %(float(my_dec)*2)
		my_whole, my_dec = temp.split(".")
		res += my_whole
	return res



def IEEE754(n) :
	sign = 0
	if n < 0 :
		sign = 1
		n = n * (-1)
	p = 30

	dec = float_bin (n, places = p)

	dotPlace = dec.find('.')
	onePlace = dec.find('1')

	if onePlace > dotPlace:
		dec = dec.replace(".","")
		onePlace -= 1
		dotPlace -= 1
	elif onePlace < dotPlace:
		dec = dec.replace(".","")
		dotPlace -= 1
	mantissa = dec[onePlace+1:]


	exponent = dotPlace - onePlace
	exponent_bits = exponent + 127


	exponent_bits = bin(exponent_bits).replace("0b",'')

	mantissa = mantissa[0:23]


	final = str(sign) + exponent_bits.zfill(8) + mantissa


	# hstr = '0x%0*X' %((len(final) + 3) // 4, int(final, 2))
	return final


def Verify_send():
    x = angle_val.get()
    if x >=-60.0 and x <= 60.0:
         # ba = bytearray(struct.pack("f", x))
         ba = IEEE754(x)

         host = '192.168.1.1'
         port = 62  

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
