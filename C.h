//
// Created by user on 09/01/19.
//

#ifndef PROJECTPART2_C_H
#define PROJECTPART2_C_H

#include <iostream>
#include <queue>
using namespace std;

template<class InputIterator, class T>
InputIterator findS (InputIterator first, InputIterator last, const T& val)
{
    while (first!=last) {
        if (*first==val) return first;
        ++first;
    }
    return last;
}

template <class T>
struct greaterP : binary_function <T,T,bool> {
    bool operator() (const T& x, const T& y) const {return x<y;}
};

template<typename T>
class C : public std::priority_queue<T, std::vector<T>,greaterP<T>>
{
  public:

      bool remove( T value) {
        auto it = findS(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
       }
       else {
        return false;
       }
 }
};


#endif //PROJECTPART2_C_H
