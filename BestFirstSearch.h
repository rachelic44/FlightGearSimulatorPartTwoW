//
// Created by user on 08/01/19.
//

#ifndef PROJECTPART2_BESTFIRSTSEARCH_H
#define PROJECTPART2_BESTFIRSTSEARCH_H


#include "ISearcher.h"
#include "Graph.h"
#include <vector>
#include "Searcher.h"
#include <unordered_set>

template <class T>
class BestFirstSearch : public Searcher<vector<Node<T> *>,T> {


    vector<Node<T>*> backTrace(Node<T>* goalState) {
        Node<T>* current=goalState;
        vector<Node<T>*> backTraceToReturn;
        backTraceToReturn.push_back(current);
        while(current->getCameFrom()!= nullptr) {
            backTraceToReturn.push_back(current->getCameFrom());
            current=current->getCameFrom();
        }
        int i;
        vector<Node<T>*> upSided;
        for(i=backTraceToReturn.size()-1;i>=0;i--) {
            upSided.push_back(backTraceToReturn[i]);
        }
        return upSided;

    }
    
    virtual vector<Node<T>*> search(Isearchable<T>* isearchable) {

        this->addToOpen(isearchable->getInitialState());
        unordered_set<Node<T>*> closed;
        while(this->getPriorityQueueSize()>0) {
            Node<T>* n = this->popOpenList();
            closed.insert(n);
            if(n==isearchable->getGoalState()) {
                return backTrace(n);
            }
            vector<Node<T>*> vecOfNeighbors = isearchable->getAllPossibleStates(n); //each searchable (matrix, graph..) is doing it differently
            for(Node<T>* neighbor: vecOfNeighbors) {
                if( (closed.count(neighbor)==0) && (!this->contains(neighbor))) {
                    neighbor->setCameFrom(n);
                    neighbor->setCost(neighbor->getStepCost()+n->getCost());
                    this->addToOpen(neighbor);
                } else if(closed.count(neighbor)==0) {
                    if (neighbor->getCameFrom()->getCost() > n->getCost()) {
                        neighbor->setCameFrom(n);
                        neighbor->setCost(n->getCost() + neighbor->getStepCost());
                    }
                }
            }
        }
        vector<Node<T>*> l;
        return l;
    }
};



#endif //PROJECTPART2_BESTFIRSTSEARCH_H
