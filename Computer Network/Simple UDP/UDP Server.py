# UDP_Server.py, tested under python 3.4
from socket import *

serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM) # create UDP socket
serverSocket.bind(('', serverPort))        # bind socket to local port (12000)
print("The server is ready to receive")    # In python using print("xxx") instead of print "xxx"

#loop forever
while 1:
    message, clientAddress = serverSocket.recvfrom(2048) # read from UDP socket into message, getting client address(IP and port)
    modifiedMessage = message.lower()                    # change the string into lower case
    serverSocket.sendto(modifiedMessage, clientAddress)  # send the modified string back to the client
