#include <iostream>
#include "A.h"
#include "B.h"
#include <unordered_map>
#include <map>
#include <iostream>
#include "Node.h"
#include <vector>
#include "Graph.h"
#include <queue>
#include "BestFirstSearch.h"
#include "C.h"
#include "Matrix.h"

using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;

   /* Node<string>* a=new Node<string>("a");
    Node<string>* b=new Node<string>("b");

    a->setCameFrom(b);
    if(*a->getCameFrom()==(*b)) {
        cout<<"eq";
    }*/

    Node<string>* a=new Node<string>("a");
    Node<string>* b=new Node<string>("b");
    Node<string>* c=new Node<string>("c");
    Node<string>* d=new Node<string>("d");
    map<pair<Node<string>*,Node<string>*>,double > archMAp;
    archMAp.insert({{a,b},5});
    archMAp.insert({{a,c},3});
    archMAp.insert({{b,c},2});
    archMAp.insert({{c,d},6});
    vector<Node<string>*> vertexVector;
    vertexVector.push_back(a);
    vertexVector.push_back(b);
    vertexVector.push_back(c);
    vertexVector.push_back(d);
    Isearchable<string>* graph=new Graph<string> (vertexVector,archMAp);
    vector<Node<string>*> vecOfNeighbors=graph->getAllPossibleStates(b);
    cout<<"G";

    PriorityHeap<string> p;
    p.push(a);
    p.push(b);
   // p.remove(b);

    Node<int> t(6);
    cout<<t<<endl;
    cout<<p.size()<< " " <<p.top()->getNodeData()<<" ";
    p.pop();
    cout<<p.size()<< " " <<p.top()->getNodeData();
    p.pop();

    cout<< " " << p.size();






    cout<<endl;
    C<int> queue;

    queue.push(10);
    queue.push(2);
    queue.push(4);
    queue.push(6);
    queue.push(3);

    queue.remove(6);

    while (!queue.empty())
    {
        std::cout << queue.top();
        queue.pop();

        if (!queue.empty())
        {
            std::cout << ", ";
        }
    }

    vector<Node<pair<int,int>>*> vec;
    Node<pair<int,int>>* A = new Node<pair<int,int>>({0,0});
    A->setStepCost(0);
    vec.push_back(A);
    Node<pair<int,int>>* B = new Node<pair<int,int>>({0,1});
    B->setStepCost(1);
    vec.push_back(B);
    Node<pair<int,int>>* C = new Node<pair<int,int>>({1,0});
    C->setStepCost(2);
    vec.push_back(C);
    Node<pair<int,int>>* D = new Node<pair<int,int>>({1,1});
    D->setStepCost(3);
    vec.push_back(D);
    Matrix* m=new Matrix(vec,A,D);
   // BestFirstSearch bestFirstSearch;
    ISearcher< vector<Node<pair<int,int>>*>,pair<int,int>> *searcher= new BestFirstSearch<pair<int,int>>();
    searcher->search(m);
    int i=6;

    return 0;
}