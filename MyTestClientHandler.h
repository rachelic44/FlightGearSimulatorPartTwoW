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
#include <strings.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include "PosixSocket.h"

using namespace posix_sockets;

class MyTestClientHandler : public ClientHandler {
private:
    Solver<string,string>* solver;
    CasheManager<std::string,std::string>* casheManager;
public:
    MyTestClientHandler(Solver<string,string>* reverseSolver,CasheManager<std::string,std::string>* casheManager ) {
        this->solver=reverseSolver;
        this->casheManager=casheManager;
    }

    virtual void handleClient(TCP_client client) {

        bool toContinue= true;
        while (toContinue) {

            string bufferReadFromCLient = client.read(1024);
            if (bufferReadFromCLient.find("end") != string::npos) {
                bufferReadFromCLient =bufferReadFromCLient.substr(0,bufferReadFromCLient.find("end"));
                toContinue=false;
                if(bufferReadFromCLient=="") {
                    continue;
                }
                cout<<"Was at non"<<endl;
            }
            cout << "here2" << endl;
            string ans = this->solver->solve(bufferReadFromCLient);
            client.write(ans);
        }
        client.close();
    }

};


#endif //PROJECTPART2_MYTESTCLIENTHANDLER_H
