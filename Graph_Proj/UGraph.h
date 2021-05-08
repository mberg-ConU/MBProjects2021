// M. Bergeron
// E. Bouskila
// UGraph.h

#ifndef UGRAPH_H
#define UGRAPH_H
#include <string>
#include "Graph.h"
#include <vector>

// definition of derived class UGraph

class UGraph : public Graph
{
private:
    virtual void display(Person&, vector<bool>&); // recursive private function used in the display functions
public:
    UGraph(int, int); // constructor
    UGraph(const UGraph&); // copy constructor
    virtual ~UGraph(); // destructor
    virtual void display(); // displays all paths of the graph
    virtual void display(Friendship&); // displays paths including Friendship
    bool remove_friendship(Friendship&); // remove Friendship from graph
    bool removeEdges(Friendship*, int); // calls remove_friendship on array of Friendship objects
    virtual void showEdges(); // shows Friendships for clarity
    virtual void query_by_value(string); // finds vertex with given value and prints paths
    virtual void call_UGraph_display(Person&, vector<bool>&); // dummy function required to call display method while keeping track of calling Person
};

#endif // UGRAPH_H
