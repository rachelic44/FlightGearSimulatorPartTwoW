//
// Created by user on 07/01/19.
//

#ifndef PROJECTPART2_ISEARCHABLE_H
#define PROJECTPART2_ISEARCHABLE_H
#include "Node.h"
#include <vector>

template <class T>
class Isearchable {
public:
    virtual Node<T>* getInitialState()=0;
    virtual Node<T>* getGoalState()=0;
    virtual std::vector<Node<T>*> getAllPossibleStates(Node<T>* s)=0;
 //   virtual ostream &operator<<(ostream &stream)=0;
   //  friend ostream &operator<<(ostream &ostream1, Isearchable<T>* infinit1) {}
};
#endif //PROJECTPART2_ISEARCHABLE_H
