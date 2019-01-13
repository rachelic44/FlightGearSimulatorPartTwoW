//
// Created by user on 06/01/19.
//

#ifndef PROJECTPART2_A_H
#define PROJECTPART2_A_H

#include <iostream>

using namespace std;


class A {
private:
    string string1;
public:
  /*  void func(P p1,P p2 ) {

        if(p1>p2) {
            std::cout<<"j";
        }
    }*/

  A(string s) {
      this->string1=s;
  }

     void operator>>(istream &s) {
      string string1;
     // if(s=="")
      s >> string1;
      A a(string1);
      *this = a;
  }

  friend void operator>>(istream &istream1, A &otherMatrix) {
      otherMatrix >> istream1;
  }

    ostream &operator<<(ostream &stream) {
        int i=0;
        stream<<this->string1;
        return stream;
    }

    friend ostream &operator<<(ostream &ostream1, A infinit1) {
        return infinit1 << (ostream1);
    }
};


#endif //PROJECTPART2_A_H
