//
// Created by user on 06/01/19.
//

#ifndef PROJECTPART2_CASHEMANAGER_H
#define PROJECTPART2_CASHEMANAGER_H

template <class Problem,class Solution>
class CasheManager {
public:
    virtual bool solutionExistance(Problem problem) = 0;
    virtual Solution getExistSolution(Problem problem) = 0;
    virtual void saveSolution(Problem problem, Solution solution)=0;

};


#endif //PROJECTPART2_CASHEMANAGER_H
