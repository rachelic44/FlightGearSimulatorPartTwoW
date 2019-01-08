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
class Graph : public Isearchable<string> {
private:
    vector<Node<std::string>*> vertexVector;
    Node<std::string>* target;
    Node<std::string>* start;
    //multimap<Node<string>,Node<string>> archMAp;
    map<pair<Node<string>*,Node<string>*>,double > archMAp;
public:
    Graph(  vector<Node<string>*> vertexVector,   map<pair<Node<string>*,Node<string>*>,double > archMAp) {
        this->vertexVector=vertexVector;
        this->archMAp=archMAp;
    }
    virtual Node<std::string>* getInitialState();
    virtual Node<std::string>* getGoalState();
    virtual std::vector<Node<std::string>*> getAllPossibleStates(Node<std::string>* s);
};

#endif //PROJECTPART2_GRAPH_H
