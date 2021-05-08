// M. Bergeron
// E. Bouskila
// DGraph.h

#ifndef DGRAPH_H
#define DGRAPH_H
#include <string>
#include "Graph.h"
#include <vector>

// definition of derived class DGraph

class DGraph : public Graph
{
private:
    virtual void display(Person&, vector<bool>&); // private recursive function used in display functions
public:
    DGraph(int, int); // constructor
    DGraph(const DGraph&); // copy constructor
    virtual ~DGraph(); // destructor
    virtual void display(); // displays all paths in the graph
    virtual void display(Friendship&); // display the paths that contain the Friendship
    bool remove_friendship(Friendship&); // remove Friendship from graph
    bool removeEdges(Friendship*, int); // remove multiple Friendships
    virtual void showEdges(); // display Friendships for clarity
    virtual void query_by_value(string); // print paths of Person with given value
    virtual void call_DGraph_display(Person&, vector<bool>&); // display paths of a Person
};

#endif // DGRAPH_H
