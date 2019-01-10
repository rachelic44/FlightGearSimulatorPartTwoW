//
// Created by user on 08/01/19.
//

#ifndef PROJECTPART2_SEARCHSOLVER_H
#define PROJECTPART2_SEARCHSOLVER_H

#include "Solver.h"
#include "ISearchable.h"
#include "ISearcher.h"

template <class Solution,class T>
class SearchSolver : public Solver<Isearchable<T>*,Solution> {
private:
    ISearcher<Solution,T>* iSearcher;
public:
    SearchSolver( ISearcher<Solution,T>* iSearcherer) {
        this->iSearcher=iSearcherer;
    }
    virtual Solution solve(Isearchable<T>* searchableProblem ) {
        return (iSearcher->search(searchableProblem));
    }
};


#endif //PROJECTPART2_SEARCHSOLVER_H
