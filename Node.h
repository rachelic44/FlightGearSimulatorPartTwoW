//
// Created by user on 07/01/19.
//

#ifndef PROJECTPART2_STATE_H
#define PROJECTPART2_STATE_H

#include <iostream>
using namespace std;

template <class T>
class Node {

private:
    T nodeData;
    double cost;
    Node<T>* cameFrom;
public:
    Node<T>() {

    }
    Node(T data) {
        this->nodeData=data;
    }
    Node<T>(T data, Node<T>*nodeFrom){
        this->nodeData=data;
        this->cameFrom=nodeFrom;
    }

    T getNodeData () const {
        return this->nodeData;
    }
    void setCost(double cost) {
        this->cost=cost;
    }
    void setCameFrom(Node<T>* state1) {
        this->cameFrom=state1;
    }
    Node<T>* getCameFrom() {
        return this->cameFrom;
    }

    bool operator==( Node<T> other) const {
        cout<<"was here";
        if(this->nodeData==other.nodeData) {
            return true;
        }
        return false;
    }
    bool operator>(const Node<T>& other) const {
        if( this->getNodeData()>other.getNodeData()) {
            return true;
        }
        return false;
    }

    ostream &operator<<(ostream &stream) {
       stream<<this->nodeData <<this->cost;
    }

    friend ostream &operator<<(ostream &ostream1, Node<T> infinit1) {
        return infinit1 << (ostream1);
    }

};


#endif //PROJECTPART2_STATE_H
