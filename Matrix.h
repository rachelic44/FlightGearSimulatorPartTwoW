//
// Created by user on 09/01/19.
//

#ifndef PROJECTPART2_MATRIX_H
#define PROJECTPART2_MATRIX_H
#define  WALL -1

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

    Matrix(vector<string>& linesVec, string& start, string& target) {
        int i=0, j=0;int index;
        for(string string1: linesVec) {
            while(string1.find(",")!= string::npos) {
               Node<pair<int,int>>* node=new Node<pair<int,int>>({i,j});
               node->setStepCost(stoi(string1.substr(0,string1.find(","))));
               this->nodesVector.push_back(node);
               index=string1.find((","));
               string1=string1.substr(index+1,string1.length()-index);
               j++;
            }
            Node<pair<int,int>>* node=new Node<pair<int,int>>({i,j});
            //node->setStepCost(stoi(string1.substr(0,string1.find(","))));
            node->setStepCost(stoi(string1));
            this->nodesVector.push_back(node);
            i++;
            j=0;
        }
        if(target.find(",")!= string::npos) {
            i=stoi(target.substr(0,target.find(",")));
            j=stoi(target.substr(target.find(",")+1,target.length()-target.find(",")));
            Node<pair<int,int>>* node=getSomeNode({i,j});
            if(node== nullptr) {
                __throw_logic_error("no target/start for matrix");
            }
            this->target=node;
        }
        if(start.find(",")!= string::npos) {
            i=stoi(start.substr(0,start.find(",")));
            j=stoi(start.substr(start.find(",")+1,start.length()-start.find(",")));
            Node<pair<int,int>>* node=getSomeNode({i,j});
            if(node== nullptr) {
                __throw_logic_error("no target/start for matrix");
            }
            this->start=node;
        }

    }

    Node<pair<int,int>>* getGoalState() {
        return this->target;
    }

    Node<pair<int,int>>* getInitialState() {
        return this->start;
    }

    Node<pair<int,int>>* getSomeNode(pair<int,int> pair1) {
        for(Node<pair<int,int>>* node :this->nodesVector) {
            if(node->getNodeData()==pair1) {
                return node;
            }
        }
        return nullptr;
    }

    vector<Node<pair<int,int>>*> getAllPossibleStates(Node<pair<int,int>>* s) {
        vector<Node<pair<int,int>>*> vecOfNeighborsToRet;
        for(Node<pair<int,int>>* neighbor : this->nodesVector) {
            if(neighbor->getStepCost()== WALL ){
                continue;
            }
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
       stream<<"\n"<<this->start->getNodeData().first<<","<<this->start->getNodeData().second;
       stream<<"\n"<<this->target->getNodeData().first<<","<<this->target->getNodeData().second;
        return stream;
    }

    friend ostream &operator<<(ostream &ostream1, Matrix infinit1) {
        return infinit1 << (ostream1);
    }

   /* pair<int, int> bringANode(string string1,string delimeter) {
        if(string1.find(delimeter)!= string::npos) {
            part=string1.substr(0,string1.find(delimeter));
            splitted.push_back(part);
            string1=string1.substr(0,string1.find(delimeter));
        }
    }*/

};


#endif //PROJECTPART2_MATRIX_H
