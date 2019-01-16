//
// Created by user on 13/01/19.
//

#ifndef PROJECTPART2_MYPARALLELSERVER_H
#define PROJECTPART2_MYPARALLELSERVER_H

#include "Server.h"
#include "CashMap.h"
#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
using namespace server_side;


class MyParallelServer : public Server {
private:
    vector<int> clientsVec;
    mutex* mutex1;
    bool *toStop;
public:
    MyParallelServer() {
        this->toStop= new bool(false);
    }
    virtual void open(int portNumber, ClientHandler* clientHandler);
    virtual void stop(int);
    //  void funcForThread(TCP_server tcp_server,TCP_client tcp_client,ClientHandler* clientHandler);

    ~MyParallelServer(){
        delete this->mutex1;
        delete this->toStop;
    }
};

#endif //PROJECTPART2_MYPARALLELSERVER_H
