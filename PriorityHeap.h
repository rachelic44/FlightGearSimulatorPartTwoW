
/*
#ifndef PROJECTPART2_PRIORITYHEAP_H
#define PROJECTPART2_PRIORITYHEAP_H
#include <queue>
#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class PriorityHeap {
private:
    vector<Node<T>*> nodesVector;
    Node<T>* current;
public:
    void push(Node<T>* node) {
        this->nodesVector.push_back(node);
    }
    Node<T>* top() {
        if(nodesVector.size()==0) {
            throw logic_error("the priority queue is empty");
        }
        Node<T>* current= this->nodesVector[0];
        for(Node<T>* node : this->nodesVector ) {
            if(node->getCost() < current->getCost()) {
                current=node;
            }
        }
        this->current=current;
        return current;
    }

    void pop() {
        if(nodesVector.size()==0) {
            throw logic_error("the priority queue is empty");
        }
        Node<T>* current= this->nodesVector[0];
        int i=0;
        int place = 0;
        for(Node<T>* node : this->nodesVector ) {
            if(node->getCost() < current->getCost()) {
                current=node;
                place=i;
            }
            i++;
        }
        this->current=current;
        this->nodesVector.erase(nodesVector.begin()+place);
    }
    bool contains(Node<T>* other) {
        for(Node<T>* node : this->nodesVector ) {
           if(node==other) {
               return true;
           }
        }
        return false;
    }
    int size() {
        return this->nodesVector.size();
    }
};*/


#ifndef PROJECTPART2_PRIORITYHEAP_H
#define PROJECTPART2_PRIORITYHEAP_H
#include <queue>
#include <iostream>
#include "Node.h"
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
struct greaterThan : binary_function <T, T, bool> {
    bool operator() (const T& x, const T& y) const {
        return *x>*y;
        //return x->getNodeData()<y->getNodeData();
    }
};


template <typename T>
class PriorityHeap : public priority_queue<Node<T>*, vector<Node<T>*>,greaterThan<Node<T>*>> {
public:
    bool remove( Node<T>*  value)  {
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
    bool contains( Node<T>*  value) const {
        auto it = finder(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            return true;
        }
        return false;
    }

};



#endif //PROJECTPART2_PRIORITYHEAP_H
