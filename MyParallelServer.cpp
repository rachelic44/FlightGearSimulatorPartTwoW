//
// Created by user on 13/01/19.
//

#include <thread>
#include "MyParallelServer.h"
#define TIME_OUT -2
#include <mutex>

vector<int> vecThread;
vector<thread> vect;


void threadFunc(TCP_server tcp_server,TCP_client tcp_client,ClientHandler* clientHandler, mutex* mutex1) {
    clientHandler->handleClient(tcp_client,mutex1);
    //cout<< vecThread.back();
   // vecThread.pop_back();
}



void MyParallelServer::open(int portNumber, ClientHandler *clientHandler) {

    TCP_server server(portNumber);
    server.listen(SOMAXCONN);
    server.settimeout(0,0);
    TCP_client client=server.accept();
    server.settimeout(1,0);
    *(this->toStop)= false;
    mutex* mutex1=new mutex();


    while (!(*this->toStop)) {

        if (client.getSockNumber() == TIME_OUT) {
            cout << "atStop";
            *toStop=true;
            continue;
        }

        thread thread1(threadFunc,server,client,clientHandler,mutex1);
        vect.push_back(move(thread1));
       // thread1.detach();
        client = server.accept();
    }

    cout<<"calling stop"<<endl;
  stop(server.getSockNumber()); // todo ask michael
}

void MyParallelServer::stop(int serverNumber) {
    close(serverNumber);
    while(vect.size()>0) {
        vect.back().join();
        vect.pop_back();
    }
   // close(serverNumber);

}