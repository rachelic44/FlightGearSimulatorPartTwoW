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
    Graph graph(vertexVector,archMAp);
    vector<Node<string>*> vecOfNeighbors=graph.getAllPossibleStates(b);
    cout<<"G";


    Node<int> t(6);
    cout<<t;


    BestFirstSearch bestFirstSearch;


    return 0;
}