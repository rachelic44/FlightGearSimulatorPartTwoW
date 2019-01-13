

//
// Created by shanyyael on 1/10/19.
//

/*
#ifndef PROJECTPART2_ASTAR_H
#define PROJECTPART2_ASTAR_H


#include "ISearcher.h"
#include "Graph.h"
#include <vector>
#include "Searcher.h"
#include <unordered_set>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

template<class T>
class Astar : public Searcher<vector<Node<T> *>, T> {


    double distance(Node<pair<int, int>> *node1, Node<pair<int, int>> *node2) {
        int x1 = node1->getNodeData().first;
        int y1 = node1->getNodeData().second;
        int x2 = node2->getNodeData().first;
        int y2 = node2->getNodeData().second;

        return abs(x1 - x2) + abs(y1 - y2);
    }


    double heuristic(Node<pair<int, int>> *node1, Node<pair<int, int>> *node2, double cost) {

        return (distance(node1, node2) + cost);
    }


    Node<T> *minimallNode(map<Node<T> *, double> heuristicMap) {


        double currentMax = 0;
        Node<T> * maxNode;

        for(auto it = heuristicMap.cbegin(); it != heuristicMap.cend(); ++it ) //todo: rubbish!!fix immidiatly!!
            //checked = it->second;
            if (it ->second > currentMax)
            {
              // minimal = it->first; todo
            }

        return maxNode;



    }


    virtual vector<Node<T> *> search(Isearchable<T> *isearchable) {

        Node<T> *heuristicNode;
        map<Node<T> *, double> heuristicMap;
        this->addToOpen(isearchable->getInitialState());// todo: took from BESTFIRSTSEARCH
        unordered_set<Node<T> *> visitedNodes;
        while (this->getPriorityQueueSize() > 0) {
            Node<T> *n = this->popOpenList();
            visitedNodes.insert(n);
            if (n == isearchable->getGoalState()) {
                return backTrace(n);
            }
            vector<Node<T> *> vecOfNeighbors = isearchable->getAllPossibleStates(n);
            for (Node<T> *neighbor: vecOfNeighbors) {
                if ((visitedNodes.count(neighbor) == 0) && (!this->contains(neighbor))) {
                    heuristicMap.insert(neighbor,
                                        heuristic(n, neighbor, neighbor->getCost())); //todo: getcost?or stepcost?


                }
            }
            heuristicNode = maximalNode(heuristicMap);
            heuristicNode->getCameFrom(n);
            //neighbor->setCost(neighbor->getStepCost()+n->getCost());
            /*
                neighbor->setCameFrom(n);
                neighbor->setCost(neighbor->getStepCost()+n->getCost());
                this->addToOpen(neighbor);
            } else if(visitedNodes.count(neighbor)==0) {
                if (neighbor->getCameFrom()->getCost() > n->getCost()) {
                    neighbor->setCameFrom(n);
                    neighbor->setCost(n->getCost() + neighbor->getStepCost());
                }
            }
        }
             */

           /* vector<Node<T> *> l;
            return l;
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



    };


#endif //PROJECTPART2_ASTAR_H

*/