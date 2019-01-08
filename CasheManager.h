//
// Created by user on 06/01/19.
//

#ifndef PROJECTPART2_CASHEMANAGER_H
#define PROJECTPART2_CASHEMANAGER_H

template <class Problem,class Solution>
class CasheManager {

    virtual bool solutionExistance(Problem problem) = 0;
    virtual Solution getExistSolution() = 0;
    virtual void saveSolution(Problem problem, Solution solution);

};


#endif //PROJECTPART2_CASHEMANAGER_H
