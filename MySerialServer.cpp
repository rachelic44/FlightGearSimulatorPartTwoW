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


void funcForThread(bool* toStop,TCP_server tcp_server,TCP_client tcp_client
        ,ClientHandler* clientHandler, mutex* mutex1) {

    while (!(*toStop)) {

        if (tcp_client.getSockNumber() == -2) {
            *toStop=true;
            continue;
        }

        clientHandler->handleClient(tcp_client,mutex1);
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
    mutex* mutex1=new mutex();



    thread thread1(funcForThread,this->toStop,server,client,clientHandler,mutex1);
    thread1.detach();
    if(*(this->toStop)) {
        close(server.getSockNumber());
    }

}


void MySerialServer::stop(int serverNUmber) {
    close(serverNUmber);
}