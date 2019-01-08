//
// Created by user on 08/01/19.
//

#ifndef PROJECTPART2_SEARCHER_H
#define PROJECTPART2_SEARCHER_H


#include "ISearcher.h"
#include "Solver.h"
#include <queue>
#include "Node.h"


template <class Solution,class T>
class Searcher : public ISearcher<Solution,T> {
private:
    priority_queue<Node<T>*, vector<Node<T>*>,greater<Node<T>*>> priorityQueue;
    int evaluateNodes;
protected:
    virtual Node<T>* popOpenList() {
        evaluateNodes++;
        priorityQueue.pop();
    }
    virtual void addToOpen(Node<T>* node) {
        priorityQueue.push(node);
    }
public:
    Searcher() {
        evaluateNodes=0;
    }

    virtual int getPriorityQueueSize() {
        return this->priorityQueue.size();
    }

    int getNumberOfNodesEvaluated() {
        return this->evaluateNodes;
    }

    virtual Solution search(Isearchable<T>* isearchable) = 0;

};

#endif //PROJECTPART2_SEARCHER_H
