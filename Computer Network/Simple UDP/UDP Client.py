# UDP_Client.py, tested under python 3.4
from socket import *        # include socket library

#serverName = ‘hostname’    # can be domain name like foo.com or ip like 1.2.3.4
serverName = '127.0.0.1'    # 127.0.0.1 for local host
serverPort = 12000          # using port > 1024 is recommanded
clientSocket = socket(AF_INET, SOCK_DGRAM)      # create UDP socket for server
message = input('Input uppercase sentence:')    # In python3, using input() to replace raw_input(), get user keypboard input
str2Bytes=message.encode('utf-8')               # In Python 3, the string (first) argument must be of type bytes or buffer, not str
clientSocket.sendto(str2Bytes,(serverName, serverPort))		# attach server name, port to message; send into socket
modifiedBytes, serverAddress = clientSocket.recvfrom(2048)	# read reply characters from socket
modifiedMessage = modifiedBytes.decode() # convert the bytes to string
print(modifiedMessage)	# In python3 using print("xxx") to replace print "xxx", print out the received string
clientSocket.close()	# close socket
