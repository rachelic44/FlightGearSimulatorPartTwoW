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


    virtual void handleClient(TCP_client client) {

        string ans;
        string bufferReadFromCLient = "";
        client.settimeout(0, 0);
        cout << "hi" << endl;
        bool toContinue = true;
        while (toContinue) {
            cout << bufferReadFromCLient << endl;
            bufferReadFromCLient += client.read(1024);
            if (bufferReadFromCLient.find("end") != string::npos) {
                bufferReadFromCLient = bufferReadFromCLient.substr(0, bufferReadFromCLient.find("end"));
                toContinue = false; //change. keep things for the next read
                if (bufferReadFromCLient == "") {
                    cout << "g1";
                    continue;
                }
                cout << "Was at non" << endl;
            } else {
                continue;
            }

            if (this->casheManager->solutionExistance(bufferReadFromCLient)) {
                cout << "g2";
                ans = casheManager->getExistSolution(bufferReadFromCLient);
            } else {
                vector<string> linesVec = splitByDelimeter(bufferReadFromCLient, "\n");
                cout << "2" << endl;
                for (auto s:linesVec) {
                    cout << s << endl;
                }
                cout << "finish" << endl;
                string target = linesVec.back();
                linesVec.pop_back();
                string start = linesVec.back();
                linesVec.pop_back();
                cout << "3!" << endl;
                Isearchable<T> *isearchable = new Matrix(linesVec, start, target);
                cout << "4" << endl;
                //  Matrix* isearchable=new Matrix(linesVec, start, target);
                //cout<<isearchable<<endl;
                cout << "5" << endl;

                /* stringstream stringstream1;
                 stringstream1<<bufferReadFromCLient; //till the end. here specific no more
                 isearchable>>stringstream1;
                 string p = stringstream1.str();*/
                stringstream stringstreamOfProblem;
                stringstreamOfProblem << isearchable;
                cout << "6" << endl;
                cout << *(static_cast<Matrix *>(isearchable)) << "the matrix";
                ans = stringstreamOfProblem.str();
                cout << endl << ans << endl;
                ans = this->solver->solve(isearchable);
                cout << endl << "7" << endl;
                this->casheManager->saveSolution(stringstreamOfProblem.str(), ans);

            }
            cout << "here2" << endl;

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

};


#endif //PROJECTPART2_MYCLIENTHANDLER_H
