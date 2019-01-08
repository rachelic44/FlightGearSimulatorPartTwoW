//
// Created by user on 08/01/19.
//

#ifndef PROJECTPART2_SEARCHER_H
#define PROJECTPART2_SEARCHER_H


#include "ISearcher.h"
#include "Solver.h"
#include <queue>
#include "Node.h"
#include "PriorityHeap.h"

template <class Solution,class T>
class Searcher : public ISearcher<Solution,T> {
private:
    PriorityHeap<Node<T>> priorityHeap;
    int evaluateNodes;
protected:
    virtual Node<T>* popOpenList() {
        evaluateNodes++;
        priorityHeap.pop();
    }
    virtual void addToOpen(Node<T>* node) {
        priorityHeap.push(node);
    }
public:
    Searcher() {
        evaluateNodes=0;
    }

    virtual int getPriorityQueueSize() {
        return this->priorityHeap.size();
    }

    int getNumberOfNodesEvaluated() {
        return this->evaluateNodes;
    }

    virtual Solution search(Isearchable<T>* isearchable) = 0;

};

#endif //PROJECTPART2_SEARCHER_H
