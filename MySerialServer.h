//
// Created by user on 06/01/19.
//

#ifndef PROJECTPART2_MYSERIALSERVER_H
#define PROJECTPART2_MYSERIALSERVER_H

#include "Server.h"
#include <iostream>
#include <strings.h>

using namespace std;

using namespace server_side;

class MySerialServer : public Server {
public:
    virtual void open(int portNumber, ClientHandler* clientHandler);
    virtual void stop(int);
};


#endif //PROJECTPART2_MYSERIALSERVER_H
