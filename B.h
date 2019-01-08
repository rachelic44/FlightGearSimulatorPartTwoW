//
// Created by user on 06/01/19.
//

#ifndef PROJECTPART2_B_H
#define PROJECTPART2_B_H

#include <iostream>
using namespace std;

class B {

public:
    B() {

    }
    bool operator > (B b) {
        return false;
    }
    ostream &operator<<(ostream &stream) {
        cout<<"H";
    }

    friend ostream &operator<<(ostream &ostream1, B infinit1) {
        return infinit1 << (ostream1);
    }

};


#endif //PROJECTPART2_B_H
