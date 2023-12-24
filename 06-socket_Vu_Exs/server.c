/*
 *This is server side
 *Listen util a client connect 
 *Accept and sent data to client
 *Close when done
 */
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_CLIENT_NO  2

int main(void)
{
    int port_no;
    port_no = 8000;
    int opt = 1;
    int server_fd, client_fd;
    char client_buffer[1024] = { 0 };
    char* server_data = "Data from server";
    //declare server socket struct
    struct sockaddr_in serv_addr;
    //server_fd = socket() use IPV4 and STREAM SOCKET
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    //prevent used ports and addresses
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    //assign serv_addr important attributes
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port   = htons(port_no);
    //bind process
    if (bind(server_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) 
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    //passively listten for MAX_CLIENT_NO clients 
    if (listen(server_fd, MAX_CLIENT_NO) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    //accept connection base on accept return value to create a socket between server and client
    if ((client_fd = accept(server_fd, (struct sockaddr*)&serv_addr, &serv_addr)) < 0) 
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    //truncate data for stdout 
    read(client_fd, client_buffer, 1024 - 1); 
    printf("%s\n", client_buffer);
    send(client_fd, server_data, strlen(server_data), 0);
    printf("Client message data was sent\n");
 
    // closing the connected socket
    close(client_fd);
    // closing the listening socket
    close(server_fd);
    return 0;
}