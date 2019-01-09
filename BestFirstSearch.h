//
// Created by user on 08/01/19.
//

#ifndef PROJECTPART2_BESTFIRSTSEARCH_H
#define PROJECTPART2_BESTFIRSTSEARCH_H


#include "ISearcher.h"
#include "Graph.h"
#include <list>
#include "Searcher.h"

class BestFirstSearch : public Searcher<list<Node<string> *>,string> {

    virtual list<Node<string>*> search(Isearchable<string>* isearchable);
};


#endif //PROJECTPART2_BESTFIRSTSEARCH_H
