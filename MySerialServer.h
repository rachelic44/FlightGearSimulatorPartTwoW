//
// Created by user on 06/01/19.
//

#ifndef PROJECTPART2_MYSERIALSERVER_H
#define PROJECTPART2_MYSERIALSERVER_H

#include "Server.h"
#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;

using namespace server_side;


struct serverParams {
    bool*  toStop;
    int tcp_client;
    int tcp_server;
    ClientHandler* clientHandler;
};


class MySerialServer : public Server {
private:
    vector<int> clientsVec;
    bool *toStop;
public:
    MySerialServer() {
        this->toStop= new bool(false);
    }
    virtual void open(int portNumber, ClientHandler* clientHandler);
    virtual void stop(int);
  //  void funcForThread(TCP_server tcp_server,TCP_client tcp_client,ClientHandler* clientHandler);
};


#endif //PROJECTPART2_MYSERIALSERVER_H
