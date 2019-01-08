//
// Created by user on 06/01/19.
//

#ifndef PROJECTPART2_SOLVER_H
#define PROJECTPART2_SOLVER_H

template <class Problem,class Solution>
class Solver {
public:
    virtual Solution solve(Problem problem ) = 0;
};

#endif //PROJECTPART2_SOLVER_H
