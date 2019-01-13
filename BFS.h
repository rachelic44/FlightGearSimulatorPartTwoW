

//
// Created by shanyyael on 1/10/19.
//

#ifndef PROJECTPART2_BFS_H
#define PROJECTPART2_BFS_H


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
class BFS : public Searcher<vector<Node<T> *>,T> {

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


    bool inVisited(vector<Node<T> *> visited,Node<T> *current ){
        for (auto state:visited) {
            if (current==state) { ////todo:pointer?
                return true;
            }
        }
        return false;
    }

    virtual vector<Node<T> *> search(Isearchable<T> *isearchable) {
        queue<Node<T> *> verQueue;
        vector<Node<T> *> visitedNodes;
        Node<T> *currentNode;
        vector<Node<T> *> nextPossibleStates;

        verQueue.push(isearchable->getInitialState()); // todo: add func like addToOpen????
        visitedNodes.push_back(isearchable->getInitialState());
        while (!verQueue.empty()) {
            // Get next vertex
            currentNode = verQueue.front();
//            verQueue.pop();
//            visitedNodes.insert(currentNode);

            if (isearchable->getGoalState() == currentNode) {
                cout << "Bfs goal" << endl;
                return backTrace(currentNode);
            }
            nextPossibleStates = isearchable->getAllPossibleStates(currentNode);
            verQueue.pop();

            for (Node<T> *neighbor: nextPossibleStates) {
                if (!inVisited(visitedNodes,neighbor)) {
                    neighbor->setCameFrom(currentNode);
                    // neighbor->setCost(neighbor->getStepCost() + currentNode->getCost());
                    visitedNodes.push_back(neighbor);
                    verQueue.push(neighbor);
                }
            }
        }

        return visitedNodes;
    }




//
//            } else {
//                vector<Node<T> *> nextPossibleStates = isearchable->getAllPossibleStates(currentNode);
//
//                for (Node<T> *neighbor: nextPossibleStates) {
//                    if (visitedNodes.count(neighbor) == 0) {
//                        neighbor->setCameFrom(currentNode);
//                        neighbor->setCost(neighbor->getStepCost()+currentNode->getCost());
//                        verQueue.push(neighbor);
//                    } else if(visitedNodes.count(neighbor)==0) {
//                        if (neighbor->getCameFrom()->getCost() > currentNode->getCost()) {
//                            neighbor->setCameFrom(currentNode);
//                            neighbor->setCost(currentNode->getCost() + neighbor->getStepCost());
//                        }
//                    }
//
//                }
//                return visitedNodes;
//
//            }
//        }
//    }

};

#endif //PROJECTPART2_BFS_H

