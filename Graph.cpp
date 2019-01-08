//
// Created by user on 08/01/19.
//

#include "Graph.h"

Node<std::string>* Graph::getGoalState() {
    return this->target;
}

vector<Node<string>*> Graph::getAllPossibleStates(Node<std::string>* s) {
    vector<Node<string>*> vecOfNeighbors;
    for(auto pairInMap : this->archMAp) {
        if(pairInMap.first.first->getNodeData()==s->getNodeData()) {
           vecOfNeighbors.push_back(pairInMap.first.second);
        } else if(pairInMap.first.second->getNodeData()==s->getNodeData()) { //taking care of unordered graph. todo
            vecOfNeighbors.push_back(pairInMap.first.first);
        }
    }
    return vecOfNeighbors;
}
Node<std::string>* Graph::getInitialState() {
    return this->start;
}