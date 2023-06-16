import socket
import csv

UDP_IP = "0.0.0.0"  # Listen on all available network interfaces
UDP_PORT = 8888

csv_file = "random_numbers.csv"

# Create a UDP socket
#These lines create a UDP socket (sock) using the socket.socket function. 
# The AF_INET parameter specifies the address family as IPv4, 
# and SOCK_DGRAM specifies that it is a UDP socket.
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

#The bind method is then used to bind the socket to the specified IP address and port number.
sock.bind((UDP_IP, UDP_PORT))

connected = False

print("Waiting for device connection...")

while True:
    # Receive UDP packet
    data, addr = sock.recvfrom(1024)
    random_num = data.decode().strip()

    if connected:
        print("Device connected")
        connected = True

    print("Received:", random_num)

    # Write to CSV file
    with open(csv_file, "a") as file:
        writer = csv.writer(file)
        writer.writerow([random_num])


