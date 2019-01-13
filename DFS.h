

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
class DFS : public Searcher<vector<Node<T> *>,T> {

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


    virtual vector<Node<T> *> search(Isearchable<T> *isearchable) {
        // queue<Node<T> *> verQueue;
        set<Node<T> *> visitedNodes;//todo: set??
        stack<Node<T> *> stackNode;
        vector<Node<T> *> vec;
        stackNode.push(isearchable->getInitialState());
        visitedNodes.insert(isearchable->getInitialState());

        while (!stackNode.empty()) {
            Node<T> *currentNode = stackNode.top();
            stackNode.pop();
            if (isearchable->getGoalState() == currentNode) {
                cout << "dfs goal" << endl;
                return backTrace(currentNode);
            }
            vector<Node<T> *> nextPossibleStates = isearchable->getAllPossibleStates(currentNode);

            for (Node<T> *neighbor: nextPossibleStates) {

                if (visitedNodes.count(neighbor) == 0) {
                    neighbor->setCameFrom(currentNode);
                    stackNode.push(neighbor);
                    visitedNodes.insert(neighbor);
                }
            }
        }

        return vec;
    }


};




#endif //PROJECTPART2_DFS_H
