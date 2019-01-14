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
        cout<<"p1"<<endl;
        unordered_map<string,string>* cashMap = CashMap::instance()->getMap();
        cout<<"p2"<<endl;
        stringstream stringstream1;
        stringstream1<<problem;
        cout<<"p3"<<endl;
        if(cashMap== nullptr) {
            cout<<"prob"<<endl;
        }
        if(cashMap->count(problem)==0) {
            cout<<"p4"<<endl;
            return false;
        }
        cout<<"p5"<<endl;
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
        unordered_map<string,string>* cashMap = CashMap::instance()->getMap();
        stringstream stringstream1;
        stringstream1<<problem;
        cashMap->insert({problem,solution});

    }
};


#endif //PROJECTPART2_FILECASHEMANAGER_H
