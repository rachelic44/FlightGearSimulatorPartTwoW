//
// Created by user on 07/01/19.
//

#ifndef PROJECTPART2_ISEARCHER_H
#define PROJECTPART2_ISEARCHER_H

#include "ISearchable.h"

template <class Solution,class T>
class ISearcher {
public:
    virtual Solution search(Isearchable<T>* isearchable) = 0;
    virtual int getNumberOfNodesEvaluated()=0;

};
#endif //PROJECTPART2_SEARCHER_H
