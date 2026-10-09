import socket

PORT = 12345

hello = "Hello Server, this is Client."

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

HOST = "127.0.0.1"

try:
    client_socket.connect((HOST, PORT))
except ConnectionRefusedError:
    print("Connection failed.")
    client_socket.close()
    exit(1)

print("Connected to server!")

client_socket.send(hello.encode())

print("Message sent to server.")

buffer = client_socket.recv(1024)

if buffer:
    message = buffer.decode()
    print(f"Server says: {message}")
else:
    print("No response received from server.")

client_socket.close()









# Command to run the code ==> python3 client.py