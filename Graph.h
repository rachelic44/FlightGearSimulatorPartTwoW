//
// Created by user on 08/01/19.
//

#ifndef PROJECTPART2_GRAPH_H
#define PROJECTPART2_GRAPH_H

#include "ISearchable.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * This class represents unordedred Graph
 */
 template <class T>
class Graph : public Isearchable<T> {
private:
    vector<Node<T>*> vertexVector;
    Node<T>* target;
    Node<T>* start;
    //multimap<Node<T>,Node<T>> archMAp;
    map<pair<Node<T>*,Node<T>*>,double > archMAp;
public:
    Graph(vector<Node<T>*> vertexVector,   map<pair<Node<T>*,Node<T>*>,double > archMAp) {
        this->vertexVector=vertexVector;
        this->archMAp=archMAp;
    }
    Node<T>* getGoalState() {
        return this->target;
    }

    vector<Node<T>*> getAllPossibleStates(Node<T>* s) {
        vector<Node<T>*> vecOfNeighbors;
        for(auto pairInMap : this->archMAp) {
            if(pairInMap.first.first->getNodeData()==s->getNodeData()) {
                vecOfNeighbors.push_back(pairInMap.first.second);
            } else if(pairInMap.first.second->getNodeData()==s->getNodeData()) { //taking care of unordered graph. todo
                vecOfNeighbors.push_back(pairInMap.first.first);
            }
        }
        return vecOfNeighbors;
    }
    Node<T>* getInitialState() {
        return this->start;
    }
};

#endif //PROJECTPART2_GRAPH_H
