//
// Created by user on 06/01/19.
//

#include <netinet/in.h>
#include <unistd.h>
#include "MySerialServer.h"
#include <fcntl.h>

void MySerialServer::open(int portNumber, ClientHandler* clientHandler) {



    std::string tillNewLine ; /* The set of  data. */
    std::string dataRead    ; /* The un-used data. */
    char buffer[1024];        /* The data we currently read. */
    int readBytes;            /* The bytes we currently read. */
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr{}, cli_addr{};
    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    fcntl(sockfd,F_SETFL,O_NONBLOCK);

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = portNumber;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }


    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    while (true) { //changer from true to the class boolen member

        /* Read socket. */
        bzero(buffer, 1024);
        readBytes = (int) read(newsockfd, buffer, 1023);

        if (readBytes < 0) { /* Check if the read succeeded. */
            throw "Could not read from client."; /* If failed throw. */
        } else {

        }

        }
       // sleep(hz/1000);
    }


void MySerialServer::stop(int) {
    //thistoStop=true;
    //close(portnumbe
    //close all the clients that talk to us \9if there are)
}