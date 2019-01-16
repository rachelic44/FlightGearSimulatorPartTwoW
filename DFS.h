

//
// Created by shanyyael on 1/10/19.
//

#ifndef PROJECTPART2_DFS_H
#define PROJECTPART2_DFS_H


#include "ISearcher.h"
#include "Graph.h"
#include <vector>
#include "Searcher.h"
#include <unordered_set>
#include<iostream>
#include <list>
#include <queue>
#include <set>
#include <stack>

using namespace std;

template <class T>
class DFS : public ISearcher<string,T> {

private:
    int numOfNodes;
public:
    DFS() {
        this->numOfNodes=0;
    }

    vector<Node<T> *> backTrace(Node<T> *goalState) {
        Node<T> *current = goalState;
        vector<Node<T> *> backTraceToReturn;
        backTraceToReturn.push_back(current);
        while (current->getCameFrom() != nullptr) {
            backTraceToReturn.push_back(current->getCameFrom());
            current = current->getCameFrom();
        }
        int i;
        vector<Node<T> *> upSided;
        for (i = backTraceToReturn.size() - 1; i >= 0; i--) {
            upSided.push_back(backTraceToReturn[i]);
        }

        return upSided;

    }

//use only for matrixes- wont work on a graph
    string backTracer(Node<T>* goalState)  {
        Node<T>* current=goalState;
        string pathToReturn="";
        int x=0;
        while(current->getCameFrom()!= nullptr) {
            if(current->getCameFrom()->getNodeData().first < current->getNodeData().first) {
                pathToReturn="Down,"+pathToReturn;
            } else  if(current->getCameFrom()->getNodeData().first > current->getNodeData().first) {
                pathToReturn="Up,"+pathToReturn;
            } else  if(current->getCameFrom()->getNodeData().second < current->getNodeData().second) {
                pathToReturn="Right,"+pathToReturn;
            } else {
                pathToReturn="Left,"+pathToReturn;
            }
            x+=current->getStepCost();
            current=current->getCameFrom();
        }
        pathToReturn.erase(pathToReturn.length()-1,1);
        return pathToReturn;
    }

    bool inVisited(vector<Node<T> *> visited,Node<T> *current ){
        for (auto state:visited) {
            if (current==state) {
                return true;
            }
        }
        return false;
    }




    string search(Isearchable<T> *isearchable) {
        int numNodeEvaluated = 0;
        vector<Node<T> *> visitedNodes;
        stack<Node<T> *> stackNode;
        Node<T> *currentNode;
        vector<Node<T> *> nextPossibleStates;
        stackNode.push(isearchable->getInitialState());
        visitedNodes.push_back(isearchable->getInitialState());

        while (!stackNode.empty()) {
            numNodeEvaluated++;
            currentNode = stackNode.top();

            if (isearchable->getGoalState() == currentNode) {
                return backTracer(currentNode);
            }
            nextPossibleStates = isearchable->getAllPossibleStates(currentNode);
            stackNode.pop();
            this->numOfNodes++;

            for (Node<T> *neighbor: nextPossibleStates) {

                if (!inVisited(visitedNodes,neighbor)) {
                    neighbor->setCameFrom(currentNode);
                    visitedNodes.push_back(neighbor);
                    stackNode.push(neighbor);
                }
            }
        }

        return "";
    }

    virtual int getNumberOfNodesEvaluated() {
        return this->numOfNodes;
    }


};




#endif //PROJECTPART2_DFS_H

