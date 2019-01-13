//
// Created by user on 06/01/19.
//

#include <netinet/in.h>
#include <unistd.h>
#include "MySerialServer.h"
#include <fcntl.h>
#include <string.h>
#include "PosixSocket.h"
#include <pthread.h>
#include <thread>

using namespace posix_sockets;


/*
void *threadOpen(void *params) {
    struct serverParams *parameters = static_cast<struct serverParams *>(params);
    TCP_server server=parameters->tcp_server;
    TCP_client client=parameters->tcp_client;


    while (!(*parameters->toStop)) {

        if (parameters->tcp_client.getSockNumber() == -2 ) {
            cout<<"atStop";
            *parameters->toStop= true;
            continue;
        }

        cout<< client.getSockNumber() << " the num"<<endl;
        cout<<"Sending"<<endl;
        parameters->clientHandler->handleClient(client);
        client = server.accept();
    }

}*/

void funcForThread(bool* toStop,TCP_server tcp_server,TCP_client tcp_client,ClientHandler* clientHandler) {
    while (!(*toStop)) {

        if (tcp_client.getSockNumber() == -2) {
            cout << "atStop";
            *toStop=true;
            continue;
        }

        clientHandler->handleClient(tcp_client);
        tcp_client = tcp_server.accept();
    }
    tcp_server.close();

}

void MySerialServer::open(int portNumber, ClientHandler* clientHandler) {


    TCP_server server(portNumber);
    server.listen(SOMAXCONN);
    server.settimeout(0,0);
    TCP_client client=server.accept();
    server.settimeout(1,0);
    *(this->toStop)= false;



    thread thread1(funcForThread,this->toStop,server,client,clientHandler);
    thread1.detach();
    if(*(this->toStop)) {
        close(server.getSockNumber());
        cout<<"ht"<<endl;
    }

}


void MySerialServer::stop(int serverNUmber) {
    close(serverNUmber);
}