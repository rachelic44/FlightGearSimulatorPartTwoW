//
// Created by user on 13/01/19.
//

#ifndef PROJECTPART2_MYCLIENTHANDLER_H
#define PROJECTPART2_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "ISearcher.h"
#include "CasheManager.h"
#include "Matrix.h"

using namespace posix_sockets;

template <class T>
class MyClientHandler : public ClientHandler {

private:
    Solver<Isearchable<T>*,string>* solver;
    CasheManager<std::string,std::string>* casheManager;
public:
    MyClientHandler(Solver<Isearchable<T>,string>* solver1, CasheManager<std::string,std::string>* casheManager) {
        this->solver=solver1;
        this->casheManager=casheManager;
    }

    virtual void handleClient(TCP_client client) {

        bool toContinue= true;
        while (toContinue) {

            string bufferReadFromCLient = client.read(1024);
            if (bufferReadFromCLient.find("end") != string::npos) {
                bufferReadFromCLient=bufferReadFromCLient.substr(0,bufferReadFromCLient.find("end"));
                toContinue=false;
                if(bufferReadFromCLient=="") {
                    continue;
                }
                cout<<"Was at non"<<endl;
            }
            vector<string> linesVec=splitByDelimeter(bufferReadFromCLient);
            string target = linesVec.back();
            linesVec.pop_back();
            string start = linesVec.back();
            linesVec.pop_back();
            Isearchable<T>* isearchable = new Matrix(linesVec,start,target);

            cout << "here2" << endl;
            string ans = this->solver->solve(isearchable);
            client.write(ans);
        }
        client.close();
    }

    vector<string> splitByDelimeter(string string1, string delimeter) {
        string part;
        vector<string> splitted;
        while(string1.find(delimeter)!= string::npos) {
            part=string1.substr(0,string1.find(delimeter));
            splitted.push_back(part);
            string1=string1.substr(0,string1.find(delimeter));
        }
        return splitted;
    }

};


#endif //PROJECTPART2_MYCLIENTHANDLER_H
