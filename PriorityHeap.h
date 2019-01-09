//
// Created by user on 09/01/19.
//
/*
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
    priority_queue<Node<T>*, vector<Node<T>*>> priorityQueue2;
public:
    PriorityHeap() {
       priority_queue<Node<T>*, vector<Node<T>*>,greater<Node<T>*>> priorityQueue1;
       this->priorityQueue=priorityQueue1;
    }
    void pop() {
        this->priorityQueue.pop();
    }
    void push(Node<T>* node) {
        this->priorityQueue.push(node);
    }
    int size() {
        return this->priorityQueue.size();
    }
    bool contains() {

    }
};

*/

#ifndef PROJECTPART2_PRIORITYHEAP_H
#define PROJECTPART2_PRIORITYHEAP_H
#include <queue>
#include <iostream>
#include "Node.h"
using namespace std;


template<class InputIterator, class T>
InputIterator finder (InputIterator first, InputIterator last, const T& val)
{
    while (first!=last) {
        if (*first==val) return first;
        ++first;
    }
    return last;
}


template <class T>
class PriorityHeap : public priority_queue<Node<T>*, vector<Node<T>*>,greater<Node<T>*>> {
public:
    bool remove( Node<T>*  value) const {
        auto it = finder(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }
        else {
            return false;
        }
    }
    bool exist( Node<T>*  value) const {
        auto it = finder(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            return true;
        }
        return false;
    }

};


#endif //PROJECTPART2_PRIORITYHEAP_H
