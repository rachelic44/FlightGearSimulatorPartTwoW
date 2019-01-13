//
// Created by user on 09/01/19.
//

#ifndef PROJECTPART2_MATRIX_H
#define PROJECTPART2_MATRIX_H


#include "ISearchable.h"

class Matrix : public Isearchable<pair<int,int>> {
private:
    vector<Node<pair<int,int>>*> nodesVector;
    Node<pair<int,int>>* target;
    Node<pair<int,int>>* start;
    int downLimit;
    int rightLimit;
public:
    Matrix(vector<Node<pair<int,int>>*> nodesVector, Node<pair<int,int>>* startT, Node<pair<int,int>>* targetT) {
        this->nodesVector=nodesVector;
        this->start=startT;
        this->target=targetT;
    }

    Node<pair<int,int>>* getGoalState() {
        return this->target;
    }

    Node<pair<int,int>>* getInitialState() {
        return this->start;
    }

    vector<Node<pair<int,int>>*> getAllPossibleStates(Node<pair<int,int>>* s) {
        vector<Node<pair<int,int>>*> vecOfNeighborsToRet;
        for(Node<pair<int,int>>* neighbor : this->nodesVector) {
           if(neighbor->getNodeData().first== s->getNodeData().first &&
                   neighbor->getNodeData().second +1 == s->getNodeData().second) {
               vecOfNeighborsToRet.push_back(neighbor);
           } else if(neighbor->getNodeData().first+1 == s->getNodeData().first &&
                   neighbor->getNodeData().second == s->getNodeData().second ) {
               vecOfNeighborsToRet.push_back(neighbor);
           } else if(neighbor->getNodeData().first== s->getNodeData().first &&
                     neighbor->getNodeData().second -1 == s->getNodeData().second) {
               vecOfNeighborsToRet.push_back(neighbor);
           } else if(neighbor->getNodeData().first -1 == s->getNodeData().first &&
                     neighbor->getNodeData().second == s->getNodeData().second ) {
               vecOfNeighborsToRet.push_back(neighbor);
           }
        }
        return vecOfNeighborsToRet;
    }


   /* void operator>>(istream &s) {
        string string1;
        s >> string1;
        Matrix a(string1);
        *this = a;
    }

    friend void operator>>(istream &istream1, Matrix &otherMatrix) {
        otherMatrix >> istream1;
    }*/

    ostream &operator<<(ostream &stream) {
        int i=0;
        for(Node<pair<int,int>>* node:this->nodesVector) {
            if(node->getNodeData().first!=i) {
                stream << "\n" << node->getStepCost();
                i++;
            } else {
                if(node->getNodeData().second==0 && i==0) {
                    stream << node->getStepCost() ;
                } else {
                    stream <<" ,"<< node->getStepCost() ;
                }

            }
        }
        return stream;
    }

    friend ostream &operator<<(ostream &ostream1, Matrix infinit1) {
        return infinit1 << (ostream1);
    }


};


#endif //PROJECTPART2_MATRIX_H
