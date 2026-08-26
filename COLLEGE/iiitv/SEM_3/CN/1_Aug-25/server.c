#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 12345

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    int opt = 1;
    char buffer[1024] = {0};

    char *hello = "Hello Client, message received!";

    // Create socket: IPv4, TCP
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    {
        perror("Socket failed");
        return 1;
    }

    // Allow reuse of address
    if (setsockopt(
            server_fd,
            SOL_SOCKET,
            SO_REUSEADDR,
            &opt,
            sizeof(opt)) < 0)
    {
        perror("setsockopt failed");
        close(server_fd);
        return 1;
    }

    // Server address: IPv4
    address.sin_family = AF_INET;

    // Listen for connections from any IPv4 network
    address.sin_addr.s_addr = INADDR_ANY;

    // Server listens on port 12345
    address.sin_port = htons(PORT);

    // Bind socket to IP address and port
    if (bind(
            server_fd,
            (struct sockaddr *)&address,
            sizeof(address)) < 0)
    {
        perror("Bind failed");
        close(server_fd);
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("Listen failed");
        close(server_fd);
        return 1;
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept client connection
    new_socket = accept(
        server_fd,
        (struct sockaddr *)&address,
        &addrlen
    );

    if (new_socket < 0)
    {
        perror("Accept failed");
        close(server_fd);
        return 1;
    }

    printf("Client connected!\n");

    // Receive message from client
    int bytes_received = recv(
        new_socket,
        buffer,
        sizeof(buffer) - 1,
        0
    );

    if (bytes_received > 0)
    {
        buffer[bytes_received] = '\0';
        printf("Client says: %s\n", buffer);
    }
    else
    {
        printf("Failed to receive message.\n");
    }

    // Send response to client
    send(
        new_socket,
        hello,
        strlen(hello),
        0
    );

    printf("Response sent to client.\n");

    // Close sockets
    close(new_socket);
    close(server_fd);

    return 0;
}



// Command ==>> cc server.c -o server
//         ==>> ./server