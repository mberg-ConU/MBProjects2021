// M. Bergeron
// E. Bouskila
// DGraph.cpp


#include "Dgraph.h"

// implementaion of D member functions

Person calling_vertex_D; // will be used in call_DGraph_display

DGraph::DGraph(int fr, int pe) : Graph(fr, pe)
{
    // nothing to initialize here
}

DGraph::DGraph(const DGraph& other) : Graph(other)
{
    // nothing to initialize here
}

DGraph::~DGraph()
{
	// Graph destructor handles memory cleanup
}

void DGraph::display()
{
    // call display function on every Person in the graph
    for(int k = 0; k < nbr_of_people; k++)
    {
        vector<bool>visited(nbr_of_people, false);
        call_DGraph_display(person_list[k], visited);

    }
}


void DGraph::display(Person& v, vector<bool>& visited)
{
    // create adjacency matrix
    static vector<vector<bool>> adj_mat;

    // initialize each element of adjacency matrix to false
    for(int i = 0; i < nbr_of_people; i++)
    {
        vector<bool>row;
        for(int j = 0; j < nbr_of_people; j++)
        {
            row.push_back(false); // initialize to false
        }
        adj_mat.push_back(row); // add vector row to adjacency matrix
    }

    int friend1index;
    int friend2index;

    // populate adjacency matrix with existing edges
    for(int j = 0; j < nbr_of_friendship; j++)
    {
        for(int i = 0; i < nbr_of_people; i++)
        {
            // find index of each object in each Friendship
            if(*(friendship_list[j].get_friend1()) == person_list[i])
            {
                friend1index = i;
            }
            if(*(friendship_list[j].get_friend2()) == person_list[i])
            {
                friend2index = i;
            }
        }
        adj_mat[friend1index][friend2index] = true; // add each edge to adjacency matrix (Directed, so we do not mark [friend2index][friend1index] as having an edge
    }

    if(v!= calling_vertex_D)
        cout << v.show();
    // show info of argument Person, not necessary if we are starting a new path (covered in below for loop)

    int vIndex;
    for(int m = 0; m < nbr_of_people; m++)
    {
        if(person_list[m] == v)
        {
            vIndex = m; // find index of argument object
        }
    }
    visited[vIndex] = true; // mark the index we are visiting as visited

    for(int t = 0; t < nbr_of_people; t++)
    {
        // find vertices that:
        // 1. is connected to argument vertex
        // 2. we have not already visited
        if(adj_mat[vIndex][t] == true && !visited[t])
        {
            if(calling_vertex_D == v) // if we are starting a new path, start a new line and print calling Person object's info
            {
                cout << endl;
                cout << v.show();
            }
            cout << "->";
            display(person_list[t], visited); // recursively call this function on the adjacent Person, to print the rest of the path
        }
    }
}


// the display(Vertex) function is recursive and so does not keep track of the starting Person
// thus, we use a "dummy" function call_UGraph_display() which will change the global variable so display function knows which is the starting Persojn object
void DGraph::call_DGraph_display(Person& v, vector<bool>& visited)
{
    calling_vertex_D = v;
    display(v, visited);
}


void DGraph::display(Friendship& e) // will print paths connected to Person objects in given Friendship
{

    for (int k = 0; k < nbr_of_friendship; k++)
    {
        if (*(e.get_friend1()) == *(friendship_list[k].get_friend1()) && *(e.get_friend2()) == *(friendship_list[k].get_friend2()) && e.get_years() == friendship_list[k].get_years())
        {
            // if Friendship object is found, print paths
            vector<bool>visited1(nbr_of_people, false);
            call_DGraph_display(*(friendship_list[k].get_friend1()), visited1);
            vector<bool>visited2(nbr_of_people, false);
            call_DGraph_display(*(friendship_list[k].get_friend2()), visited2);
        }
    }
}

bool DGraph::remove_friendship(Friendship& rem) // remove friendship from graph
{
    for (int p = 0; p < nbr_of_friendship; p++)
    {
       if(*(rem.get_friend1()) == *(friendship_list[p].get_friend1()) && *(rem.get_friend2()) == *(friendship_list[p].get_friend2()) && rem.get_years() == friendship_list[p].get_years())
        {
            for (int i = 0; i < nbr_of_friendship; i++)
            {
                friendship_list[i] = friendship_list[i + 1]; // shift array to delete Friendship
            }
            nbr_of_friendship--;
            return true;
        }
    }
    return false;
}

bool DGraph::removeEdges(Friendship* eArray, int size_)
{
    // use a for loop to call remove_friendship on every element of argument array
    for (int d = 0; d < size_; d++)
    {
        remove_friendship(eArray[d]);
    }
    return true;
}

void DGraph::showEdges() // show Edges for clarity
{
    cout << "Number of friendships in graph: " << nbr_of_friendship << endl;
    for (int i = 0; i < nbr_of_friendship; i++)
    {
        cout << friendship_list[i].get_friend1()->show() << "-" << friendship_list[i].get_years()<< "->" << friendship_list[i].get_friend2()->show() << endl;
    }

}


void DGraph::query_by_value(string to_find) // check if any Person in graph has a given value, output paths of that Person
{
    for(int k = 0; k < nbr_of_people; k++)
    {
        if(person_list[k].get_name() == to_find)
        {
            vector<bool>visited(nbr_of_people, false);
            call_DGraph_display(person_list[k], visited);
        }
    }
}
