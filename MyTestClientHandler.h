//
// Created by user on 06/01/19.
//

#ifndef PROJECTPART2_MYTESTCLIENTHANDLER_H
#define PROJECTPART2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CasheManager.h"
#include <iostream>
#include "ReverseSolver.h"


class MyTestClientHandler : public ClientHandler {
private:
    Solver<string,string>* solver;
    CasheManager<std::string,std::string>* casheManager;
public:
    MyTestClientHandler() {
        ReverseSolver* reverseSolver= new ReverseSolver();
        this->solver=reverseSolver;
    }

};


#endif //PROJECTPART2_MYTESTCLIENTHANDLER_H
