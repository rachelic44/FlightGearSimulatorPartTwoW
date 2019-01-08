//
// Created by user on 07/01/19.
//

#ifndef PROJECTPART2_REVERSESOLVER_H
#define PROJECTPART2_REVERSESOLVER_H

#include "Solver.h"
#include <iostream>
using namespace std;

class ReverseSolver : public Solver<std::string,std::string> {

private:
    string s1;
public:
    ReverseSolver();
    virtual string solve(string problem ) {
        string solution = problem;
        int lengthOfProblem = problem.length();
        for(int i=0;i<problem.length();i++) {
            solution[lengthOfProblem-i] = problem[i];
        }
        return solution;
    }
};


#endif //PROJECTPART2_REVERSESOLVER_H
