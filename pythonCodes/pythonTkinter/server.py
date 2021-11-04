import socket
import struct
TCP_IP = '192.168.1.2'
TCP_PORT = 62
BUFFER_SIZE = 1024

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

conn, addr = s.accept()
print('Connection address:', addr)
while 1:
     data = conn.recv(BUFFER_SIZE)
     if not data: break
     d = struct.unpack('f', data)
     print ("received data:", d)
     conn.send(data)
conn.close()
