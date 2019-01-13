//
// Created by user on 06/01/19.
//

#include <netinet/in.h>
#include <unistd.h>
#include "MySerialServer.h"
#include <fcntl.h>
#include <string.h>


void MySerialServer::open(int portNumber, ClientHandler* clientHandler) {


    int sockfd, newsockfd, portno, clilent;
    struct sockaddr_in serv_addr{}, cli_addr{};
    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket server");
        exit(1);
    }


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

    listen(sockfd, SOMAXCONN);
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);


    int new_sock;

    timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));

    new_sock = accept(sockfd, (struct sockaddr *) &client, &clilen);
    if (new_sock < 0) {
        if (errno == EWOULDBLOCK || errno == EAGAIN) {
            cout << "timeout!" << endl;
            exit(2);
        } else {
            perror("other error");
            exit(3);
        }
    }
    cout << new_sock << endl;
    cout << sockfd << endl;

    while (true) { //changer from true to the class boolen member


        if (new_sock < 0) {
            stop(sockfd);

        }

        cout<<new_sock<< " the num"<<endl;
        cout<<"Sending"<<endl;
        clientHandler->handleClient(new_sock);
        new_sock = accept(sockfd, (struct sockaddr *) &client, &clilen);
    }
    // sleep(hz/1000);

}


void MySerialServer::stop(int serverNUmber) {
    cout<<"stopped";
    close(serverNUmber);
    //thistoStop=true;
    //close(portnumbe
    //close all the clients that talk to us \9if there are)
}