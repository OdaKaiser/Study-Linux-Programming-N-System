#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char const* argv[])
{
    int status, valread, client_fd, port_no;
    port_no = 8000;
    //declare client socket struct using server address
    struct sockaddr_in serv_addr;
    char* client_data = "Data from client";
    char buffer[1024] = {0};
    //server_fd = socket() use IPV4 and STREAM SOCKET
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    ///assign serv_addr important attributes
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_no);
    //prevent used ports and addresses
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }
    //check status connection base on accept return value
    if ((status = connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0) 
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    //send data to server
    send(client_fd, client_data, strlen(client_data), 0);
    printf("Client message data was sent\n");
    //truncate data for stdout 
    valread = read(client_fd, buffer, 1024 - 1); 
    printf("%s\n", buffer);
    // closing the connected socket
    close(client_fd);
    return 0;
}