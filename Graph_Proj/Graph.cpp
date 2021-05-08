// M. Bergeron
// E. Bouskila
// Graph.cpp

#include "Graph.h"
#include <vector>

// implementaion of Graph member functions


Graph::Graph(int mf, int mp) // constructor
{
	max_friendships = mf;
	max_people = mp;
	nbr_of_friendship = 0;
	nbr_of_people = 0;
	friendship_list = new Friendship[max_friendships];
	person_list = new Person[max_people];
}

Graph::Graph(const Graph& _Graph) // copy constructor
{
	nbr_of_people = _Graph.nbr_of_people;
	max_people = _Graph.max_people;
	nbr_of_friendship = _Graph.nbr_of_friendship;
	max_friendships = _Graph.max_friendships;
	friendship_list = new Friendship[max_friendships];
	person_list = new Person[max_people];
	for (int i = 0; i < nbr_of_friendship; i++)
	{
		friendship_list[i] = _Graph.friendship_list[i]; // copying all objects in the array
	}
	for (int i = 0; i < nbr_of_people; i++)
	{
		person_list[i] = _Graph.person_list[i]; // copying all objects in the array
	}

}

Graph::~Graph() // destructor
{
    // clean up memory
	delete[] friendship_list;
	delete[] person_list;
}


bool Graph::addVertex(Person& v)
{
    // use exception handling to ensure there is space for the Vertex
    try
    {
        if (nbr_of_people < max_people)
        {
            // add Person objects to array
            person_list[nbr_of_people] = v;
            nbr_of_people++;
            return true;
        }
    else
    {
            throw "Vertex limit cannot be exceeded. Vertex not added."; // if there is not enough space, throw exception
    }
    }
    catch(const char* message)
    {
        cout << message << endl;
        return false;
    }


}

bool Graph::addVertices(Person* vArray, int arrSize)
{
    // use exception handling to ensure there is space for the Vertices
    try
    {
       if (nbr_of_people + arrSize < max_people)
    {
        for (int h = 0; h < arrSize; h++)
        {
            person_list[nbr_of_people + h] = vArray[h]; // add elements of array to Graph's person_list
        }
        nbr_of_people += arrSize;
        return true;
    }
    else
    {
        throw "\nVertex limit cannot be exceeded. Vertices not added."; // if there is not enough space, throw exception
    }
    }
    catch(const char* message)
    {
        cout << message << endl;
        return false;
    }

}

bool Graph::removeVertex(int index_rem) // remove Person object from graph
{
    if (index_rem >= nbr_of_people) // ensure the index is valid
    {
        cout << "Invalid index" << endl;
        return false;
    }

    // modify Person array
    for(int n = index_rem; n < nbr_of_people - 1; n++)
    {
        person_list[n] = person_list[n + 1]; // shift array
    }
    nbr_of_people--;

    // modify Friendship array
    // remove all Friendships with the Person object being removed
    for (int j = 0; j < nbr_of_friendship; j++)
    {
        Person first = *(friendship_list[j].get_friend1());
        Person second = *(friendship_list[j].get_friend2());
        if (person_list[index_rem] == first || person_list[index_rem] == second) // remove all Friendships including the argument Person objects
        {
            for (int i = j; i < nbr_of_friendship - 1; i++)
            {
                friendship_list[i] = friendship_list[i + 1];
            }
            nbr_of_friendship--;
        }
    }
    return true;
}


bool Graph::addEdge(Friendship& fr) // add edhe to array
{
    try
    {
        if (nbr_of_friendship < max_friendships)
        {
            bool found1 {false}, found2{false};
            for(int i = 0; i < nbr_of_people; i++) // ensure the two friends exist in the graph
            {
                if(person_list[i] == *(fr.get_friend1()))
                {
                    found1 = true;
                }
                if(person_list[i] == *(fr.get_friend1()))
                {
                    found2 = true;
                }
            }
            if(!found1 || !found2)
            {
                throw "One or more elements of friendship is not part of graph, cannot add friendship.";
            }
            friendship_list[nbr_of_friendship] = fr;
            nbr_of_friendship++;
            return true;
        }
        else
        {
            throw "Max edges cannot be exceeded. Edge not added."; // if there is not enough space, throw exception
        }
    }
    catch(const char* message)
    {
        cout << message << endl;
        return false;
    }
}


bool Graph::addEdges(Friendship* eArray, int size_) // add many Friendships to graph
{
    try
    {
        if ((nbr_of_friendship + size_) >= max_friendships)
    {
        throw "Max edges cannot be exceeded. Edges not added."; // throw exception if max size would be exceeded
    }
    else
    {
        for (int s = 0; s < size_; s++)
        {
            friendship_list[nbr_of_friendship + s] = eArray[s]; // add all necessary Friendships to graph
        }
        nbr_of_friendship += size_; // adjust number of friendships
        return true;
    }
    }
    catch(const char* message)
    {
        cout << message << endl;
        return false;
    }

}

bool Graph::clean() // remove all Friendships and Person objects from graph
{
    person_list = new Person[max_people];
    friendship_list = new Friendship[max_friendships];
    nbr_of_friendship = 0;
    nbr_of_people = 0;
    return true;
}


void Graph::showVerts()
{
    // simply prints all vertices for clarity
    cout << "Number of Person objects in graph: " << nbr_of_people << endl;
    for(int i = 0; i < nbr_of_people; i++)
    {
        cout << person_list[i].show() << endl;
    }
}

int Graph::get_number_of_people() const // simple getter
{
    return nbr_of_people;
}

Person Graph::return_Person(string name)
{
    for(int i = 0; i < nbr_of_people; i++)
    {
        if(person_list[i].get_name() == name)
            return person_list[i];
    }

    cout << "Person not found in graph. Empty Person will be returned." << endl;
    return Person();

}
