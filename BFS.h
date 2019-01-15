


//
// Created by shanyyael on 1/10/19.
//

#ifndef PROJECTPART2_BFS_H
#define PROJECTPART2_BFS_H
///hellooooo

#include "ISearcher.h"
#include "Graph.h"
#include <vector>
#include "Searcher.h"
#include <unordered_set>
#include<iostream>
#include <list>
#include <queue>
#include <set>

using namespace std;

template <class T>
class BFS : public ISearcher<string,T> {

private:
    int numOfNodes;
public:
    BFS() {
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
                pathToReturn="DOWN,"+pathToReturn;
            } else  if(current->getCameFrom()->getNodeData().first > current->getNodeData().first) {
                pathToReturn="UP,"+pathToReturn;
            } else  if(current->getCameFrom()->getNodeData().second < current->getNodeData().second) {
                pathToReturn="RIGHT,"+pathToReturn;
            } else {
                pathToReturn="LEFT,"+pathToReturn;
            }
            x+=current->getStepCost();
            current=current->getCameFrom();
        }
        pathToReturn.erase(pathToReturn.length()-1,1);
        return pathToReturn;
    }


    bool inVisited(vector<Node<T> *> visited,Node<T> *current ){
        for (auto state:visited) {
            if (current==state) { ////todo:pointer?
                return true;
            }
        }
        return false;
    }

    string search(Isearchable<T> *isearchable) {
        queue<Node<T> *> verQueue;
        vector<Node<T> *> visitedNodes;
        Node<T> *currentNode;
        vector<Node<T> *> nextPossibleStates;

        verQueue.push(isearchable->getInitialState()); // todo: add func like addToOpen????
        visitedNodes.push_back(isearchable->getInitialState());
        while (!verQueue.empty()) {
            // Get next vertex
            currentNode = verQueue.front();
            this->numOfNodes++;
//            verQueue.pop();
//            visitedNodes.insert(currentNode);

            if (isearchable->getGoalState() == currentNode) {
                return backTracer(currentNode);
            }
            nextPossibleStates = isearchable->getAllPossibleStates(currentNode);
            verQueue.pop();


            for (Node<T> *neighbor: nextPossibleStates) {
                if (!inVisited(visitedNodes,neighbor)) {
                    neighbor->setCameFrom(currentNode);
                    visitedNodes.push_back(neighbor);
                    verQueue.push(neighbor);
                }
            }
        }
        return "";
    }

    virtual int getNumberOfNodesEvaluated() {
        return this->numOfNodes;
    }
};

#endif //PROJECTPART2_BFS_H
