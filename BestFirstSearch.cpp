//
// Created by user on 08/01/19.
//

#include "BestFirstSearch.h"
#include <unordered_set>


list<Node<string>*> backTrace(Node<string>* isearchable);


/* it is getting an isearchable, this case it is bestForSearch so it is getting a memushkel graph */
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

}