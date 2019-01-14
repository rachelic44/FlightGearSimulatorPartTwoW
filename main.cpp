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
#include "FileCasheManager.h"
#include "MyClientHandler.h"
#include <sstream>
#include "CasheManager.h"

using namespace std;

CashMap *CashMap::map_instance = NULL;
#include "SearchSolver.h"

int main() {
 /*

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


/*
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
 // cout<<"hello main"<<endl;
//string s="123end2";
//cout<<s.substr(0,s.find("end"));

/*
FileCasheManager fileCasheManager;
string queston ="hello";
cout<<fileCasheManager.getExistSolution(queston);

int a=stoi("       5\n \n");
cout<<a+3;
int i=0,j=0;
string start="5,63 \n";
i=stoi(start.substr(0,start.find(",")));
j=stoi(start.substr(start.find(",")+1,start.length()-start.find(",")));
cout<<" "<<i<<" "<<j;




    vector<string> vector1={"2,2,8,10,2",
                            "2,2,8,10,2",
                            "2,2,8,10,2",
                            "2,2,8,10,2",
                            "2,2,8,10,2"};
    Isearchable<pair<int,int>> * mush=new Matrix(vector1,"4,4","0,0");
    // BestFirstSearch bestFirstSearch;
    ISearcher< string, pair<int,int>> *searcher= new BestFirstSearch<pair<int,int>>();
    // vector<Node<pair<int,int>>*> answer = searcher->search(m);

    Solver<Isearchable<pair<int,int>>*, string> * solverSearcherTobeSolver =
            new SearchSolver< string,pair<int,int>>(searcher);
    string answer=solverSearcherTobeSolver->solve(mush);

    cout<<endl<<answer;

    stringstream stringstream1;
    stringstream1<<"G";
    string r=stringstream1.str();
    cout<<r;
    //*mush>>stringstream1;
   // cout<<*mush;
  */

    MyParallelServer myParallelServer;
    CasheManager<string,string>* fileCasheManager = new FileCasheManager() ;

    ISearcher< string,pair<int,int>> *searcher= new BestFirstSearch<pair<int,int>>();
    // vector<Node<pair<int,int>>*> answer = searcher->search(m);

    Solver<Isearchable<pair<int,int>>*, string> * solverSearcherTobeSolver =
            new SearchSolver<string,pair<int,int>>(searcher);


    cout<<"hello main"<<endl;
    sleep(1);

 //   MyClientHandler<string> *myClientHandler=new MyClientHandler<string>(solverSearcherTobeSolver,fileCasheManager);
    ClientHandler* testClientHandler=new MyClientHandler<pair<int,int>>(solverSearcherTobeSolver,fileCasheManager);
    myParallelServer.open(5400,testClientHandler);


    cout<<"hello main2"<<endl;
   delete CashMap::instance();
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