//
// Created by user on 08/01/19.
//

#ifndef PROJECTPART2_ASTAR_H
#define PROJECTPART2_ASTAR_H


#include "ISearcher.h"
#include "Graph.h"
#include <vector>
#include "Searcher.h"
#include <unordered_set>
#include <math.h>

template <class T>
class Astar : public Searcher<string,T> {

    double huristic(Node<pair<int, int>>* node1, Node<pair<int, int>>* node2) {
        int x1 = node1->getNodeData().first;
        int y1 = node1->getNodeData().second;
        int x2 = node2->getNodeData().first;
        int y2 = node2->getNodeData().second;
        double ans= sqrt((abs(x1 - x2)*abs(x1 - x2)) + (abs(y1 - y2)*abs(y1 - y2)));
        return ans;
    }

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

    //use only for matrixes- wont work on a graph
    string backTracer(Node<T>* goalState)  {
        Node<T>* current=goalState;
        string pathToReturn="";
        while(current->getCameFrom()!= NULL) {

            if(current->getCameFrom()->getNodeData().first < current->getNodeData().first) {
                pathToReturn="DOWN,"+pathToReturn;
            } else  if(current->getCameFrom()->getNodeData().first > current->getNodeData().first) {
                pathToReturn="UP,"+pathToReturn;
            } else  if(current->getCameFrom()->getNodeData().second < current->getNodeData().second) {
                pathToReturn="RIGHT,"+pathToReturn;
            } else {
                pathToReturn="LEFT,"+pathToReturn;
            }
            current=current->getCameFrom();
        }
        cout<<"numberofEvaluated "<<this->getNumberOfNodesEvaluated()<<endl;
        pathToReturn.erase(pathToReturn.length()-1,1);
        return pathToReturn;
    }

    string search(Isearchable<T>* isearchable) {

        Node<T>* startingFrom=isearchable->getInitialState();
        startingFrom->setCost(startingFrom->getCost()+huristic(startingFrom,isearchable->getGoalState()));
        this->addToOpen(startingFrom);
        unordered_set<Node<T>*> closed;
        while(this->getPriorityQueueSize()>0) {
            Node<T>* n = this->popOpenList();
            n->setCost(n->getCost()-huristic(n,isearchable->getGoalState()));
            closed.insert(n);
            if(n==isearchable->getGoalState()) {
                return backTracer(n);
            }
            vector<Node<T>*> vecOfNeighbors = isearchable->getAllPossibleStates(n); //each searchable (matrix, graph..) is doing it differently
            for(Node<T>* neighbor: vecOfNeighbors) {
                if( (closed.count(neighbor)==0) && (!this->contains(neighbor))) {
                    neighbor->setCameFrom(n);
                    neighbor->setCost(neighbor->getStepCost()+n->getCost()+huristic(neighbor,isearchable->getGoalState()));
                    this->addToOpen(neighbor);
                } else if(closed.count(neighbor)==0) {
                    if (neighbor->getCameFrom()->getCost() > n->getCost()) {
                        neighbor->setCameFrom(n);
                        neighbor->setCost(n->getCost() + neighbor->getStepCost()+huristic(neighbor,isearchable->getGoalState()));
                    }
                }
            }
        }
        //vector<Node<T>*> l;
        string l="";
        return l;
    }
};



#endif //PROJECTPART2_BESTFIRSTSEARCH_H
