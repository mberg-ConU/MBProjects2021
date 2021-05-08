// M. Bergeron
// E. Bouskila
// UGraph.cpp

#include "UGraph.h"

#include <vector>

// implementation of UGraph member functions

Person calling_vertex_U; // will be used in the call_UGraph_display function

UGraph::UGraph(int max_p, int max_f) : Graph(max_p, max_f)
{
    // no attributes to initialize here
}

UGraph::UGraph(const UGraph& other) : Graph(other)
{
    // no attributes to initialize here
}

UGraph::~UGraph()
{
    // Graph destructor handles memory cleanup
}


void UGraph::display()
{
    // call display function on every vertex in the graph
    for(int k = 0; k < nbr_of_people; k++)
    {
        vector<bool>visited(nbr_of_people, false);
        call_UGraph_display(person_list[k], visited);
    }
}


void UGraph::display(Person& v, vector<bool>& visited) // recursive function which displays the paths connected to argument Vertex
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
    // populate adjacency matrix with existing Friendships
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
        adj_mat[friend1index][friend2index] = true; // add each Friendship to adjacency matrix
        adj_mat[friend2index][friend1index] = true;
    }

    if(v!= calling_vertex_U)
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
        // 1. are connected to argument vertex
        // 2. we have not already visited
        if(adj_mat[vIndex][t] == true && !visited[t])
        {
            if(calling_vertex_U == v) // if we are starting a new path, start a new line and print calling Person object's info
            {
                cout << endl;
                cout << v.show();
            }
            cout << "--";
            display(person_list[t], visited); // recursively call this function on the adjacent Person, to print the rest of the path
        }
    }
}


// the display(Vertex) function is recursive and so does not keep track of the starting Person
// thus, we use a "dummy" function call_UGraph_display() which will change the global variable so display function knows which is the starting Persojn object
void UGraph::call_UGraph_display(Person& v, vector<bool>& visited)
{
    calling_vertex_U = v;
    display(v, visited);
}


void UGraph::display(Friendship& e) // will print paths connected to Person objects in the given Friendship
{
    bool found = false;
    for (int k = 0; k < nbr_of_friendship; k++) // find the necessary friendship
    {
        if (*(e.get_friend1())== *(friendship_list[k].get_friend1()) && *(e.get_friend2())== *(friendship_list[k].get_friend2()) && friendship_list[k].get_years() == e.get_years() ||
            (*(e.get_friend2()) == *(friendship_list[k].get_friend1()) && *(e.get_friend1()) == *(friendship_list[k].get_friend2())) &&  friendship_list[k].get_years() == e.get_years())
        {
            found = true;
            // if Friendship object is found, print paths of both Person objects
            vector<bool>visited1(nbr_of_people, false);
            call_UGraph_display(*(friendship_list[k].get_friend1()), visited1);
            cout << endl;
            vector<bool>visited2(nbr_of_people, false);
            call_UGraph_display(*(friendship_list[k].get_friend2()), visited2);
        }

    }
    if(!found)
    {
        cout << endl << "No Friendship found." << endl;
    }
}


bool UGraph::remove_friendship(Friendship& rem)
{
    for (int p = 0; p < nbr_of_friendship; p++) // check if argument friendship exists in graph
    {
        if ((*(rem.get_friend1()) == *(friendship_list[p].get_friend1()) && *(rem.get_friend2()) == *(friendship_list[p].get_friend2())) &&  friendship_list[p].get_years() == rem.get_years()||
            (*(rem.get_friend2()) == *(friendship_list[p].get_friend1()) && *(rem.get_friend1()) == *(friendship_list[p].get_friend2())) &&  friendship_list[p].get_years() == rem.get_years())
        {
            for (int i = p; i < nbr_of_friendship - 1; i++)
            {
                friendship_list[i] = friendship_list[i + 1]; // shift array to delete Friendship
            }
            nbr_of_friendship--;
            return true;
        }
    }
    return false;
}

bool UGraph::removeEdges(Friendship* eArray, int size_)
{
    // use a for loop and iterate over each element of argument array
    for (int d = 0; d < size_; d++)
    {
        remove_friendship(eArray[d]);
    }
    return true;
}


void UGraph::showEdges() // shows all Friendship objects for clarity
{
    cout << "Number of friendships in graph: " << nbr_of_friendship << endl;
    for (int i = 0; i < nbr_of_friendship; i++)
    {
        cout << friendship_list[i].get_friend1()->show() << "<-" << friendship_list[i].get_years() << "->" << friendship_list[i].get_friend2()->show() << endl;
    }
}


void UGraph::query_by_value(string to_find) // find Person object with given value/name, then print that Person's paths
{
    for(int k = 0; k < nbr_of_people; k++)
    {
        if(person_list[k].get_name() == to_find)
        {
            vector<bool>visited(nbr_of_people, false);
            call_UGraph_display(person_list[k], visited);
        }
    }
}
