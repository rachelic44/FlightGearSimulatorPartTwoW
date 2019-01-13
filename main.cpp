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
#include <fstream>
#include "MyParallelServer.h"

using namespace std;

#include "SearchSolver.h"

int main() {
  /* std::cout << "Hello, World!" << std::endl;

    vector<Node<pair<int,int>>*> vec;
    Node<pair<int,int>>* A1 = new Node<pair<int,int>>({0,0});
    A1->setStepCost(1);
    vec.push_back(A1);
    Node<pair<int,int>>* A2 = new Node<pair<int,int>>({0,1});
    A2->setStepCost(0);
    vec.push_back(A2);
    Node<pair<int,int>>* A3 = new Node<pair<int,int>>({0,2});
    A3->setStepCost(1);
    vec.push_back(A3);
    Node<pair<int,int>>* A4 = new Node<pair<int,int>>({0,3});
    A4->setStepCost(1);
    vec.push_back(A4);
    Node<pair<int,int>>* A5 = new Node<pair<int,int>>({0,4});
    A5->setStepCost(1);
    vec.push_back(A5);
    Node<pair<int,int>>* A11 = new Node<pair<int,int>>({1,0});
    A11->setStepCost(1);
    vec.push_back(A11);
    Node<pair<int,int>>* A21 = new Node<pair<int,int>>({1,1});
    A21->setStepCost(0);
    vec.push_back(A21);
    Node<pair<int,int>>* A31 = new Node<pair<int,int>>({1,2});
    A31->setStepCost(0);
    vec.push_back(A31);
    Node<pair<int,int>>* A41 = new Node<pair<int,int>>({1,3});
    A41->setStepCost(0);
    vec.push_back(A41);
    Node<pair<int,int>>* A51 = new Node<pair<int,int>>({1,4});
    A51->setStepCost(0);
    vec.push_back(A51);
    Node<pair<int,int>>* A12 = new Node<pair<int,int>>({2,0});
    A12->setStepCost(0);
    vec.push_back(A12);
    Node<pair<int,int>>* A22 = new Node<pair<int,int>>({2,1});
    A22->setStepCost(50);
    vec.push_back(A22);
    Node<pair<int,int>>* A32 = new Node<pair<int,int>>({2,2});
    A32->setStepCost(5);
    vec.push_back(A32);
    Node<pair<int,int>>* A42 = new Node<pair<int,int>>({2,3});
    A42->setStepCost(50);
    vec.push_back(A42);
    Node<pair<int,int>>* A52 = new Node<pair<int,int>>({2,4});
    A52->setStepCost(3);
    vec.push_back(A52);
    Node<pair<int,int>>* A13 = new Node<pair<int,int>>({3,0});
    A13->setStepCost(0);
    vec.push_back(A13);
    Node<pair<int,int>>* A23 = new Node<pair<int,int>>({3,1});
    A23->setStepCost(50);
    vec.push_back(A23);
    Node<pair<int,int>>* A33 = new Node<pair<int,int>>({3,2});
    A33->setStepCost(50);
    vec.push_back(A33);
    Node<pair<int,int>>* A43 = new Node<pair<int,int>>({3,3});
    A43->setStepCost(50);
    vec.push_back(A43);
    Node<pair<int,int>>* A53 = new Node<pair<int,int>>({3,4});
    A53->setStepCost(3);
    vec.push_back(A53);
    Node<pair<int,int>>* A14 = new Node<pair<int,int>>({4,0});
    A14->setStepCost(0);
    vec.push_back(A14);
    Node<pair<int,int>>* A24 = new Node<pair<int,int>>({4,1});
    A24->setStepCost(50);
    vec.push_back(A24);
    Node<pair<int,int>>* A34 = new Node<pair<int,int>>({4,2});
    A34->setStepCost(50);
    vec.push_back(A34);
    Node<pair<int,int>>* A44 = new Node<pair<int,int>>({4,3});
    A44->setStepCost(50);
    vec.push_back(A44);
    Node<pair<int,int>>* A54 = new Node<pair<int,int>>({4,4});
    A54->setStepCost(3);
    vec.push_back(A54);

    Isearchable<pair<int,int>> * mush=new Matrix(vec,A1,A54);
   // BestFirstSearch bestFirstSearch;
    ISearcher< vector<Node<pair<int ,int>>*>,pair<int,int>> *searcher= new BestFirstSearch<pair<int,int>>();
   // vector<Node<pair<int,int>>*> answer = searcher->search(m);

    Solver<Isearchable<pair<int,int>>*, vector<Node<pair<int,int>>*>> * solverSearcherTobeSolver =
            new SearchSolver< vector<Node<pair<int,int>>*>,pair<int,int>>(searcher);
    vector<Node<pair<int,int>>*> answer=solverSearcherTobeSolver->solve(mush);

     Matrix* mm=new Matrix(vec,A1,A54);
   // cout<<*mm;
    cout<< *(static_cast<Matrix*>(mush));
    Node<int>* np;
    int i=6;


    ifstream myfile ("files.txt");
    string line;
    string whole="";
    if(!myfile.is_open()) {
        myfile.open("files.txt",fstream::app | fstream::in);
    }
    if (myfile.is_open()) {

        A s("");
        myfile>>s;
        cout<<s;
        myfile.close();
    }*/



  MySerialServer mySerialServer;
  MyParallelServer myParallelServer;
  Solver<string,string> * solver=new ReverseSolver();
  cout<<"hello main"<<endl;
  sleep(1);
  ClientHandler* testClientHandler=new MyTestClientHandler(solver);
  myParallelServer.open(5400,testClientHandler);
  /*while(true) {
    cout<<"hello main"<<endl;
    sleep(1);
  }*/
  cout<<"hello main"<<endl;
//string s="123end2";
//cout<<s.substr(0,s.find("end"));

pthread_exit(nullptr);
   // return 0;
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