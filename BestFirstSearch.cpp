//
// Created by user on 08/01/19.
//

#include "BestFirstSearch.h"
#include <unordered_set>

/*
list<Node<T>*> backTrace(Node<T>* isearchable);



list<Node<T>*> BestFirstSearch::search(Isearchable<T>* isearchable) {


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
                addToOpen(neighbor);
            } else if(neighbor->getCost() > n->getCost()) {
                if(!this->contains(neighbor)) {
                    addToOpen(neighbor);
                } else {
                    neighbor->setCost(n->getCost()+neighbor->getStepCost());
                }

            }
        }
    }
    list<Node<T>*> l;
    return l;

}

list<Node<T>*> backTrace(Node<T>* goalState) {
    Node<T>* current=goalState;
    list<Node<T>*> backTraceToReturn;
    backTraceToReturn.push_front(current);
    while(current->getCameFrom()!= nullptr) {
        backTraceToReturn.push_front(current->getCameFrom());
        current=current->getCameFrom();
    }
    return backTraceToReturn;

}
*/
/*/
// Created by user on 08/01/19.
//

#include "BestFirstSearch.h"
#include <unordered_set>


list<Node<string>*> backTrace(Node<string>* isearchable);


list<Node<string>*> BestFirstSearch::search(Isearchable<string>* isearchable) {


    this->addToOpen(isearchable->getInitialState());
    unordered_set<Node<string>*> closed;
    while(this->getPriorityQueueSize()>0) {
        Node<string>* n = this->popOpenList();
        closed.insert(n);
        if(n==isearchable->getGoalState()) {
            return backTrace(n);
        }
        vector<Node<string>*> vecOfNeighbors = isearchable->getAllPossibleStates(n); //each searchable (matrix, graph..) is doing it differently
        for(Node<string>* neighbor: vecOfNeighbors) {
            if( (closed.count(neighbor)==0) && (!this->contains(neighbor))) {
                neighbor->setCameFrom(n);
                neighbor->setCost(neighbor->getCost()+n->getCost());
                addToOpen(neighbor);
            } else {
                if(!this->contains(neighbor)) {
                    addToOpen(neighbor);
                }
            }
        }
    }

}

list<Node<string>*> backTrace(Node<string>* goalState) {
    Node<string>* current=goalState;
    list<Node<string>*> backTraceToReturn;
    backTraceToReturn.push_front(current);
    while(current->getCameFrom()!= nullptr) {
        backTraceToReturn.push_front(current->getCameFrom());
        current=current->getCameFrom();
    }
    return backTraceToReturn;

}*/