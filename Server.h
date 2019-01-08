//
// Created by user on 06/01/19.
//

#ifndef PROJECTPART2_SERVER_H
#define PROJECTPART2_SERVER_H

#include "ClientHandler.h"

namespace server_side {

    class Server{

    public:
        virtual void open(int portNumber, ClientHandler* clientHandler) = 0;
        virtual void stop(int portNumber) = 0;
    };
}





#endif //PROJECTPART2_SERVER_H
