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

template <class Solution, class T>
class Searcher : public ISearcher<Solution,T> {
private:
    PriorityHeap<T> priorityHeap;
    int evaluateNodes=0;
protected:
    virtual Node<T>* popOpenList() {
        evaluateNodes++;
        Node<T>* n=priorityHeap.top();
        priorityHeap.pop();
        return n;

    }
    virtual void addToOpen(Node<T>* node) {
        this->priorityHeap.push(node);
    }
    virtual bool contains( Node<T>* node) {
        return this->priorityHeap.contains(node);
    }
public:
    Searcher() {
        evaluateNodes=0;
    }

    virtual int getPriorityQueueSize() {
        return this->priorityHeap.size();
    }

    int getNumberOfNodesEvaluated() { //not virtual in porpuse
        return this->evaluateNodes;
    }

    virtual void setExistingNodeValue(Node<T>* nodeToSetValueTo, double cost) {
        priorityHeap.setExistingNodeValue(nodeToSetValueTo,cost);
    }

    virtual Solution search(Isearchable<T>* isearchable) = 0;

};

#endif //PROJECTPART2_SEARCHER_H
