cmake_minimum_required(VERSION 3.12)
project(projectPart2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(projectPart2 main.cpp MySerialServer.cpp MySerialServer.h Server.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CasheManager.h A.cpp A.h B.cpp B.h ReverseSolver.cpp ReverseSolver.h ISearcher.h Node.cpp Node.h ISearchable.h Graph.cpp Graph.h BestFirstSearch.cpp BestFirstSearch.h SearchSolver.cpp SearchSolver.h Searcher.h PriorityHeap.h C.h Matrix.cpp Matrix.h DFS.cpp DFS.h BFS.cpp BFS.h Astar.cpp Astar.h PosixSocket.cpp PosixSocket.h MyParallelServer.cpp MyParallelServer.h MyClientHandler.cpp MyClientHandler.h FileCasheManager.cpp FileCasheManager.h CashMap.h)