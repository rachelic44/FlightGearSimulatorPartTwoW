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
#include "SearchSolver.h"
#include <sstream>
#include <mutex>

using namespace posix_sockets;

template<class T>
class MyClientHandler : public ClientHandler {

private:
    Solver<Isearchable<T> *, string> *solver;
    CasheManager<std::string, std::string> *casheManager;
public:
    MyClientHandler(Solver<Isearchable<T> *, string> *solver1, CasheManager<std::string, std::string> *casheManager) {
        this->solver = solver1;
        this->casheManager = casheManager;
    }


    virtual void handleClient(TCP_client client,mutex* mutex1) {


        string ans;
        string bufferReadFromCLient = "";
        client.settimeout(0, 0);
        bool toContinue = true;
        while (toContinue) {
            cout << bufferReadFromCLient << endl;
            bufferReadFromCLient += client.read(1024);
            if (bufferReadFromCLient.find("end") != string::npos) {
                bufferReadFromCLient = bufferReadFromCLient.substr(0, bufferReadFromCLient.find("end"));
                toContinue = false;
                if (bufferReadFromCLient == "") {
                    continue;
                }
            } else {
                continue;
            }

            bufferReadFromCLient=getRiddOfSpaces(bufferReadFromCLient);
            mutex1->lock();
            if (this->casheManager->solutionExistance(bufferReadFromCLient)) {
                ans = casheManager->getExistSolution(bufferReadFromCLient);
                cout<<"Good"<<endl;
                mutex1->unlock();
            } else {
                mutex1->unlock();
                vector<string> linesVec = splitByDelimeter(bufferReadFromCLient, "\n");
                string target = linesVec.back();
                linesVec.pop_back();
                string start = linesVec.back();
                linesVec.pop_back();
                Isearchable<T> *isearchable = new Matrix(linesVec, start, target);

                stringstream stringstreamOfProblem;
                cout<<"theMatrix"<< *(static_cast<Matrix *>(isearchable))<<"matrix<"<<endl;
                stringstreamOfProblem << *(static_cast<Matrix *>(isearchable));
                mutex1->lock();
                ans = this->solver->solve(isearchable);
                this->casheManager->saveSolution(stringstreamOfProblem.str(), ans);
                mutex1->unlock();
            }
            if(ans[ans.length()-1]=='\n') {
                ans.erase(ans.length()-1,1);
            }
            client.write(ans);
        }
        client.close();
    }

    vector<string> splitByDelimeter(string string1, string delimeter) {
        string part;
        vector<string> splitted;
        while (string1.find(delimeter) != string::npos) {
            part = string1.substr(0, string1.find(delimeter));
            splitted.push_back(part);
            string1 = string1.substr(string1.find(delimeter) + 1, string1.length() - string1.find(delimeter));
        }
        return splitted;
    }

    string getRiddOfSpaces(string & string1) {
        string stringToReturn="";
        for( int i=0; i<string1.length();i++) {
            if(string1[i]==' ') {
                continue;
            }
            stringToReturn+=string1[i];
        }
        return stringToReturn;
    }

};


#endif //PROJECTPART2_MYCLIENTHANDLER_H
