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
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    char *hello = "Hello Server, this is Client.";

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        perror("Socket creation failed");
        return 1;
    }

    // Server address
    serv_addr.sin_family = AF_INET;

    // Server port
    serv_addr.sin_port = htons(PORT);

    // For testing both programs on the same computer
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        perror("Invalid address");
        close(sock);
        return 1;
    }

    // Connect to server
    if (connect(
            sock,
            (struct sockaddr *)&serv_addr,
            sizeof(serv_addr)) < 0)
    {
        perror("Connection failed");
        close(sock);
        return 1;
    }

    printf("Connected to server!\n");

    // Send message
    send(sock, hello, strlen(hello), 0);

    printf("Message sent to server.\n");

    // Receive response
    int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);

    if (bytes_received > 0)
    {
        buffer[bytes_received] = '\0';
        printf("Server says: %s\n", buffer);
    }
    else
    {
        printf("No response received from server.\n");
    }

    // Close socket
    close(sock);

    return 0;
}



// Command ==>> cc client.c -o client
//         ==>> ./client