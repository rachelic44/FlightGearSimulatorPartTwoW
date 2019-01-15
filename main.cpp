#include <iostream>
#include <unordered_map>
#include <map>
#include <iostream>
#include "Node.h"
#include <vector>
#include "Graph.h"
#include <queue>
#include "BestFirstSearch.h"
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
#include "Astar.h"

using namespace std;

CashMap *CashMap::map_instance = NULL;
unordered_map<string,string> *CashMap::theCashMap = NULL;

#include "SearchSolver.h"
#include "BFS.h"
#include "DFS.h"

int main(int args,char **argv) {


    MyParallelServer myParallelServer;
    CasheManager<string,string> *fileCasheManager = new FileCasheManager();

    ISearcher<string,pair<int,int>> *searcher = new Astar<pair<int,int>>();

    Solver<Isearchable<pair<int,int>> *,string> *solverSearcherTobeSolver =
            new SearchSolver<string,pair<int,int>>(searcher);

    ClientHandler *testClientHandler = new MyClientHandler<pair<int,int>>(solverSearcherTobeSolver,fileCasheManager);
    myParallelServer.open(stoi(argv[1]),testClientHandler);






   // pthread_exit(nullptr);
    return 0;
}



