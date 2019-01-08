//
// Created by user on 09/01/19.
//

#ifndef PROJECTPART2_PRIORITYHEAP_H
#define PROJECTPART2_PRIORITYHEAP_H

#include <queue>
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class PriorityHeap{

private:
    priority_queue<Node<T>*, vector<Node<T>*>,greater<Node<T>*>> priorityQueue;
public:
    PriorityHeap() {
       priority_queue<Node<T>*, vector<Node<T>*>,greater<Node<T>*>> priorityQueue1;
       this->priorityQueue=priorityQueue1;
    }
    Node<T>* pop() {
        this->priorityQueue.pop();
    }
    void push(Node<T>* node) {
       // this->priorityQueue.push(node);
    }
    int size() {
        return this->priorityQueue.size();
    }
};
#endif //PROJECTPART2_PRIORITYHEAP_H
