import socket

PORT = 12345

hello = "Hello Client, message received!"

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

HOST = "0.0.0.0"

server_socket.bind((HOST, PORT))

server_socket.listen(3)

print(f"Server listening on port {PORT}...")

client_socket, client_address = server_socket.accept()

print("Client connected!")

buffer = client_socket.recv(1024)

if buffer:
    message = buffer.decode()
    print(f"Client says: {message}")
else:
    print("Failed to receive message.")

client_socket.send(hello.encode())

print("Response sent to client.")

client_socket.close()
server_socket.close()







# Command to run the code ==>  python3 server.py