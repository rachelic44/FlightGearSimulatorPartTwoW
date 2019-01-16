//
// Created by user on 13/01/19.
//

#ifndef PROJECTPART2_FILECASHEMANAGER_H
#define PROJECTPART2_FILECASHEMANAGER_H

#include "CasheManager.h"
#include <iostream>
using namespace std;

#include "CashMap.h"
#include <sstream>


class FileCasheManager : public CasheManager<string,string> {
public:
    virtual bool solutionExistance(string problem) {
        unordered_map<string,string>* cashMapa = CashMap::instance()->getMap();
        stringstream stringstream1;
        stringstream1<<problem;
        if(cashMapa->count(problem)==0) {
            return false;
        }
        return true;

    }
    virtual string getExistSolution(string problem) {
        unordered_map<string,string>* cashMap = CashMap::instance()->getMap();
        stringstream stringstream1;
        stringstream1<<problem;
        if (!cashMap->count(problem)) {
            __throw_logic_error("the solution does not exist");
        }
        return cashMap->at(problem);
    }
    virtual void saveSolution(string problem, string solution) {
        cout<<problem<<endl;
        unordered_map<string,string>* cashMap = CashMap::instance()->getMap();
        cashMap->insert({problem,solution});

    }
};


#endif //PROJECTPART2_FILECASHEMANAGER_H
