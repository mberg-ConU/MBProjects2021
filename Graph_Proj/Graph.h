// M. Bergeron
// E. Bouskila
// Graph.h


#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "Person.h"
#include "Friendship.h"

// definition of abstract class Graph

class Graph
{
protected:
	Person* person_list; // pointing to an array of Person objects
	Friendship* friendship_list; // pointing to an array of Friendships
	int max_friendships; // max Friendships in graph
	int max_people; // max People in graph
	// keep track of number of Person and Friendship objects
    int nbr_of_friendship;
    int nbr_of_people;
public:
	Graph(int, int); // constructor
	Graph(const Graph&); // copy constructor
	~Graph(); // default constructor
    virtual bool addVertex(Person&); // add a Person
    virtual bool addVertices(Person*, int); // add multiple Person objects
    virtual bool removeVertex(int); // remove a Person object
    virtual bool addEdge(Friendship&); // remove Friendship object
    virtual bool addEdges(Friendship*, int); // remove multiple Friendship objects
    virtual bool clean(); // clear graph
    virtual void showEdges() = 0; // pure virtual function, class is abstract
    void showVerts(); // show all verts for clarity
    int get_number_of_people() const; // simple getter
    virtual void query_by_value(string) = 0;// pure virtual function, class is abstract
    Person return_Person(string);
};

#endif // !GRAPH_H


