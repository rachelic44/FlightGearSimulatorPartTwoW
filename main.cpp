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
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "ReverseSolver.h"

using namespace std;

#include "SearchSolver.h"

int main() {
  /*  std::cout << "Hello, World!" << std::endl;

    vector<Node<pair<int,int>>*> vec;
    Node<pair<int,int>>* A = new Node<pair<int,int>>({0,0});
    A->setStepCost(0);
    vec.push_back(A);
    Node<pair<int,int>>* B = new Node<pair<int,int>>({0,1});
    B->setStepCost(3);
    vec.push_back(B);
    Node<pair<int,int>>* C = new Node<pair<int,int>>({0,2});
    C->setStepCost(0);
    vec.push_back(C);
    Node<pair<int,int>>* D = new Node<pair<int,int>>({1,0});
    D->setStepCost(2);
    vec.push_back(D);
    Node<pair<int,int>>* E = new Node<pair<int,int>>({1,1});
    E->setStepCost(2);
    vec.push_back(E);
    Node<pair<int,int>>* F = new Node<pair<int,int>>({1,2});
    F->setStepCost(3);
    vec.push_back(F);
    Node<pair<int,int>>* G = new Node<pair<int,int>>({2,0});
    G->setStepCost(5);
    vec.push_back(G);
    Node<pair<int,int>>* H = new Node<pair<int,int>>({2,1});
    H->setStepCost(3);
    vec.push_back(H);
    Node<pair<int,int>>* I = new Node<pair<int,int>>({2,2});
    I->setStepCost(1);
    vec.push_back(I);
    Isearchable<pair<int,int>> * m=new Matrix(vec,A,I);
   // BestFirstSearch bestFirstSearch;
    ISearcher< vector<Node<pair<int ,int>>*>,pair<int,int>> *searcher= new BestFirstSearch<pair<int,int>>();
   // vector<Node<pair<int,int>>*> answer = searcher->search(m);

    Solver<Isearchable<pair<int,int>>*, vector<Node<pair<int,int>>*>> * solverSearcherTobeSolver =
            new SearchSolver< vector<Node<pair<int,int>>*>,pair<int,int>>(searcher);
    vector<Node<pair<int,int>>*> answer=solverSearcherTobeSolver->solve(m);


    Node<int>* np;
    int i=6;
*/

  MySerialServer mySerialServer;
  Solver<string,string> * solver=new ReverseSolver();

  ClientHandler* testClientHandler=new MyTestClientHandler(solver);
  mySerialServer.open(5400,testClientHandler);

    return 0;
}





/*
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    cout << argv[0] << endl;
    if (argc < 2)	{
        cout << "Usage: <prog> <port>" << endl;
        return 1;
    }
    int port = atoi(argv[1]);
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    if (bind(s, (sockaddr *)&serv, sizeof(serv)) < 0)	{
        cerr << "Bad!" << endl;
    }

    int new_sock;
    listen(s, 5);
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);

    timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    new_sock = accept(s, (struct sockaddr*)&client, &clilen);
    if (new_sock < 0)	{
        if (errno == EWOULDBLOCK || errno ==EAGAIN)	{
            cout << "timeout!" << endl;
            exit(2);
        }	else	{
            perror("other error");
            exit(3);
        }
    }
    cout << new_sock << endl;
    cout << s << endl;
    close(new_sock);
    close(s);
    return 0;
}
*/