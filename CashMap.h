//
// Created by user on 13/01/19.
//

#ifndef PROJECTPART2_CASHMAP_H
#define PROJECTPART2_CASHMAP_H


#include <unordered_map>
#include <vector>
#define FILE_NAME "cash.txt"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class CashMap {

    static unordered_map<string, string>* theCashMap;
    static CashMap *map_instance;
public:
    static inline CashMap *instance() {
        if (map_instance == nullptr) {
            theCashMap=new unordered_map<string,string>();
            map_instance = new CashMap();
            ifstream myfile (FILE_NAME);
            string line;
            string whole="";
            string problem;
            string solution;
            int signInProblem=1;
            if(!myfile.is_open()) {
                myfile.open(FILE_NAME,fstream::app | fstream::in);
            }

            if (myfile.is_open())
            {
                while ( getline (myfile,line) )
                {

                    if(!(line=="$")) {
                        whole += line+"\n";
                    } else if(signInProblem) {
                        problem=whole;
                        whole="";
                        signInProblem=0;
                    } else {
                        solution=whole;
                        whole="";
                        signInProblem++;
                        map_instance->setValue(problem,solution);
                    }
                }
                myfile.close();
            } else {
                throw "Could not open file";
            }
        }
        return map_instance;
    }

    inline void setValue(string key, string val) {
       theCashMap->insert({key,val});
    }

    inline unordered_map<string, string>* getMap() {
        return theCashMap;
    }

   /* inline double getValue(const string &key) {
        return pathMap[key];
    }*/
   ~CashMap(){
      // cout<<"at cash map distructor";

       ofstream myfile;
     /*  if(!myfile.is_open()) {
           myfile.open(FILE_NAME,fstream::app | fstream::in);
       }*/
       myfile.open(FILE_NAME);


       for(auto p : *this->theCashMap) {
           if(p.second[p.second.length()-1]=='\n') {
               myfile << p.first << "$\n" << p.second << "$\n";
           } else {
               myfile << p.first << "$\n" << p.second << "\n$\n";
           }
       }
       myfile.close();
       /*
       if (myfile.is_open())
       {
           for(auto p : *this->theCashMap) {
               myfile<<p.first<<"\n$\n"<<p.second<<"\n$\n";
           }
           myfile.close();
       } else {
           throw "Could not open file";
       }*/
   }
};

#endif //PROJECTPART2_CASHMAP_H
